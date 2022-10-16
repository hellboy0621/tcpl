// 可用空间大小
#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
// 下一个空闲位置
static char *allocp = allocbuf;

// 返回指向 n 个字符的指针
char *alloc(int n) {
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        // 有足够的空闲空间
        allocp += n;
        return allocp - n;
    } else {
        return 0;
    }
}

// 释放 p 指向的存储区
void afree(char *p) {
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE) {
        allocp = p;
    }
}
