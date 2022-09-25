#include <stdio.h>
#include <math.h>

// max size of operand or operator
#define MAXOP 100
// signal that a number was found
#define NUMBER '0'

int getop(char[]);

void push(double);

double pop(void);

// reverse Polish calculator
int main() {
    setbuf(stdout, NULL);

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
                if (op2 != 0.0) {
                    push(pop() / op2);
                } else {
                    printf("error: zero divisor\n");
                }
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push(fmod(pop(), op2));
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

#include <string.h>
#include <ctype.h>

int getch(void);

void ungetch(int);

// get next operator or numeric operand
int getop(char s[]) {
    int c, i;

    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    i = 0;
    if (!isdigit(c) && c != '.' && c != '-') {
        // not a number
        return c;
    }
    if (c == '-') {
        // 就因为多了一个 = 号，让本来的赋值操作变成了比较操作！
        // if (isdigit(c == getch()) || c == '.') {
        if (isdigit(c = getch()) || c == '.') {
            // negative number
            s[++i] = c;
        } else {
            // minus sign
            if (c != EOF) {
                ungetch(c);
            }
            return '-';
        }
    }
    if (isdigit(c)) {
        //  collect integer part
        while (isdigit(s[++i] = c = getch()));
    }
    if (c == '.') {
        // collect fraction part
        while (isdigit(s[++i] = c = getch()));
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

