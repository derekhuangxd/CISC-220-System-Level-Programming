#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

#define STACK_MAX 3

struct node{
    char data[50];
    struct node *next;
};
typedef struct node node;

void init(){
    node *head;
}

node *head;

int CalculateNumOfData(node *head) {
    if (head == NULL) {
        return 0;
    }
    else if (head -> next == NULL) {
        return 1;
    }
    else if (head -> next != NULL) {
        return 1 + CalculateNumOfData(head -> next);
    }
}

int push(char string[], int num){
    if (CalculateNumOfData(head) >= STACK_MAX) {
        printf("The stack is full and cannot take more elements\n");
        return 0;
    }
    else {
        node *tmp = malloc(sizeof(node));
        strcpy(tmp -> data, string);
        tmp -> next = head;
        head = tmp;
        return 1;
    }
}

int pop(){
    if (head == NULL)
        return 0;
    else {
        node *temp;
        temp = head;
        head = head -> next;
        free(temp);
        if (head == NULL)
            return 2;
        else 
            return 1;
    }
}

void printAll(node *head) {
    if (head != NULL) {
        printAll(head -> next);
        if (head -> next != NULL) {
            printf(", ");
        }
        printf("\"%s\"", head -> data);
    }
}

void main(){
    printf("Creating a Stack that can take only 3 string elements.\n");
    head = NULL;
    //init();

    char *arr[4] = {"First Element", "Second Element", "Third Element", "Forth Element"};
    
    int value = 0;
    for (int i = 0; i < 4; i++) {
        printf("Pushing\n");
        value = push(arr[i], i + 1);

        if (value) {
            printf("The stack status: {");
            printAll(head);
            printf("}\n");
        }
        else {
            break;
        }
    }

    value = 0;
    for (int i = 4; i > 0; i--){
        printf("Popping\n");
        value = pop();
        if (!value) {
            printf("Cannot pop an empty stack\n");
            break;
        }
        else if (value == 2) {
            printf("The stack is empty. \n");
        }
        else if (value) {
            printf("The stack: {");
            printAll(head);
            printf("}\n");
        }
        else if (!value) {
            printf("Cannot pop an empty stack\n");
            break;
        }
    }

    //End of program==========================================================================

    printf("End of program\n");
}
