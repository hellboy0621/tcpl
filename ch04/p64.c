#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);

void push(double);

double pop(void);

// 1 2 - 4 5 + *
// -9
// 逆波兰计算器
int main() {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

// ****************

// 栈 val 的最大深度
#define MAXVAL 100

// 下一个空闲栈位置
int sp = 0;
// 值栈
double val[MAXVAL];

// 把 f 压入值栈中
void push(double f) {
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("error: stack full, can't push %g\n", f);
    }
}

// 弹出并返回栈顶的值
double pop(void) {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

// ****************

#include <ctype.h>

int getch(void);

void ungetch(int);

int getop(char s[]) {
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    if (!isdigit(c) && c != '.') {
        // 不是数
        return c;
    }
    i = 0;
    if (isdigit(c)) {
        // 收集整数部分
        while (isdigit(s[++i] = c = getch()));
    }
    if (c == '.') {
        // 收集小数部分
        while (isdigit(s[++i] = c = getch));
    }
    s[i] = '\0';
    if (c != EOF) {
        ungetch(c);
    }
    return NUMBER;
}

// ****************

#define BUFSIZE 100

// 用于 ungetch 函数的缓冲区
char buf[BUFSIZE];

// buf 中下一个空闲位置
int bufp = 0;

// 取一个字符（可能是压回的字符）
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

// 把字符压回到输入中
void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
