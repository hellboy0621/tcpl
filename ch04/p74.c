#include <stdio.h>

// 打印十进制数 n
// 不能处理最大的负数
void printd(int n) {
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n / 10) {
        printd(n / 10);
    }
    putchar(n % 10 + '0');
}

// 以递增顺序对 v[left]...v[right] 进行排序
void qsort(int v[], int left, int right) {
    int i, last;
    void swap(int v[], int i, int j);

    if (left >= right) {
        return;
    }
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if (v[i] < v[left]) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

void swap(int v[], int i, int j) {
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int main() {
    printd(345);
    printf("\n");
    printd(-4568345);
    printf("\n");

    int v[] = {3, 5, 1, 2, 4, 6};
    qsort(v, 0, 5);
    for (int i = 0; i < 6; ++i) {
        printf("%d ", v[i]);
    }
}