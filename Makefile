# Uncomment to build static binaries
#CFLAGS=-static

INCLUDES=-I mysql-source/include -I mysql-source/innobase/include

all: constraints_parser page_parser

print_data.o: print_data.h tables_dict.h
	gcc $(CFLAGS) -g $(INCLUDES) -c print_data.c

check_data.o: check_data.h tables_dict.h
	gcc $(CFLAGS) -g $(INCLUDES) -c check_data.c

tables_dict.o: tables_dict.h tables_dict.c table_defs.h mysql-source/include/my_config.h
	gcc $(CFLAGS) -g $(INCLUDES) -c tables_dict.c

# BINARIES

page_parser: page_parser.c error.h tables_dict.o libut.a
	gcc $(CFLAGS) -g $(INCLUDES) -o page_parser page_parser.c tables_dict.o libut.a

constraints_parser: constraints_parser.c error.h tables_dict.o print_data.o check_data.o libut.a
	gcc $(CFLAGS) -g $(INCLUDES) -o constraints_parser constraints_parser.c tables_dict.o print_data.o check_data.o libut.a

# DEPENDENCIES FROM MYSQL

mysql-source/config.h:
	cd mysql-source && ./configure --without-docs --without-man --without-bench --without-extra-tools

mysql-source/include/my_config.h: mysql-source/config.h
	cd mysql-source/include && make my_config.h

libut.a: mysql-source/include/my_config.h
	cd mysql-source/innobase/ut && make libut.a
	ln -fs mysql-source/innobase/ut/libut.a

dist:
	mkdir -p innodb_recovery
	cp page_parser constraints_parser innodb_recovery/
	tar czf innodb_recovery.tar.gz innodb_recovery
	rm -rf innodb_recovery
    
clean: 
	rm -f page_parser constraints_parser *.o
	rm -rf constraints_parser.dSYM page_parser.dSYM

distclean: clean
	rm -rf innodb_recovery
	rm -f innodb_recovery.tar.gz
	rm -f libut.a
	cd mysql-source && make distclean
