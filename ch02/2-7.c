
// invert the bits of x that begin at position p
unsigned invert(unsigned x, int p, int n) {
    // 1. (~0 << n) 将所有位都为1的屏蔽码左移n位，在它最右端制造出n位0
    // 2. ~(~0 << n) 把屏蔽码最右侧的n位设置为1，其余位全部设置为0
    // 3. ~(~0 << n) << (p - n + 1) 把屏蔽码最右侧的n位1，左移到第p位处
    // 4. 屏蔽码与x进行异或，完成对x，从第p位开始的n位进行翻转的工作
    return x ^ (~(~0 << n) << (p - n + 1));
}
