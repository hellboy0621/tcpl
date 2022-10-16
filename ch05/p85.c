#include <stdio.h>

// 返回字符串 s 的长度
int strlen(char *s) {
    int n;
    for (n = 0; *s != '\0'; s++) {
        n++;
    }
    return n;
}

int main() {
    printf("%d\n", strlen("hello, world"));
    char array[100];
    array[0] = 'h';
    array[1] = 'e';
    array[2] = 'l';
    array[3] = 'l';
    array[4] = '\0';
    printf("%d\n", strlen(array));
}