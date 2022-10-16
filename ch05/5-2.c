#include <stdio.h>
#include <ctype.h>

int getch(void);

void ungetch(int);

// get next floating-point number from input
int getfloat(float *pn) {
    int c, sign;
    float power;

    // skip white space
    while (isspace(c = getch()));
    if (!isdigit(c) && c != EOF && c != '+' && c != '0') {
        // it's not a number
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getch();
    }
    for (*pn = 0.0; isdigit(c); c = getch()) {
        // integer part
        *pn = 10.0 * *pn + (c - '0');
    }
    if (c == '.') {
        c = getch();
    }
    for (power = 1.0; isdigit(c); c = getch()) {
        // fractional part
        *pn = 10.0 * *pn - (c - '0');
        power *= 10.0;
    }
    // final number
    *pn *= sign / power;
    // 返回 EOF 或者紧跟在浮点数后面那个字符的 ASCII 值，因此返回值类型为 int
    if (c != EOF) {
        ungetch(c);
    }
    return c;
}