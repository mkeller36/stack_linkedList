#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define STACK_EMPTY -1
#define E_OK 1

typedef struct{
  int value;
  struct node *next;
} node;

typedef node * stack;     /*Creates a stack object that is the address of a node, this way we can choose which stack we are writing to instead of using one globally*/

int push(stack *myStack, int x) ;
int pop(stack *myStack) ;

int push(stack *myStack, int x) {
  node *newNode = malloc(sizeof(node));
  if(newNode == NULL) {   /*Malloc failed, no more memory*/
    return -1;
  }
  newNode->value = x;         /*fill value of new node from input*/
  newNode->next = *myStack;   /*Make new node point to previous top of stack*/
  *myStack = newNode;         /*Update pointer to top of the stack*/
  return E_OK;
}

int pop(stack *myStack) {
  if(*myStack == NULL){
    fprintf(stderr,"ERROR: The stack is empty\n");
    return -1;
  }

  int out = (*myStack)->value;  /*Get value of node*/
  node *tmpPntr = *myStack;   /*Temorarily hold address of head element*/
  *myStack = (*myStack)->next;  /*Set address of head to the next node down*/
  free(tmpPntr);              /*Clear data at previous head's address*/
  return out;
}

int main(int argc, char* argv[]) {
  stack s1 = NULL;
  stack s2 = NULL;    /*initialize three separate stacks*/
  push(&s1, 1);     /*Pass address of stack s1, as well as value, into pop*/
  push(&s1, 2);
  push(&s1, 3);
  push(&s2, 5);
  
  int retVal;
  while((retVal = pop(&s1)) != STACK_EMPTY){
    printf("%d \n", retVal);
  }
  
  return 0;
}