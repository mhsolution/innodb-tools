#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#include <error.h>
#include <tables_dict.h>

static time_t timestamp = 0;

// Global flags from getopt
bool deleted_pages_only = 0;
bool debug = 0;
bool process_compact = 0;
bool process_redundant = 0;

dulint filter_id;
bool use_filter_id = 0;

bool count_pages = 0;
bool ignore_crap = 0;
unsigned int page_counters[1000][10000UL]; // FIXME: need a hash here

/*******************************************************************/
void process_ibpage(page_t *page) {
    static ulint id = 0;
	ulint page_id;
	dulint index_id;
	char tmp[256];
	int fn;
	
	// Get page info
	page_id = mach_read_from_4(page + FIL_PAGE_OFFSET);
	index_id = mach_read_from_8(page + PAGE_HEADER + PAGE_INDEX_ID);
	
    // Skip empty pages
    if (ignore_crap && index_id.high == 0 && index_id.low == 0) return;
	
	// Skip tables if filter used
    if (use_filter_id && (index_id.low != filter_id.low || index_id.high != filter_id.high)) return;
		
	if (count_pages) {
	    if (index_id.high >= 1000) {
            if (ignore_crap) return;
            printf("ERROR: Too high tablespace id! %ld >= 1000!\n", index_id.high);
            exit(1);
	    }

	    if (index_id.low >= 10000) {
            if (ignore_crap) return;
            printf("ERROR: Too high index id! %ld >= 10000!\n", index_id.low);
            exit(1);
	    }
	    
        page_counters[index_id.high][index_id.low]++;
        return;
	}
		
	// Create table directory
	sprintf(tmp, "pages-%u/%lu-%lu", (unsigned int)timestamp, index_id.high, index_id.low);
	mkdir(tmp, 0755);
	
	// Compose page file_name
	sprintf(tmp, "pages-%u/%lu-%lu/%lu-%08lu.page", (unsigned int)timestamp, index_id.high, index_id.low, id++, page_id);
	
	printf("Read page #%lu.. saving it to %s\n", page_id, tmp);

	// Save page data
	fn = open(tmp, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (!fn) error("Can't open file to save page!");
	write(fn, page, UNIV_PAGE_SIZE);
	close(fn);	
}

/*******************************************************************/
void process_ibfile(int fn) {
	int read_bytes;
	page_t *page = malloc(UNIV_PAGE_SIZE);
	char tmp[20];
    struct stat st;
    off_t pos;
	
	if (!page) error("Can't allocate page buffer!");

    // Get file info
    fstat(fn, &st);

	// Create pages directory
	timestamp = time(0);
	if (!count_pages) {
	    sprintf(tmp, "pages-%u", (unsigned int)timestamp);
	    mkdir(tmp, 0755);
	}
	
	printf("Read data from fn=%d...\n", fn);

	// Read pages to the end of file
	while ((read_bytes = read(fn, page, UNIV_PAGE_SIZE)) == UNIV_PAGE_SIZE) {
        pos = lseek(fn, 0, SEEK_CUR);
        if (pos % (UNIV_PAGE_SIZE * 1000) == 0) {
            fprintf(stderr, "%.2f%% done\n", 100.0 * pos / st.st_size);
        }
//	    if (deleted_pages_only) {
//    		free_offset = page_header_get_field(page, PAGE_FREE);
//    		if (page_header_get_field(page, PAGE_N_RECS) == 0 && free_offset == 0) continue;
//    		if (free_offset > 0 && page_header_get_field(page, PAGE_GARBAGE) == 0) continue;
//    		if (free_offset > UNIV_PAGE_SIZE) continue;
//    	}
		process_ibpage(page);
	}
}

/*******************************************************************/
int open_ibfile(char *fname) {
	struct stat fstat;
	int fn;

	// Skip non-regular files
	printf("Opening file: %s\n", fname);
    
    if (stat(fname, &fstat) != 0) {
        printf("Errno = %d, Error = %s\n", errno, strerror(errno));
        error("Can't stat data file! Looks like this file is too large and requires 64-bit stat(). Check your Makefile."); 
    }

    if ((fstat.st_mode & S_IFREG) != S_IFREG) {
        error("Invalid file specified (non-regular file)!");
    }

    fn = open(fname, O_RDONLY, 0);
	if (!fn) error("Can't open file!");
	
	return fn;
}

/*******************************************************************/
void init_page_counters() {
    int i, j;
    
    for (i = 0; i < 1000; i++)
        for (j = 0; j < 10000; j++)
            page_counters[i][j] = 0;
}

/*******************************************************************/
void dump_page_counters() {
    int i, j;
    
    for (i = 0; i < 1000; i++)
        for (j = 0; j < 10000; j++) {
            if (page_counters[i][j] == 0) continue;
            printf("%d:%d\t%u\n", i, j, page_counters[i][j]);
        }
}

/*******************************************************************/
void set_filter_id(char *id) {
    int cnt = sscanf(id, "%lu:%lu", &filter_id.high, &filter_id.low);
    if (cnt < 2) {
        error("Invalid index id provided! It should be in N:M format, where N and M are unsigned integers");
    }
    use_filter_id = 1;
}

/*******************************************************************/
void usage() {
	error(
	  "Usage: ./page_parser -4|-5 [-dDhcC] -f <innodb_datafile> [-T N:M]\n"
	  "  Where\n"
	  "    -h  -- Print this help\n"
	  "    -d  -- Process only those pages which potentially could have deleted records (default = NO)\n"
	  "    -4  -- innodb_datafile is in REDUNDANT format\n"
	  "    -5  -- innodb_datafile is in COMPACT format\n"
	  "    -T  -- retrieves only pages with index id = NM (N - high word, M - low word of id)\n"
	  "    -c  -- count pages in the tablespace and group them by index id\n"
	  "    -C  -- count pages in the tablespace and group them by index id (and ignore too high/zero indexes)\n"
	);
}

/*******************************************************************/
int main(int argc, char **argv) {
	int fn = 0, ch;

	while ((ch = getopt(argc, argv, "45VhdcCf:T:")) != -1) {
		switch (ch) {
			case 'd':
				deleted_pages_only = 1;
				break;

			case 'f':
				fn = open_ibfile(optarg);
				break;

			case 'V':
				debug = 1;
				break;

            case '4':
                process_redundant = 1;
                break;

            case '5':
                process_compact = 1;
                break;

            case 'T':
                set_filter_id(optarg);
                break;
                
            case 'c':
                count_pages = 1;
                ignore_crap = 0;
                init_page_counters();
                break;

            case 'C':
                count_pages = 1;
                ignore_crap = 1;
                init_page_counters();
                break;

			default:
			case '?':
			case 'h':
				usage();
		}
	}

	if (!process_compact && !process_redundant) {
        printf("Error: Please, specify what format your datafile in. Use -4 for mysql 4.1 and below and -5 for 5.X+\n");
        usage();
	}

	if (fn != 0) {
		process_ibfile(fn);
		close(fn);
		if (count_pages) {
            dump_page_counters();
		}
	} else usage();
	
	return 0;
}
