// Mostly from the c answer book. Still under testing

#include "myFile.h"

int _myflushbuf(int x, MYFILE *fp) {
    int bufsize;
    // characters that already in buffer to be flushed
    int nc;

    if ((fp->myflag & (_MYWRITE | _MYERR)) != _MYWRITE) {
        return _MYEOF;
    }
    bufsize = (fp->myflag & _MYUNBUF) ? 1 : MYBUFSIZ;
    // no buffer yet
    if (fp->mybase == MYNULL) {
        if ((fp->mybase = (char *) malloc(bufsize)) == MYNULL) {
            fp->myflag |= _MYERR;
            return MYEOF;
        }
    } else {
        // buffer already exists
        nc = fp->myptr - fp->mybase;
        if ((write (fp->myfd, fp->mybase, bufsize)) != nc) {
            fp->myflag |= _MYERR;
            return _MYEOF;
        }
    }
    fp->myptr = fp->mybase;
    *fp->myptr++ = (char) x;
    // I think it's because end of array is '\0'
    fp->mycnt = bufsize - 1;
    return x;
}