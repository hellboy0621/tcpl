#include <stdio.h>

#define MAXCOL 10
#define TABINC 8

char line[MAXCOL];

int exptab(int pos);

int findblnk(int pos);

int newpos(int pos);

void printl(int pos);

// fold long input lines into two or more shorter lines
int main() {
    int c, pos;

    // position in the line
    pos = 0;
    while ((c = getchar()) != EOF) {
        // store current character
        line[pos] = c;
        if (c == '\t') {
            // expand tab character
            pos = exptab(pos);
        } else if (c == '\n') {
            // print current input line
            printl(pos);
            pos = 0;
        } else if (++pos >= MAXCOL) {
            pos = findblnk(pos);
            printl(pos);
            pos = newpos(pos);
        }
    }

    return 0;
}

// print line until pos column
void printl(int pos) {
    int i;
    for (i = 0; i < pos; ++i) {
        putchar(line[i]);
    }
    if (pos > 0) {
        putchar('\n');
    }
}

// expand tab into blanks
int exptab(int pos) {
    // tab is at least one blank
    line[pos] = ' ';
    for (++pos; pos < MAXCOL; ++pos) {
        line[pos] = ' ';
    }
    if (pos < MAXCOL) {
        return pos;
    } else {
        printl(pos);
        return 0;
    }
}

// find blank's position
int findblnk(int pos) {
    while (pos > 0 && line[pos] != ' ') {
        --pos;
    }
    if (pos == 0) {
        return MAXCOL;
    } else {
        return pos + 1;
    }
}

// rearrange line with new position
int newpos(int pos) {
    int i, j;

    if (pos <= 0 || pos >= MAXCOL) {
        return 0;
    } else {
        i = 0;
        for (j = pos; j < MAXCOL; ++j) {
            line[i] = line[j];
            ++i;
        }
        return i;
    }
}