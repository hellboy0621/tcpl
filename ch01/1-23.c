#include <stdio.h>

void rcomment(int c);
void in_comment(void);
void echo_quote(int c);

// remove all comments from a valid C program
/**
 *
 * @return
 */
int main() {
    int c, d;

    while ((c = getchar()) != EOF) {
        rcomment(c);
    }

    return 0;
}

// read each character, remove the comments
void rcomment(int c) {
    int d;

    if (c == '/') {
        if ((d = getchar()) == '*') {
            // beginning comment
            in_comment();
        } else if (d == '/') {
            // another slash
            putchar(c);
            rcomment(d);
        } else {
            // not a comment
            putchar(c);
            putchar(d);
        }
    } else if (c == '\'' || c == '"') {
        // quote begins
        echo_quote(c);
    } else {
        // not a comment
        putchar(c);
    }
}

// inside a valid comment
void in_comment(void) {
    int c, d;

    c = getchar();
    d = getchar();
    while (c != '*' || d != '/') {
        c = d;
        d = getchar();
    }
}

// echo characters within quotes
void echo_quote(int c) {
    int d;

    putchar(c);
    while ((d = getchar()) != c) {
        putchar(d);
        if (d == '\\') {
            putchar(getchar());
        }
        putchar(d);
    }
}
