#include "list_queue.h"

void init_queue(queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

int empty(queue *q) {
  if (q->rear == NULL) {  
    return true;
  } else {
    return false;
  }
}

void print_queue(queue *q)
{
  qnode *n = q->front;
  while (n != NULL)
  {
    printf("| %d ", n->data);
    n = n->next;
  }
  printf("|\n");
}

void enqueue(queue *q, int x) {
  qnode* temp= malloc(sizeof(qnode)); //create new node with given value
  temp->data = x;
  temp->next = NULL;
  if (empty(q)) { //if queue is empty, new node will be both rear and front
    q->front = temp;
    q->rear = temp;
  }
  q->rear->next = temp; //else add node to rear of queue
  q->rear = temp;
}

int dequeue(queue *q) {
  assert(empty(q)==false); //the queue cant be empty
  int data = q->front->data; //save data from front node in queue
  q->front = q->front->next; //dequeue the node
  if (q->front == NULL) { //if front is now empty, then change rear to empty
    q->rear = NULL;
  } 
  return data; //return the saved data from dequeued node
}