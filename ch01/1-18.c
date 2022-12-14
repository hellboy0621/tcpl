#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
int remove1(char s[]);

int main() {
    char line[MAXLINE];

    while (getline(line, MAXLINE) > 0) {
        if (remove1(line) > 0) {
            printf("%s", line);
        }
    }

    return 0;
}

int remove1(char s[]) {
    int i;

    i = 0;
    while (s[i] != '\n') {
        ++i;
    }
    --i;
    while (i >= 0 && (s[i] == ' ' || s[i] == '\t')) {
        --i;
    }
    // is it a non-blank line?
    if (i >= 0) {
        ++i;
        // put new line character back
        s[i] = '\n';
        ++i;
        // terminate the string
        s[i] = '\0';
    }
    return i;
}

int getline(char s[], int lim) {
    int c, i, j;

    j = 0;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i < lim - 2) {
            s[j] = c;
            ++j;
        }
    }
    if (c == '\n') {
        s[j] = c;
        ++j;
        ++i;
    }
    s[j] = '\0';
    return i;
}