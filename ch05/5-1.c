#include <stdio.h>
#include <ctype.h>

int getch(void);

void ungetch(int);

// get next integer from input into *pn
int getint(int *pn) {
    int c, d, sign;

    // skip white space
    while (isspace(c = getch()));
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        // it's not a number
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        // remeber sign char
        d = c;
        if (!isdigit(c = getch())) {
            if (c != EOF) {
                // push back non-digit
                ungetch(c);
            }
            // push back sign char
            ungetch(d);
            // return sign char
            return d;
        }
    }
    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;
    if (c != EOF) {
        ungetch(c);
    }
    return c;
}