#include <stdio.h>

#define YES 1
#define NO 0

int htoi(const char s[]);

int main() {
    // 59229
    printf("result = %d\n", htoi("0xE75D"));
    // 41704
    printf("result = %d\n", htoi("A2E8"));
}

// 把由十六进制数字组成的字符串（包含可选的前缀 0x 或 0X）转换为与之等价的整型数
// convert hexadecimal string s to integer
int htoi(const char s[]) {
    int hexdigit, i, inhex, n;

    i = 0;
    if (s[i] == '0') {
        // skip optional 0x or 0X
        ++i;
        if (s[i] == 'x' || s[i] == 'X') {
            ++i;
        }
    }
    // integer value to be returned
    n = 0;
    // assume valid hexadecimal digit
    inhex = YES;
    for (; inhex == YES; ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            hexdigit = s[i] - '0';
        } else if (s[i] >= 'a' && s[i] <= 'f') {
            hexdigit = s[i] - 'a' + 10;
        } else if (s[i] >= 'A' && s[i] <= 'F') {
            hexdigit = s[i] - 'A' + 10;
        } else {
            // not a valid hexadecimal digit
            inhex = NO;
        }
        if (inhex == YES) {
            n = 16 * n + hexdigit;
        }
    }
    return n;
}
