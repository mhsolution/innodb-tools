# Uncomment to build static binaries
#CFLAGS=-static

all: page_parser records_parser heuristic_parser

page_parser: page_parser.c error.h common.h common.c
	gcc $(CFLAGS) -g -I innodb_includes -I mysql_includes -o page_parser page_parser.c common.c libut.a

records_parser: records_parser.c error.h common.h common.c
	gcc $(CFLAGS) -g -I innodb_includes -I mysql_includes -o records_parser records_parser.c common.c libut.a

heuristic_parser: heuristic_parser.c error.h common.h table_defs.h common.c
	gcc $(CFLAGS) -g -I innodb_includes -I mysql_includes -o heuristic_parser heuristic_parser.c common.c libut.a

constraints_parser: constraints_parser.c error.h common.h table_defs.h common.c
	gcc $(CFLAGS) -g -I innodb_includes -I mysql_includes -o constraints_parser constraints_parser.c common.c libut.a


dist:
	mkdir -p innodb_recovery
	cp page_parser records_parser heuristic_parser innodb_recovery/
	tar czf innodb_recovery.tar.gz innodb_recovery
	rm -rf innodb_recovery
    
clean: 
	rm -f page_parser records_parser heuristic_parser

distclean: clean
	rm -rf innodb_recovery
	rm -f innodb_recovery.tar.gz
