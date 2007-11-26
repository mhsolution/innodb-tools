# Uncomment to build static binaries
#CFLAGS=-static

INCLUDES=-I include -I mysql-source/include -I mysql-source/innobase/include

all: constraints_parser page_parser

# LIBS

lib: 
	mkdir lib

lib/print_data.o: lib print_data.c include/print_data.h include/tables_dict.h
	gcc $(CFLAGS) -g $(INCLUDES) -c print_data.c -o lib/print_data.o

lib/check_data.o: lib check_data.c include/check_data.h include/tables_dict.h
	gcc $(CFLAGS) -g $(INCLUDES) -c check_data.c -o lib/check_data.o

lib/tables_dict.o: lib tables_dict.c include/tables_dict.h include/table_defs.h mysql-source/include/my_config.h
	gcc $(CFLAGS) -g $(INCLUDES) -c tables_dict.c -o lib/tables_dict.o

# BINARIES

page_parser: page_parser.c include/error.h lib/tables_dict.o lib/libut.a
	gcc $(CFLAGS) -g $(INCLUDES) -o page_parser page_parser.c lib/tables_dict.o lib/libut.a

constraints_parser: constraints_parser.c include/error.h lib/tables_dict.o lib/print_data.o lib/check_data.o lib/libut.a
	gcc $(CFLAGS) -g $(INCLUDES) -o constraints_parser constraints_parser.c lib/tables_dict.o lib/print_data.o lib/check_data.o lib/libut.a

# DEPENDENCIES FROM MYSQL

mysql-source/config.h:
	cd mysql-source && ./configure --without-docs --without-man --without-bench --without-extra-tools

mysql-source/include/my_config.h: mysql-source/config.h
	cd mysql-source/include && $(MAKE) my_config.h

lib/libut.a: mysql-source/include/my_config.h
	cd mysql-source/innobase/ut && $(MAKE) libut.a
	ln -fs ../mysql-source/innobase/ut/libut.a lib/libut.a

# CLEAN

dist:
	mkdir -p innodb_recovery
	cp page_parser constraints_parser innodb_recovery/
	tar czf innodb_recovery.tar.gz innodb_recovery
	rm -rf innodb_recovery
    
clean: 
	rm -f page_parser constraints_parser
	rm -rf lib constraints_parser.dSYM page_parser.dSYM

distclean: clean
	rm -rf innodb_recovery
	rm -f innodb_recovery.tar.gz
	cd mysql-source && (test -f Makefile && $(MAKE) -i distclean) || true
	rm -f mysql-source/Docs/Makefile mysql-source/man/Makefile mysql-source/sql-bench/Makefile
