/* strcpy: copy t to s; array subscript version */
#include <stdio.h>
#include <string.h>

void myStrcpy_v1(char *s, char *t) {
    int i;
    i = 0;
    while ((s[i] = t[i]) != '\0')
        i++;
}

void myStrcpy_v2(char *s, char *t) {
    while ((*s = *t) != '\0') {
        s++;
        t++;
    }
}

void myStrcpy_v3 (char *s, char *t) {
    while ((*s++ = *t++) != '\0')
        ;
}

void myStrcpy_v4(char *s, char *t) {
    while (*s++ = *t++) // ends when expression is 0.
        ;
}

int main() {
  char str1[20] = "C programming";
  char str2[20];

  // copying str1 to str2
  //myStrcpy_v1(str2, str1);
  //myStrcpy_v2(str2, str1);
  //myStrcpy_v3(str2, str1);
  myStrcpy_v4(str2, str1);

  puts(str2); // C programming

  return 0;
}