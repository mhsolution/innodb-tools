all: page_parser records_parser heuristic_parser

page_parser: page_parser.c error.h common.h
	gcc -g -I innodb_includes -I mysql_includes -o page_parser page_parser.c libut.a

records_parser: records_parser.c error.h common.h
	gcc -g -I innodb_includes -I mysql_includes -o records_parser records_parser.c libut.a

heuristic_parser: heuristic_parser.c error.h common.h table_defs.h
	gcc -g -I innodb_includes -I mysql_includes -o heuristic_parser heuristic_parser.c libut.a

clean: 
	rm -f page_parser records_parser heuristic_parser
