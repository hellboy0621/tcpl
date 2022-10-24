#include <stdio.h>

int echo1(int argc, char *const *argv);

int echo2(int argc, char *const *argv);

int main(int argc, char *argv[]) {
//    return echo1(argc, argv);
    return echo2(argc, argv);
}

// 回显程序命令行参数，版本1
int echo1(int argc, char *const *argv) {
    for (int i = 1; i < argc; ++i) {
        printf("%s%s", argv[i], (i < argc - 1) ? " " : "");
    }
    printf("\n");
    return 0;
}

// 回显程序命令行参数，版本2
int echo2(int argc, char *const *argv) {
    while (--argc > 0) {
        printf("%s%s", *++argv, (argc > 1) ? " " : "");
    }
    printf("\n");
    return 0;
}

