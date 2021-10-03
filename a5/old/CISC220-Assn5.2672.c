#include<stdio.h> 
#include<stdlib.h> 

#define STACK_MAX 3

    typedef struct node node; // Necessary in C, harmless (but non-idiomatic) in C++

    typedef struct node{
        char data[50];
        struct node *next;
        int size;
    } node;

    //typedef struct node item;

    void init(node *head){
        head = NULL;
        head->size = 0;
    }

    void push(node *stack, char inputdata[]){
        if (stack->size < STACK_MAX){
            //stack->data[stack->size++] = inputdata;
            
            node* newnode = (node*)malloc(sizeof(node));
            newnode->data[stack->size] = inputdata;
            newnode->next = stack->next; //should be first
            stack->next = newnode;
            (stack->size)++;
        }
        else
            printf("The stack is full and cannot take any more elements.\n");
    }


    void pop(node *stack){
        int temp;
        node* toBePopped;
        
        if(stack->next!=NULL){
            temp = stack->next->data;
            toBePopped = stack->next;
            stack->next = stack->next->next;
            free(toBePopped);
        }
        else
            printf("Cannot pop an empty stack\n");
    }

void main(){
    printf("Creating a Stack that can take only 3 string elements.\n");
    struct node* head = NULL;
    // int size, element;
    init(head);

    printf("Pushing");
    push(head, "First Element");
    printf("The stack status: { \"%s\" }\n", head->data[0]);

    printf("Pushing");
    push(head, "Second Element");
    printf("The stack status: { \"%s\", \"%s\" }\n", head->data[0], head->data[1]);

    printf("Pushing");
    push(head, "Third Element");
    printf("The stack status: { \"%s\", \"%s\", \"%s\" }\n", head->data[0], head->data[1], head->data[2]);

    printf("Pushing");
    push(head, "Forth Element");
    
    printf("Popping");
    pop(head);
    printf("The stack status: { \"%s\", \"%s\", \"%s\" }", head->data[0], head->data[1], head->data[2]);

    printf("Popping");
    pop(head);
    printf("The stack status: { \"%s\", \"%s\", \"%s\" }", head->data[0], head->data[1], head->data[2]);

    printf("Popping");
    pop(head);
    printf("The stack status: { \"%s\", \"%s\", \"%s\" }", head->data[0], head->data[1], head->data[2]);//The stack is empty

    printf("Popping");
    pop(head);
    printf("End of program");
}
