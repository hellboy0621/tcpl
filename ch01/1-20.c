#include <stdio.h>
// tab increment size
#define TABINC 8

// replace tabs with the proper number of blanks
int main() {
    int c, nb, pos;

    // number of blanks necessary
    nb = 0;
    // position of character int line
    pos = 1;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            // tab character
            nb = TABINC - (pos - 1) % TABINC;
            while (nb > 0) {
                putchar(' ');
                ++pos;
                --nb;
            }
        } else if (c == '\n') {
            // new line character
            putchar(c);
            pos = 1;
        } else {
            // all other character
            putchar(c);
            ++pos;
        }
    }

    return 0;
}
