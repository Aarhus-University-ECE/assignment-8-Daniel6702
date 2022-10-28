#include "linked_list.h"

node *createNode(int value)
{
  node *nodePtr = malloc(sizeof(node));
  nodePtr->data = value;
  nodePtr->next = NULL;
  return nodePtr;
}

linked_list *createLinkedList()
{
  linked_list *llPtr = malloc(sizeof(linked_list));
  llPtr->head = NULL;
  return llPtr;
}

void insertFront(node *nodePtr, linked_list *llPtr)
{
  nodePtr->next = llPtr->head;
  llPtr->head = nodePtr;
}

node *swap(node *x, node *y)
{
  x->next = y->next;
  y->next = x;
  return y;
}

bool isempty(linked_list *llPtr)
{
  return llPtr->head != NULL;
}

void printLL(linked_list *llPtr)
{
  node *n = llPtr->head;
  while (n != NULL)
  {
    printf("| %d ", n->data);
    n = n->next;
  }
  printf("|\n");
}
