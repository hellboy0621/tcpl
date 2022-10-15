#include <string.h>
#include <stdio.h>

// reverse string s in place
void reverse(char s[]) {
    void reverser(char s[], int i, int len);

    reverser(s, 0, strlen(s));
}

// reverse string s in place, recursive
void reverser(char s[], int i, int len) {
    int j = len - (i + 1);
    if (i < j) {
        int tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        reverser(s, ++i, len);
    }
}

int main() {
    char s[] = "abcdef";
    reverse(s);
    printf("%s\n", s);
    char s2[] = "abcdefg";
    reverse(s2);
    printf("%s\n", s2);
}