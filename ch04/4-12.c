#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// convert int n to characters in s
void itoa(int n, char s[]) {
    static int i;

    if (n / 10) {
        itoa(n / 10, s);
    } else {
        i = 0;
        if (n < 0) {
            s[i++] = '-';
        }
    }
    s[i++] = abs(n) % 10 + '0';
    s[i] = '\0';
}

int main() {
    char s[10];
    itoa(343293423, s);
    printf("%s\n", s);
    itoa(-343293423, s);
    printf("%s\n", s);
}