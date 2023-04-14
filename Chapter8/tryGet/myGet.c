#include <unistd.h>
// to use stderr
#include <stdio.h>
// to use O_RDONLY
#include <fcntl.h>

#define LEN 20
#define MAXLEN 1000
#define START 0

// get: read n bytes from position pos
int get(int fd, long pos, char *buf, int n) {
    if (lseek(fd, pos, 0) >= 0) {
        // get to pos
        return read(fd, buf, n);
    } else {
        return -1;
    }
}

int main (int argc, char *argv[]) {
    int fd;
    char buffer[MAXLEN];
    if (argc != 2) {
        fprintf(stderr, "Usage: get file");
    }
    if ((fd = open(*++argv, O_RDONLY, 0)) == -1) {
        fprintf(stderr, "get can't open file %s", *argv);
    } else {
        get(fd, START, buffer, LEN);
        if ((write(1, buffer, LEN)) != LEN) {
            fprintf(stderr, "Can't write to stdout");
        }
    }
    return 0;
}