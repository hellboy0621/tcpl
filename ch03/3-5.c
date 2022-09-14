#include <stdio.h>

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

// itob: convert n to characters in s - base b
void itob(int n, char s[], int b) {
    int i, j, sign;
//    void reverse(char s[]);

    if ((sign = n) < 0) {
        n = -n;
    }
    i = 0;
    do {
        j = n % b;
        s[i++] = (j <= 9) ? j + '0' : j + 'A' - 10;
    } while ((n /= b) > 0);
    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

int main() {
    char s[10];
    itob(329385329, s, 16);
    printf("%s\n", s);
    return 0;
}