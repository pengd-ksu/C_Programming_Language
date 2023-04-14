#include <string.h>
// to import system function
#include <stdlib.h>

int main () {
   char command[50];

   strcpy( command, "tree\n" );
   strcat( command, "date" );
   system(command);

   return(0);
}