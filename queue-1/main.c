#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main () {
  int j, k, h, t;

  struct queue *this_ptr;
  this_ptr = queue_create();
  
  k = 1000;
  for (j=0; j<Q_SIZE; j++) {
    h = this_ptr->head;
    this_ptr->insert(this_ptr, k);
    printf ("[%s] Inserting %d at position %d, size = %d \n", __func__, k--, h, this_ptr->getSize(this_ptr));
  }

  printf ("[%s] Inserted %d elements \n", __func__, this_ptr->getSize(this_ptr));

  for(j=0; j<Q_SIZE; j++) {
    t = this_ptr->tail;
    k = this_ptr->removE(this_ptr);
    printf ("[%s] Removing %d at position %d, size = %d \n", __func__, k, t, this_ptr->getSize(this_ptr));
  }

  printf ("[%s] Last ite removed = %d \n", __func__, k);

  printf ("[%s] Current Queue size = %d \n", __func__, this_ptr->getSize(this_ptr));

  queue_destroy(this_ptr);
  return 0;
} 
