#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define minNum 5
#define maxNum 50
#define sentinelVal -1 //for the end of the user's input.

    int a;
    int b;
    int c; //bitwiseOperator
    int d; //output value

void operatorFn(){
    c,d=0;
    printf("enter 1 for A & B \nenter 2 for A | B \nenter 3 for A ^ B \nenter your choice: ");
    if(!scanf("%d", &c)){
        printf("Your entry is not accepted; it must be 1-3.\n");
        // Now the \n needs to be read, consume & read
        int ch;
        while ((ch = fgetc(stdin)) != EOF && ch != '\n'){
        }
        operatorFn();
    }
    else if (c==sentinelVal){
            printf("The program has been terminated.\n");
            exit(3);
    }
    else if (c==1 || c==2 || c==3){
        d = (c==1) ? a&b :d;
        d = (c==2) ? a|b :d;
        d = (c==3) ? a^b :d;

        char op='\0'; //operator
        op = (c==1) ? '&' :op;
        op = (c==2) ? '|' :op;
        op = (c==3) ? '^' :op;

        printf("%d %c %d = %d \n", a, op, b, d);
    }
    else{
        printf("Your entry is not accepted; it must be 1-3.\n");
        operatorFn();
    }
}
    
void main(){
    a, b= 0;
        printf("enter a value of \"A\" : ");
        if (!scanf("%d", &a)){
            printf("you have entered an alphabetic characters, enter a number between 5 and 50\n");
            // Now the \n needs to be read, consume & read
            int ch;
            while ((ch = fgetc(stdin)) != EOF && ch != '\n'){
            }
            main();
        }
        else if (a==sentinelVal){
            printf("The program has been terminated.\n");
            exit(1);
        }
        else if (a<minNum||a>maxNum){
            printf("you have entered an a value out of accepted range, enter a number between 5 and 50\n");
            main();
        }
        else if (a>=minNum||a<=maxNum){
            printf("enter a value of \"B\" : ");
            if (!scanf("%d", &b)){
                printf("you have entered an alphabetic characters, enter a number between 5 and 50\n");
                // Now the \n needs to be read, consume & read
                int ch;                
                while ((ch = fgetc(stdin)) != EOF && ch != '\n'){
                }
                main();
                }
            else if (b==sentinelVal){
                printf("The program has been terminated.\n");
                exit(2);
            } 
            else if (b<minNum||b>maxNum){
                printf("you have entered an a value out of accepted range, enter a number between 5 and 50\n");
                main();
            }
            else if (b>=minNum||b<=maxNum){
                operatorFn();
                main();
            }
        }
}
