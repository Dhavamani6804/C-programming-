
#include <stdio.h>
#include <stdlib.h>

void fun(struct node* start)
{
  if(start == NULL)
    return;
  printf("%d  ", start->data); 
 
  if(start->next != NULL )
    fun(start->next->next);
  printf("%d ", start->data);
}
