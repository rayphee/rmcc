#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

void print_char(unsigned char c);

void print_char(unsigned char c){
    char cout;
    switch(c){
        case '\a':
            cout = 'a';
            break;
        case '\b':
            cout = 'b';
            break;
        case '\f':
            cout = 'f';
            break;
        case '\n':
            cout = 'n';
            break;
        case '\r':
            cout = 'r';
            break;
        case '\t':
            cout = 't';
            break;
        case '\v':
            cout = 'v';
            break;
        case '\\':
            cout = '\\';
            break;
        case '\'':
            cout = '\'';
            break;
        case '"':
            cout = '"';
            break;
        default:
	    if((c>0x7E) || (c<0x20)){
		fprintf(stdout, "\\%o", c);
		return;
	    }
            fprintf(stdout, "%c", c);
            return;
    }
    fprintf(stdout, "\\%c", cout);
}
