#ifndef MYFILEHEADER_H
#define MYFILEHEADER_H

#include <stdio.h>
#include <stdlib.h>
// to import read and write
#include <unistd.h>
#include <fcntl.h>

#define MYNULL      0
#define MYEOF       (-1)
#define MYBUFSIZ    1024
// max #files open at once
#define MYOPEN_MAX  20

typedef struct _myiobuf{
    // characters left
    int mycnt;
    // next character position
    char *myptr;
    // location of buff
    char *mybase;
    // mode of file access
    int myflag;
    // file descriptor
    int myfd;
} MYFILE;
extern MYFILE _myiob[MYOPEN_MAX];

#define mystdin     (&_myiob[0])
#define mystdout    (&_myiob[1])
#define mystderr    (&_myiob[2])

enum _myflags {
    // file open for reading
    _MYREAD     = 01,
    // file open for writing
    _MYWRITE    = 02,
    // file is unbuffered
    _MYUNBUF    = 04,
    // EOF has occurred on this file
    _MYEOF      = 010,
    // error occurred on this file
    _MYERR      = 020
};

int _myfillbuf(MYFILE *);
int _myflushbuf(int, MYFILE *);

#define myfeof(p)       (((p)->myflag & _MYEOF)     != 0)
#define myferror(p)     (((p)->myflag & _MYERROR)   != 0)
#define myfileno(p)     ((p)->myfd)

#define mygetc(p)   (--(p)->mycnt >= 0 \
                ? (unsigned char) *(p)->myptr++ : _myfillbuf(p))
#define myputc(x, p)   (--(p)->mycnt >= 0 \
                ? *(p)->myptr++ = (x) : _myflushbuf((x), p))

#define mygetchar() mygetc(mystdin)
#define myputchar() myputc((x), mystdout)

// stdin, stdout, stderr:
MYFILE _myiob[MYOPEN_MAX] = {
    {0, (char *) 0, (char *) 0, _MYREAD, 0},
    {0, (char *) 0, (char *) 0, _MYWRITE, 1},
    {0, (char *) 0, (char *) 0, _MYWRITE | _MYUNBUF, 2}
};

int _myfillbuf(MYFILE *);
MYFILE *myFopen(char *, char *);

#endif