// Ricky Zhang
// CISC220 Assignment 5
// 16hz47

// includoing the libraries used
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// declaring node struct
// a ndoe contains a word, and a pointer to the next node
struct node {
    char word[50];
    struct node *next;
};
typedef struct node node;

// initialize the linked list
node *head;

// list out the strings in the stack, recursively
void list(node *head) {
    if (head != NULL) {
        list(head -> next);
        if (head -> next != NULL) {
            printf(", ");
        }
        printf("\"%s\"", head -> word);
    }
}

// measures the number of elements in stack
int height(node *head) {
    if (head == NULL) {
        return 0;
    }
    else if (head -> next != NULL) {
        return 1 + height(head -> next);
    }
    else if (head -> next == NULL) {
        return 1;
    }
}

// push the given string to stack
int push(char string[], int num) {
    printf("Pushing\n");
    int h = height(head);
    if (h >= 3) {
        printf("The stack is full and cannot take more elements\n");
        return 0;
    }
    else {
        // create new node for the new value and link it in
        node *temp;
        temp = malloc(sizeof(node));
        strcpy(temp -> word, string);
        temp -> next = head;
        head = temp;
        return 1;
    }
}

// pop the string at the top of the stack out
char pop() {
    printf("Popping\n");
    if (head == NULL) {
        return 0;
    }
    else {
        node *temp;
        temp = head;
        head = head -> next;
        free(temp);
        if (head == NULL) {
            return 2;
        }
        else {
            return 1;
        }
    }
}

// main function that push string in and pop string out
int main() {
    // create the stack
    head = NULL;
    printf("Creating a Stack that can take only 3 string elements.\n");

    // create the string array for pushing
    char * strings[4];
    strings[0] = "First Element";
    strings[1] = "Second Element";
    strings[2] = "Third Element";
    strings[3] = "Forth Element";
    
    // try to push all the strings to stack
    int i;
    int result;
    for (i = 0; i < 4; i++) {
        result = push(strings[i], i + 1);
        if (result == 1) {
            printf("The stack status: {");
            list(head);
            printf("}\n");
        }
        else {
            break;
        }
    }
    // try to pop all the strings from stack
    i = 4;
    result = 0;
    while (i > 0) {
        result = pop();;
        if (result == 0) {
            printf("Cannot pop an empty stack\n");
            break;
        }
        else if (result == 1) {
            printf("The stack: {");
            list(head);
            printf("}\n");
        }
        else if (result == 0) {
            printf("Cannot pop an empty stack\n");
            break;
        }
        else if (result == 2) {
            printf("The stack is empty. \n");
        }
        i--;
    }

    // end of program
    printf("End of program\n");
    return 0;
}
