#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define minNum 5
#define maxNum 50
//#define sentinelVal // -1 for the end of the user's input.

    int a;
   char aTerm;
// int main(){ 
//     if(scanf("%d", &a)){
//         printf("Character entered: %d\n", a);
//     }
//     else{
//          printf("not number given, Character entered: %d\n", a);
//     }

// }
void main(){
        printf("enter a value of \"A\" : ");
        if (!scanf("%d", &a)){
            printf("you have entered an alphabetic characters, enter a number between 5 and 50\n");
            int ch = fgetc(stdin);
            main();
        }
}