
// 与 p47.c 折半查找比，并没有得到多大的性能改进，反而失掉了代码的可读性。
int binsearch(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    mid = low + (high - low) / 2;
    while (low <= high && x != v[mid]) {
        if (x < v[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
        mid = low + (high - low) / 2;
    }
    if (x == v[mid]) {
        return mid;
    } else {
        return -1;
    }
}