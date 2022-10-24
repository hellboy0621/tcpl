#include <stdio.h>
#include <ctype.h>
#include <string.h>

// read a lint into s, return length
int getline2(char *s, int lim) {
    char c;
    char *t = s;

    while (--lim > 0 && (c = getchar() != EOF) && c != '\n') {
        *s++ = c;
    }
    if (c == '\n') {
        *s++ = c;
    }
    *s = '\0';
    return s - t;
}

// convert s to integer, pointer version
int atoi(char *s) {
    int sign, n;
    // skip white space
    while (isspace(*s++));

    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-') {
        s++;
    }
    for (n = 0; isdigit(*s); s++) {
        n = 10 * n + (*s - '0');
    }
    return n * sign;
}

void reverse(char *s);

// convert n to characters in s, pointer version
void itoa(int n, char *s) {
    // save pointer to s
    char *t = s;
    int sign;

    // record sign
    if ((sign = n) < 0) {
        // make n positive
        n = -n;
    }
    do {
        // generate digits in revers order
        // get next digit
        *s++ = n % 10 + '0';
        // delete it
    } while ((n /= 10) > 0);

    if (sign < 0) {
        *s++ = '-';
    }
    *s = '\0';
    reverse(t);
}

// reverse string s in place
void reverse(char *s) {
    char c;
    char *t;
    for (t = s + (strlen(s) - 1); s < t; s++, t--) {
        c = *s;
        *s = *t;
        *t = c;
    }
}

// return index of t in s, -1 if none
int strindex(char *s, char *t) {
    // beginning of string s
    char *bs = s;
    char *p, *r;

    for (; *s != '\0'; s++) {
        for (p = s, r = t; *r != '\0' && *p == *r; p++, r++);
        if (r > t && *r == '\0') {
            return s - bs;
        }
    }
    return -1;
}

// convert string s to double, pointer version
double atof(char *s) {
    double val, power;
    int sign;

    while (isspace(*s)) {
        s++;
    }
    sign = (*s == '-') ? -1 : 1;
    if (*s == '-' || *s == '+') {
        s++;
    }
    for (val = 0.0; isdigit(*s); s++) {
        val = val * 10.0 + (*s - '0');
    }
    if (*s == '.') {
        s++;
    }
    for (power = 1.0; isdigit(*s); s++) {
        val = val * 10.0 + (*s - '0');
        power *= 10;
    }
    return sign * val / power;
}

// signal that a number was found
#define NUMBER '0'

int getch(void);

void ungetch(int);

// get next operator or numeric operand; pointer version
int getop(char *s) {
    int c;

    while ((*s = c = getch()) == ' ' || c == '\t');
    *(s + 1) = '\0';
    if (!isdigit(c) && c != '.') {
        // not a number
        return c;
    }
    // collect integer part
    if (isdigit(c)) {
        while (isdigit(*++s = c = getch));
    }
    // collect fraction part
    if (c == '.') {
        while (isdigit(*++s = c = getch()));
    }
    *s = '\0';
    if (c != EOF) {
        ungetch(c);
    }
    return NUMBER;
}
