
// set n bits of x at position p with bits of y
unsigned setbits(unsigned x, int p, int n, unsigned y) {
    // x 从 p 位开始的 n 个位，全部清零
    return x & ~(~(~0 << n) << (p - n + 1))
           |
           (y & ~(~0 << n)) << (p - n + 1);
}
