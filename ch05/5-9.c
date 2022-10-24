#include <stdio.h>

static char daytab[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day) {
    int leap = (year % 4 == 0 && year % 400 != 0) || year % 400 == 0;
    char *p;
    p = daytab[leap];
    while (--month) {
        day += *++p;
    }
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
    int leap = (year % 4 == 0 && year % 400 != 0) || year % 400 == 0;
    char *p;
    p = daytab[leap];
    while (yearday > *++p) {
        yearday -= *p;
    }
    *pmonth = p - *(daytab + leap);
    *pday = yearday;
}

int main() {
    printf("2022-03-01 day of year = %d\n", day_of_year(2022, 3, 1));
    int pmonth = 0;
    int pday = 0;
    month_day(2020, 60, &pmonth, &pday);
    printf("2020's 60th day is month = %d, day = %d\n", pmonth, pday);
}