#include <stdio.h>

// rotate x to the right by n positions
unsigned rightrot(unsigned x, int n) {
    int worldlength(void);
    // right most bit
    int rbit;

    while (n-- > 0) {
        rbit = (x & 1) << (worldlength() - 1);
        // shift x 1 position right
        x = x >> 1;
        // complete one rotation
        x = x | rbit;
    }
    return x;
}

// computes world length of the machine
int worldlength(void) {
    int i;
    unsigned v = (unsigned) ~0;

    for (i = 1; (v = v >> 1) > 0; i++) {}

    return i;
}

unsigned rightrot2(unsigned x, int n) {
    int worldlength(void);
    unsigned rbits;

    if ((n = n % worldlength()) > 0) {
        rbits = ~(~0 << n) & x;
        rbits = rbits << (worldlength() - n);
        x = x >> n;
        x = x | rbits;
    }
    return x;
}

int main() {
    printf("%d\n", rightrot(7, 2));
    printf("%d\n", rightrot2(7, 2));
}
