#include <string.h>

// returns rightmost index of t in s, -1 if none
int strrindex(char s[], char t[]) {
    int i, j, k, pos;

    pos = -1;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) {

        }
        if (k > 0 && t[k] == '\0') {
            pos = i;
        }
    }

    return pos;
}

/*
 * 从字符串s的尾部，向串首推进字符串t的长度个字符的位置开始寻找字符串t。
 * 如果没有匹配，将从右到左后退一个位置再次进行比较。
 * 当在字符串s中找到字符串t时，将立刻返回变量i，因为变量i此时的取值，就是字符串t在字符串s中最右边出现的位置。
 */
// returns rightmost index of t in s, -1 if none
int strrindex2(char s[], char t[]) {
    int i, j, k;

    for (i = strlen(s) - strlen(t); i >= 0; i--) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) {

        }
        if (k > 0 && t[i] == '\0') {
            return i;
        }
    }

    return -1;
}