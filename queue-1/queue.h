#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdio.h>
#include <stdlib.h>

#define Q_SIZE 10

/***
    class queue
 */

struct queue {
  int buffer[Q_SIZE];
  int head;
  int tail;
  int size;
  int (*isFull) (struct queue * const this_ptr);
  int (*isEmpty) (struct queue *const this_ptr);
  int (*getSize) (struct queue *const this_ptr);
  void (*insert) (struct queue *const this_ptr, int k);
  int (*removE) (struct queue *const this_ptr);
};

/***
    constructor's & destructor's
 */

void queue_init (struct queue * const me,
		 int (*isFullFunc) (struct queue * const this_ptr),
		 int (*isEmptyFunc) (struct queue *const this_ptr),
		 int (*getSizeFunc) (struct queue *const this_ptr),
		 void (*insertFunc) (struct queue *const this_ptr, int k),
		 int (*removeFunc) (struct queue *const this_ptr)
  );

void queue_cleanup(struct queue *this);

/* Operations */
  int isFull (struct queue * const this_ptr);
  int isEmpty (struct queue *const this_ptr);
  int getSize (struct queue *const this_ptr);
  void insert (struct queue *const this_ptr, int k);
  int removE (struct queue *const this_ptr);

struct queue * queue_create(void);
void queue_destroy(struct queue *this_ptr);

#endif
