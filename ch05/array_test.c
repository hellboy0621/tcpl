#include <stdio.h>

int main() {
    int i = 0;
    int arr[3] = {0};
    for (; i <= 3; ++i) {
        // 本来以为 arr[3] 是 i 的内存地址，可以无限循环打印 hello world
        // 实际运行后，只会打印4次程序就运行结束了
        arr[i] = 0;
        printf("hello world \n");
    }
    return 0;
}