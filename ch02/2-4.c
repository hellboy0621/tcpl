
// 从字符串 s 中删除字符 c
void sequeeze(char s[], int c) {
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++) {
        if (s[i] != c) {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}

// 将字符串 s1 中任何与字符串 s2 中字符匹配的字符都删除
void sequeeze2(char s1[], char s2[]) {
    int i, j, k;

    for (i = k = 0; s1[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0' && s2[j] != s1[i]; j++) {
        }
        // 如果没有找到匹配的字符，s2 被遍历完，进入 if 分支，s1[i] 被复制到结果字符串 s1 中
        // 如果找到了匹配的字符，s2 没有被遍历完，不会进入 if 分支，不会被复制到结果字符串中
        if (s2[j] == '\0') {
            s1[k++] = s1[i];
        }
    }
    s1[k] = '\0';
}
