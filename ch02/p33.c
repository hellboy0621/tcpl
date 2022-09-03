#include <stdio.h>

enum loop {
    NO, YES
};
enum loop okLoop = YES;

int main() {
    // 原 for 循环
    int i, lim = 5;
    char c;
    char s[10];

    for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i) {
        s[i] = c;
    }

    // 不使用 && 与 || 等价的循环语句

    i = 0;
    while (okLoop == YES) {
        if (i >= lim - 1) {
            okLoop = NO;
        } else if ((c = getchar()) == '\n') {
            okLoop = NO;
        } else if (c == EOF) {
            okLoop = NO;
        } else {
            s[i] = c;
            ++i;
        }
    }
}
