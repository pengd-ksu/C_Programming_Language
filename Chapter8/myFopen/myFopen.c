#include "myFile.h"

// RW for owner, group, others
#define PERMS 0666

/* 
    myFopen: open file, return file ptr. It doesn't 
    allocate any buffer space; this is done by 
    _myfillbuf when the file is first read
*/
MYFILE *myFopen(char *name, char *mode) {
    int fd;
    MYFILE *fp;
    
    // myFopen handles 3 modes: read, write, and append
    if (*mode != 'r' && mode != 'w' && mode != 'a') {
        return MYNULL;
    }
    for (fp = _myiob; fp < _myiob + MYOPEN_MAX; fp++) {
        if ((fp->myflag & (_MYREAD | _MYWRITE)) == 0) {
            break;
        }
    }
    // no free slots
    if (fp >= _myiob + MYOPEN_MAX) {
        return MYNULL;
    }

    if (*mode == 'w') {
        fd = creat(name, PERMS);
    }
    else if (*mode == 'a') {
        if ((fd = open(name, O_WRONLY, 0)) == -1) {
            fd = creat(name, PERMS);
        }
        lseek(fd, 0L, 2);
    } else {
        fd = open(name, O_RDONLY, 0);
    }
    // Couldn't access name
    if (fd == -1) {
        return MYNULL;
    }
    fp->myfd = fd;
    fp->mycnt = 0;
    fp->mybase = MYNULL;
    fp->myflag = (*mode == 'r') ? _MYREAD : _MYWRITE;
    return fp;
}