#include <stdio.h>

// escape : expand newline and tab info visible sequences
// while copying the string t to s
void escape(char s[], char t[]) {
    int i, j;

    for (i = j = 0; t[i] != '\0'; i++) {
        switch (t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = t[i];
                break;
        }
    }
    s[j] = '\0';
}

// unescape: convert escape sequences into real characters
// while copying the string t to s
void unescape(char s[], char t[]) {
    int i, j;

    for (i = j = 0; t[i] != '\0'; i++) {
        switch (t[i]) {
            case '\\':
                switch (t[++i]) {
                    case 'n':
                        s[j++] = '\n';
                        break;
                    case 't':
                        s[j++] = '\t';
                        break;
                    default:
                        s[j++] = '\\';
                        s[j++] = t[i];
                        break;
                }
                break;
            default:
                s[j++] = t[i];
                break;
        }
    }
    s[j] = '\0';
}

int main() {
    setbuf(stdout, NULL);

    char t[100] = "abc\tdef\nkkk 123";
    printf("%s\n", t);

    char s[100];
    escape(s, t);
    // abc\tdef\nkkk 123
    printf("%s\n", s);

    char r[100];
    unescape(r, s);
    printf("%s\n", r);
    return 0;
}