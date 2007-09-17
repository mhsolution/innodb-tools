all: page_parser records_parser

page_parser: page_parser.c error.h common.h
	gcc -g -I innodb_includes -I mysql_includes -o page_parser page_parser.c libut.a

records_parser: records_parser.c error.h common.h
	gcc -g -I innodb_includes -I mysql_includes -o records_parser records_parser.c libut.a

clean: 
	rm -f page_parser records_parser
