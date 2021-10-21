#include "push_swap.h"
#include "libft.h"

int *change_array(t_list  *head)
{
  int *array;
  int i;
  t_list  *p;

  i = 0;
  p = head->next;
  array = (int *)malloc((ft_lstsize(head)) * sizeof(int));

  while(p->next != head)
  {
    array[i++] = p->value;
    p = p->next;
  }
  array[i] = p->value;
  return (array);
}

void  bubble_swap(int *x, int *y)
{
  int tmp;

  tmp = *x;
  *x = *y;
  *y = tmp;
}

int *bubble_sort(int  array[], int array_size)
{
  int i;
  int j;

  i = 0;
  while(i < array_size -1)
  {
    j = array_size - 1;
    while(j > i)
    {
      //右から小さいのを左に持っていく
      if (array[j-1] > array[j])
      {
        bubble_swap(&array[j-1], &array[j]);
      }
      j--;
    }
    i++;
  }
  return (array);
}

int calc_median(t_list *head, int *array)
{
  int i;
  int median;

  i = ft_lstsize(head) / 2.0;
  median = array[i];
  return(median);
}
