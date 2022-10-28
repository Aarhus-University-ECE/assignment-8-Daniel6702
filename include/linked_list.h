#ifndef __LINKED_LIST_H_
#define __LINKED_LIST_H_
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
  int data;
  struct node *next;
} node;

typedef struct
{
  node *head;
} linked_list;

node *createNode(int value);
linked_list *createLinkedList();
void insertFront(node *nodePtr, linked_list *llPtr);
node *swap(node *x, node *y);
bool isempty();
void printLL(linked_list *llPtr);

#endif // __LINKED_LIST_H_
