#include "myFile.h"

// _myfillbuf: allocate and fill input buffer
int _myfillbuf(MYFILE *fp) {
    int bufsize;
    
    if((fp->myflag & (_MYREAD | _MYEOF | _MYERR)) != _MYREAD) {
        return MYEOF;
    }
    bufsize = (fp->myflag & _MYUNBUF) ? 1 : MYBUFSIZ;
    // no buffer yet
    if (fp->mybase == MYNULL) {
        if ((fp->mybase = (char *) malloc(bufsize)) == MYNULL) {
            return MYEOF;
        }
    }
    fp->myptr = fp->mybase;
    fp->mycnt = read(fp->myfd, fp->myptr, bufsize);
    if (--fp->mycnt < 0) {
        if (fp->mycnt == -1) {
            fp->myflag |= _MYEOF;
        } else {
            fp->myflag |= _MYERR;
        }
        fp->mycnt = 0;
        return MYEOF;
    }
    return (unsigned char) *fp->myptr++;
}