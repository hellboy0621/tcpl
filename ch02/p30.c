#include <stdio.h>

int strlen(const char s[]);

int main() {
    setbuf(stdout, NULL);

    // 一旦对 字符数组 初始化了，其余的都是 \0
    char s[10] = "abc";
    printf("%s\n", s);

    // 这里使用 for 循环赋值，没有对 字符数组 初始化！
//    for (int i = 0; i < 5; ++i) {
//        s[i] = 'a';
//    }

    int length = strlen(s);
    printf("The length is %d.\n", length);
}

int strlen(const char s[]) {
    int i;

    i = 0;
    while (s[i] != '\0') {
        ++i;
    }
    return i;
}