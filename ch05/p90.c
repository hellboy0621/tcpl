
void a() {
    // 定义一个数组
    char ameaseage[] = "now is the time";
    // 定义一个指针
    char *pmessage = "now is the time";
}

// 将指针 t 指向的字符串复制到指针 s 指向的位置；
// 使用数组下标实现的版本
void strcpy(char *s, char *t) {
    int i = 0;
    while ((s[i] = t[i]) != '\0') {
        i++;
    }
}

// 将指针 t 指向的字符串复制到指针 s 指向的位置；
// 使用指针方式实现的版本1
void strcpy1(char *s, char *t) {
    while ((*s = *t) != '\0') {
        s++;
        t++;
    }
}

// 将指针 t 指向的字符串复制到指针 s 指向的位置；
// 使用指针方式实现的版本2
void strcpy2(char *s, char *t) {
    while ((*s++ = *t++) != '\0');
}

// 将指针 t 指向的字符串复制到指针 s 指向的位置；
// 使用指针方式实现的版本3
void strcpy3(char *s, char *t) {
    while (*s++ = *t++);
}

// 根据 s 按照字典顺序小于、等于或大于 t 的结果分别返回负整数、0或正整数
int strcmp(char *s, char *t) {
    int i;

    for (i = 0; s[i] == t[i]; i++) {
        if (s[i] == '\0') {
            return 0;
        }
    }
    return s[i] - t[i];
}

// 使用指针方式实现的 strcmp
int strcmp2(char *s, char *t) {
    for (; *s == *t; s++, t++) {
        if (*s == '\0') {
            return 0;
        }
    }
    return *s - *t;
}