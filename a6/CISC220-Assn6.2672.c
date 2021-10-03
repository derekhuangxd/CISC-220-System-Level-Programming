/*
 * This program demonstrates reading from a file, one line at a time.
 * Will split lines that are more than 20 characters long.
 *
 * Assignment 6 for CISC 220, Fall 2018
 * author: Derek Huang
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// max number of characters we will read from line
// (including and end of line characters and null character)
#define STRING_LENGTH 20 //end of line + EOF

int main(int argc, char *argv[]){
  if (argc != 2)  // program name plus input file name
    {
      printf("usage: Assn6 inputfile\n");
      exit(1);
    } // end if
 
  // Try to open the first argument for reading. In case of error,
  // write and error message and abort
  char *inputName = argv[1];
  FILE *inFile = fopen(inputName, "r");
  if (inFile == NULL)
    {
      perror("Error while openin file for input");
      exit(1);
    } // end if
 
  // Read and ech lines until EOF. Abort in case of error
  
int wordlength(const char * str){
   int temppt1=0;
   while(str[temppt1]!=' ' && str[temppt1]!=0 && str[temppt1]!='\n'){
      ++temppt1;
   }
   return temppt1;
}
int wrap(char * s){
   int pt1=0;
   int pt2 = 0;

   while(s[pt1] != '\0'){
    if(s[pt1] == '\n'){
        pt2=0;
    }
    else if(s[pt1] == ' '){
        if(pt2 + wordlength(&s[pt1+1]) >= STRING_LENGTH){
          s[pt1] = '\n';
          pt2 = 0;
        }
    }
    pt2++;
    pt1++;
   }
   return pt2;
}

  char inputLine[999999] ; // the entire passage from the file

    char *readResult = fgets(inputLine, 999999, inFile);

    if (readResult == NULL){
      if (errno == 0){
          exit(0); // end file, not an error
        }
      else{
          perror("error while reading input file");
          exit(1);
        } // end else
    }  // end if
    else{
      fgets(inputLine, wrap(readResult), inFile);
      printf("\n============Program Started============\n\nInput Lines: \n\n\"%s\"\n", inputLine);
    }

  printf("\n============No More Input============\n\n============Program Ended============\n\n");
  return 0;
}  // end main
