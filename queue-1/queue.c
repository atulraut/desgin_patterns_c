#include "queue.h"

void queue_init (struct queue * const this_ptr,
		 int (*isFullFunc) (struct queue * const this_ptr),
		 int (*isEmptyFunc) (struct queue *const this_ptr),
		 int (*getSizeFunc) (struct queue *const this_ptr),
		 void (*insertFunc) (struct queue *const this_ptr, int k),
		 int (*removeFunc) (struct queue *const this_ptr))
{
  this_ptr->head = 0;
  this_ptr->tail = 0;
  this_ptr->size = 0;
  /***
      initialize member function pointers
   */
  this_ptr->isFull = isFullFunc;
  this_ptr->isEmpty = isEmptyFunc;
  this_ptr->getSize = getSizeFunc;
  this_ptr->insert = insertFunc;
  this_ptr->removE = removeFunc;
}

void queue_cleanup(struct queue *this_ptr) {
  if(NULL != this_ptr) {
    free(this_ptr);
    this_ptr = NULL;
  }
}

/* Operations */
int isFull (struct queue * const this_ptr) {
  return (this_ptr->head+1) % Q_SIZE == this_ptr->tail;
}

int isEmpty (struct queue *const this_ptr) {
  return (this_ptr->head == this_ptr->tail);
}

int getSize (struct queue *const this_ptr) {
  return this_ptr->size;
}

void insert (struct queue *const this_ptr, int k) {
  if (!this_ptr->isFull(this_ptr)) {
    this_ptr->buffer[this_ptr->head] = k;
    this_ptr->head = (this_ptr->head+1) % Q_SIZE;
    ++this_ptr->size;
  }
}

int removE (struct queue *const this_ptr) {
  int value = -999; /* sentinel value */
  if (!this_ptr->isEmpty(this_ptr)) {
    value = this_ptr->buffer[this_ptr->tail];
    this_ptr->tail = (this_ptr->tail+1) % Q_SIZE;
    --this_ptr->size;
  }
  return value;
}

struct queue * queue_create(void) {
  struct queue *this_ptr = (struct queue*)malloc(sizeof(struct queue));
  if (this_ptr != NULL) {
    queue_init(this_ptr, isFull,
	       isEmpty,
	       getSize,
	       insert,
	       removE);
  }
  return this_ptr;
}

void queue_destroy(struct queue *this_ptr) {
  if (this_ptr != NULL) {
    queue_cleanup(this_ptr);
  }
}
