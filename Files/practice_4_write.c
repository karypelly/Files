
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// a structure to read and write
struct student {
    char fn[20];
    char ln[20];
    char email[20];
    float t1;
    float t2;
    float t3;
};

/**************************************/
int main ()
{
   FILE *outfile;
   struct student input;

   // open Accounts file for writing
   outfile = fopen ("txt.txt","w");
   if (outfile == NULL)
     {
      fprintf(stderr, "\nError opening accounts.dat\n\n");
      exit (1);
     }

   // instructions to user
   printf("Enter \"stop\" for First Name to end program.");

   // endlessly read from keyboard and write to file
   while (1)
     {
      // prompt user
      printf("\nFirst Name: ");
      scanf ("%s", input.fn);
      // exit if no name provided
      if (strcmp(input.fn, "stop") == 0)
         exit(1);
      // continue reading from keyboard
      printf("Last Name : ");
      scanf ("%s", input.ln);
      printf("Email  : ");
      scanf ("%s", input.email);
      printf("T1   : ");
      scanf ("%f", &input.t1);
      printf("T2   : ");
      scanf ("%f", &input.t2);
      printf("T3   : ");
      scanf ("%f", &input.t3);

      // write entire structure to Accounts file
      fwrite (&input, sizeof(struct student), 1, outfile);
     }
}