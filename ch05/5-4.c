#include <stdio.h>

// return 1 if string t occurs at the end of s
int strend(char *s, char *t) {
    // remember the beginning of strs
    char *bs = s;
    char *bt = t;

    // end of the string s
    for (; *s; s++);
    // end of the string t
    for (; *t; t++);

    for (; *t == *s; s--, t--) {
        // at the beginning of a string
        if (t == bt || s == bs) {
            break;
        }
    }
    if (*t == *s && t == bt && *s != '\0') {
        return 1;
    } else {
        return 0;
    }
}

void strcpy3(char *s, char *t) {
    while ((*s++ = *t++));
}

int main() {
    char s[50];
    char t[50];
    strcpy3(s, "This is the source.");
    strcpy3(t, "source.");
    printf("res = %d\n", strend(s, t));
}