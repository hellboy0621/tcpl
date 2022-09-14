#include <stdio.h>

#define abs(x) ((x) < 0 ? -(x) : (x))

void reverse(char s[]) {
    int i, j;
    char temp;

    i = 0;
    while (s[i] != '\0') {
        ++i;
    }
    --i;
    if (s[i] == '\n') {
        --i;
    }
    j = 0;
    while (j < i) {
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
        --i;
        ++j;
    }
}

// itoa: convert n to characters in s - modified
void itoa(int n, char s[]) {
    int i, sign;
//    void reverse(char s[]);

    // record sign
    sign = n;
    i = 0;
    do {
        // generate digits in reverse order
        // get next digit
        s[i++] = abs(n % 10) + '0';
        // delete it
    } while ((n /= 10) != 0);
    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

int main() {
    int n = -832983924;
    char s[10];
    itoa(n, s);
    printf("%s\n", s);
    return 0;
}

