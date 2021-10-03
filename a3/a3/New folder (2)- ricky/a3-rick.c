// cisc220 assignment 3 
// Ricky Zhang 16hz47
// taking 2 numbers from user and perform bitwise operation

// include standard input ourput, and define constants
#include<stdio.h>
#define NUM_MIN 5
#define NUM_MAX 50

// declaring methods used
int main(void);
int getNum(int min, int max, char prompt[], char error_prompt[]);
int atoi(char num_s[]);

// main, tell getNum to get inputs, and perform bitwise operation
// looping until user inputs -1
int main(void){
  int run = 0;
  while(run == 0){
    // ask for a and b
    int a;
    a = getNum(NUM_MIN,NUM_MAX,"Enter A, between 5 and 50:","Your number must be between 5 and 50\n");
    int b;
    b = getNum(NUM_MIN,NUM_MAX,"Enter B, between 5 and 50:","Your number must be between 5 and 50\n");

    // ask for which bitwise operation to perform
    int choice;
    choice = getNum(1,3,"Choose Bitwise operator for A and B:\nEnter 1 for AND\nEnter 2 for OR\nEnter 3 for XOR", "only “1, 2, or 3”are allowed\n");

    // perform the operation and output the result
    if (choice == 1){
      printf("%d AND %d = %d\n",a,b,a&b);
    }
    else if (choice == 2){
      printf("%d OR %d = %d\n",a,b,a|b);
    }
    else if (choice == 3){
      printf("%d XOR %d = %d\n",a,b,a^b);
    }

    // ask to continue/exit
    printf("Type -1 to exit, or anything else to restart\n");
    char command[100];
    scanf("%s",command);
    if (command[0] == '-' && command[1] == '1'){
      run = -1;
    }
  }
  return 0;
}

// prompt user for input within supposed range, and can print custom error message
int getNum(int min, int max, char prompt[], char error_prompt[]) {
    int pass = 0;
    int num = 0;
    while(pass == 0){
        printf("%s", prompt);
        printf("%s", "\n");
        
        char num_s[100];
        scanf("%s",num_s);
        
        num = atoi(num_s);
        
        if (num == 0) {
          printf("%s","You enter an alphabet character(s), enter only a digit character(s)\n");
        }
        else{
          if (num >= min && num <= max) {
            pass = 1;
            return num;
          }
          else {
            printf("%s", error_prompt);
          }
        }
    }
    return 0;
}
