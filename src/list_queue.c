#include "list_queue.h"

void init_queue(queue *q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
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
  printf("| size: %d\n",q->size);
}

void enqueue(queue *q, int x) {
  qnode* temp= malloc(sizeof(qnode)); //create new node with given value
  temp->data = x;
  temp->next = NULL;
  if (empty(q)) { //if queue is empty, new node will be both rear and front
    q->front = temp;
    q->rear = temp;
    q->size = 1;
  } else {
    q->rear->next = temp; //else add node to rear of queue
    q->rear = temp;
    q->size ++;
  }
}

int dequeue(queue *q) {
  assert(empty(q)==false); //the queue cant be empty
  int data = q->front->data;
  q->front = q->front->next; //dequeue the node
  q->size--;
  if (q->front == NULL) { //if front is now empty, then change rear to empty
    q->rear = NULL;
    q->size = 0;
  } 
  return data; //return the saved data from dequeued node
}

void test1(void) { //(A)
    queue *q = malloc(sizeof(queue));
    init_queue(q); 
    if (empty(q)) { //test if empty
        printf("Test (A) Successful\n");
    } else {
        printf("Test (A) Failed\n");
    }
}

void test2(void) {
    queue *q = malloc(sizeof(queue));
    init_queue(q);
    enqueue(q,6); //add element
    dequeue(q);  //remove element

    if (empty(q)) { //test if empty
        printf("Test (B) Successful\n");
    } else {
        printf("Test (B) Failed\n");
    }
}

void test3(void) {
    int x_0 = 1, x_1 = 2, y_0 = 0, y_1 = 0;
    queue *q = malloc(sizeof(queue));
    init_queue(q);
    enqueue(q,x_0); 
    enqueue(q,x_1); 
    y_0 = dequeue(q);
    y_1 = dequeue(q);  
    if ((x_0 == y_0 && x_1 == y_1) && empty(q)) {
        printf("Test (C) Successful\n");
    } else {
        printf("Test (C) Failed\n");
    }
}
