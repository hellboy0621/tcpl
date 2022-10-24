#include <stdio.h>
#include <string.h>

// 进行排序的最大文本行数
#define MAXLINES 5000

// 指向文本行的指针数组
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);

void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

// 对输入的文本行进行排序
int main() {
    // 读取的输入行数目
    int nlines;

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

// 每个输入文本行的最大长度
#define MAXLEN 1000

int getline1(char *, int);

char *alloc(int);

// 读取输入行
int readlines(char *lineptr[], int maxlines) {
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getline1(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = alloc(len) == NULL)) {
            return -1;
        } else {
            // 删除换行符
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}


// 写输出行
void writelines(char *lineptr[], int nlines) {
    for (int i = 0; i < nlines; i++) {
        printf("%s\n", lineptr[i]);
    }
//    while (nlines-- > 0) {
//        printf("%s\n", *lineptr++);
//    }
}

void qsort(char *v[], int left, int right) {
    int i, last;
    void swap(char *v[], int i, int j);

    // 如果数组元素的个数小于 2，则返回
    if (left >= right) {
        return;
    }
    swap(v, left, left + (right - left) / 2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if (strcmp(v[i], v[left]) < 0) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    swap(v, left, last - 1);
    swap(v, last + 1, right);
}

// 交换 v[i] 和 v[j]
void swap(char *v[], int i, int j) {
    char *temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

