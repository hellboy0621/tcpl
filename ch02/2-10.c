#include <stdio.h>

// 将大写字母转小写字母
int original_lower(int c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 'a' - 'A';
    }
    return c;
}

int lower(int c) {
    return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c;
}

int main() {
    printf("the lower of %c is %c\n", 'G', original_lower('G'));
    printf("the lower of %c is %c\n", 'G', lower('G'));
}