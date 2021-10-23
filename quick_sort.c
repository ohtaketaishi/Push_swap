#include "push_swap.h"
#include "libft.h"

int  half_a_to_b(t_list *head_a, t_list *head_b, int *operation)
{
  int *array;
  int median;
  t_list *p;
  int i;
  int count;

  array = bubble_sort(change_array(head_a), ft_lstsize(head_a));
  median = calc_median(head_a, array);
  ft_free(array);
  p = head_a->next;
  i = ft_lstsize(head_a);
  count = 0;
  while(i-- > 0)
  {
    if(p->value < median)
    {
      p = p->next;
      push_b(head_a, head_b, operation);
      count++;
    }
    else
    {
      p = p->next;
      rotate_a(head_a, operation);
    }
  }
  return(count);
}

int  half_b_to_a(t_list *head_a, t_list *head_b, int *operation)
{
  int *array;
  int median;
  t_list *p;
  int i;
  int count;

  array = bubble_sort(change_array(head_b), ft_lstsize(head_b));
  median = calc_median(head_b, array);
  ft_free(array);
  p = head_b->next;
  i = ft_lstsize(head_b);
  count = 0;
  while(i-- > 0)
  {
    if(p->value < median)
    {
      p = p->next;
      rotate_b(head_b, operation);
    }
    else
    {
      p = p->next;
      push_a(head_a, head_b, operation);
      count++;
    }
  }
  return (count);
}

void  count_a_to_b(t_list *head_a, t_list *head_b, int  count, int *operation)
{
  int i;

  i = 0;
  while(i++ < count)
  {
    push_b(head_a, head_b, operation);
  }
}
