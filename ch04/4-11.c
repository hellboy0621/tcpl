#include <ctype.h>
#include <stdio.h>

// signal that a number was found
#define NUMBER '0'

int getch(void);

// get next operator or numeric operand
int getop(char s[]) {
    int c, i;
    static int lastc = 0;

    if (lastc == 0) {
        c = getch();
    } else {
        c = lastc;
        lastc = 0;
    }
    while ((s[0] = c) == ' ' || c == '\t') {
        c = getch();
    }
    s[1] = '\0';
    if (!isdigit(c) && c != '.') {
        // not a number
        return c;
    }
    i = 0;
    if (isdigit(c)) {
        // collect integer part
        while (isdigit(s[++i] = c = getch())) {
        }
    }
    if (c == '.') {
        // collect fraction part
        while (isdigit(s[++i] = c = getch())) {
        }
    }
    s[i] = '\0';
    if (c != EOF) {
        lastc = c;
    }
    return NUMBER;
}