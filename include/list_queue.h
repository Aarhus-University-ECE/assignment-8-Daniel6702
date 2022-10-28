#ifndef __LIST_QUEUE_H_
#define __LIST_QUEUE_H_
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct qnode
{
  int data;
  struct qnode *next;
} qnode;

typedef struct queue
{
  int size;
  qnode *front;
  qnode *rear;
} queue;

void init_queue(queue *q);
int empty(queue *q);
void enqueue(queue *q, int x);
int dequeue(queue *q);
void test1(void);
void test2(void);
void test3(void);

#endif // __LIST_QUEUE_H_