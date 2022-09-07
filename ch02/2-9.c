#include <stdio.h>

/**
 * x &= (x - 1)
 * 可以删除 x 中最右边值为1的一个二进制位
 * 以一个4位的无符号数值为例，假设x的值为9，二进制为 1001
 *   1001
 * & 1000
 *   1000
 * 可见，x最右端值为1的位被清零了，重复
 *   1000
 * & 0111
 *   0000
 * x最右端值为1的位又被清零了。此时，新的x中再也没有1的位了，过程就此结束。
 * 做了2次赋值操作，对应 1001 中有2位1。
 * 最坏的情况下（即当x中所有位都为1时），新方案需要进行 & 操作次数与原函数需要进行的移位次数一样多，因此会执行的更快些。
 */
int bitcount(unsigned x) {
    int count = 0;
    while (x != 0) {
        count++;
        x &= (x - 1);
    }

    return count;
}

/**
 * 以一个4位的无符号数值为例
 * 统计数值中值为1的个数
 * 需要进行4次移位操作，并对最右端的位做4次比较
 */
int origin_bitcount(unsigned x) {
    int b;
    for (b = 0; x != 0; x >>= 1) {
        if (x & 01) {
            b++;
        }
    }
    return b;
}

int main() {
    // 9
    // 1111011001110000000000000000
    printf("count = %d\n", bitcount(258408448));
    printf("count = %d\n", origin_bitcount(258408448));
}