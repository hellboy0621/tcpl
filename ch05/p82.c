#include <ctype.h>
#include <stdio.h>

int getch(void);

void ungetch(int);

// 将输入中的下一个整数型赋值给 *pn
int getint(int *pn) {
    int c, sign;

    // 跳过空白符
    while (isspace(c = getch()));
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        // 输入不是一个数字
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getch();
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