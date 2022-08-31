#include <stdio.h>
#include <limits.h>

// determine ranges of types
int main() {
    // 利用标准头文件来确定类型取值范围
    // signed types
    printf("signed char min     = %d\n", SCHAR_MIN);
    printf("signed char max     = %d\n", SCHAR_MAX);
    printf("signed short min    = %d\n", SHRT_MIN);
    printf("signed short max    = %d\n", SHRT_MAX);
    printf("signed int min      = %d\n", INT_MIN);
    printf("signed int max      = %d\n", INT_MAX);
    printf("signed long min     = %ld\n", LONG_MIN);
    printf("signed long max     = %ld\n", LONG_MAX);

    printf("\n");
    // unsigned types
    printf("unsigned char max   = %u\n", UCHAR_MAX);
    printf("unsigned short max  = %u\n", USHRT_MAX);
    printf("unsigned int max    = %u\n", UINT_MAX);
    printf("unsigned long max   = %lu\n", ULONG_MAX);

    printf("\n\n");

    // 利用按位运算符进行计算
    // signed types
    printf("signed char min = %d\n", -(char) ((unsigned char) ~0 >> 1) - 1);
    printf("signed char max = %d\n", (char) ((unsigned char) ~0 >> 1));
    printf("signed short min = %d\n", -(short) ((unsigned short) ~0 >> 1) - 1);
    printf("signed short max = %d\n", (short) ((unsigned short) ~0 >> 1));
    printf("signed int min = %d\n", -(int) ((unsigned int) ~0 >> 1) - 1);
    printf("signed int max = %d\n", (int) ((unsigned int) ~0 >> 1));
    printf("signed long min = %ld\n", -(long) ((unsigned long) ~0 >> 1) - 1);
    printf("signed long max = %ld\n", (long) ((unsigned long) ~0 >> 1));

    printf("\n");

    // unsigned types
    printf("unsigned char max = %u\n", (unsigned char) ~0);
    printf("unsigned short max = %u\n", (unsigned short) ~0);
    printf("unsigned int max = %u\n", (unsigned int) ~0);
    printf("unsigned long max = %lu\n", (unsigned long) ~0);

    return 0;
}
/*
signed char min     = -128
signed char max     = 127
signed short min    = -32768
signed short max    = 32767
signed int min      = -2147483648
signed int max      = 2147483647
signed long min     = -2147483648
signed long max     = 2147483647

unsigned char max   = 255
unsigned short max  = 65535
unsigned int max    = 4294967295
unsigned long max   = 4294967295


signed char min = -128
signed char max = 127
signed short min = -32768
signed short max = 32767
signed int min = -2147483648
signed int max = 2147483647
signed long min = -2147483648
signed long max = 2147483647

unsigned char max = 255
unsigned short max = 65535
unsigned int max = 4294967295
unsigned long max = 4294967295

Process finished with exit code 0

 */