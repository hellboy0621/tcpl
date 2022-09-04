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

// 将字符串 s 转换为响应的整型数
int atoi(char s[]) {
    int i, n;

    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i) {
        n = 10 * n + (s[i] - '0');
    }
    return n;
}

// 把字符 c 转换为小写形式；只对 ASCII 字符集有效
int lower(int c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 'a' - 'A';
    }
    return c;
}
