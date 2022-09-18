#define abs(x) ((x) < 0 ? -(x): (x))

// convert n to characters in s, w characters wide
void itoa(int n, char s[], int w) {
    int i, sign;
    void reverse(char s[]);

    // record sign
    sign = n;
    i = 0;
    // generate digits in reverse order
    do {
        // get  next digit
        s[i++] = abs(n % 10) + '0';
    } while ((n /= 10) != 0);
    if (sign < 0) {
        s[i++] = '-';
    }
    // pad with blanks
    while (i < w) {
        s[i++] = ' ';
    }
    s[i] = '\0';
    reverse(s);
}