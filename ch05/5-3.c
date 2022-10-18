#include <stdio.h>

// concatenate t to the end of s
// pointer version
void strcat(char *s, char *t) {
    while (*s) {
        s++;
    }
    while (*s++ = *t++);
}

void strcpy3(char *s, char *t) {
    while (*s++ = *t++);
}

int main() {
    char s[50];
    char t[50];
    strcpy3(s, "This is the source.");
    strcpy3(t, "This is the destination.");
    strcat(s, t);
    printf("s = %s, t = %s\n", s, t);
}