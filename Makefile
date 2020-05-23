CFLAGS=-I includes -fms-extensions
# CC=/usr/local/bin/gcc-8 
CC=gcc

src/lex.yy.c: src/lexer.l
	lex -o $@ $^

src/y.tab.c: src/parser.y
	yacc -d -v -o $@ $^

lexertester: tests/lexertester.c tests/common.c src/lex.yy.c
	touch src/y.tab.h
	$(CC) $(CFLAGS) -ll $^ -o $@
	rm src/y.tab.h

exprtester: tests/exprtester.c tests/common.c
	lex -o src/lex.yy.c src/lexer.l
	yacc -d -v -o src/y.tab.c src/expr_parser.y
	$(CC) $(CFLAGS) $^ src/y.tab.c src/lex.yy.c -o $@

symtester: tests/symtester.c tests/common.c src/symtab.c src/lex.yy.c src/y.tab.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f *.o lexertester exprtester symtester src/lex.yy.c src/y.tab.* src/y.output
