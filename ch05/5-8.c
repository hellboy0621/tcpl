#include <stdio.h>

static char daytab[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day) {
    if (year < 1) {
        return -1;
    }
    if (month < 1 || month > 12) {
        return -1;
    }
    int leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    if (day < 1 || day > daytab[leap][month]) {
        return -1;
    }
    for (int i = 0; i < month; ++i) {
        day += daytab[leap][i];
    }
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
    if (year < 1) {
        *pmonth = -1;
        *pday = -1;
        return;
    }
    int leap = (year % 4 == 0 && year % 400 != 0) || year % 400 == 0;
    int i;
    for (i = 1; i <= 12 && yearday > daytab[leap][i]; i++) {
        yearday -= daytab[leap][i];
    }
    if (i > 12 || yearday > daytab[leap][12]) {
        *pmonth = -1;
        *pday = -1;
        return;
    }
    *pmonth = i;
    *pday = yearday;
}

int main() {
    printf("2022-03-01 day of year = %d\n", day_of_year(2022, 3, 1));
    int pmonth = 0;
    int pday = 0;
    month_day(2020, 60, &pmonth, &pday);
    printf("2020's 60th day is month = %d, day = %d\n", pmonth, pday);
}
