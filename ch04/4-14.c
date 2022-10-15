#include <stdio.h>

// 前提是，x 或 y 的变量名不能为 _z
#define swap(t, x, y) { t _z; \
_z = x;                     \
x = y;                      \
y = _z;                      \
}
// 注意计算次序的优先级问题
#define square(x) x * x
#define square2(x) (x) * (x)


int main() {
    int i = 3;
    int j = 5;
    swap(int, i, j);
    // i = 5, j = 3
    printf("i = %d, j = %d\n", i, j);

    int a = 3;
    // 等效于 a + 1 * a + 1 => a + a + 1 => 2a + 1
    int b = square(a + 1);
    // a = 3, b = 7
    printf("a = %d, b = %d\n", a, b);
    int c = square2(a + 1);
    // a = 3, c = 16
    printf("a = %d, c = %d\n", a, c);
}
