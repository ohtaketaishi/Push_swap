#include "push_swap.h"
#include "libft.h"

void  a_half_b(t_list *head_a, t_list *head_b)
{
  int *array;
  int median;
  t_list *p;
  int i;

  array = bubble_sort(change_array(head_a), ft_lstsize(head_a));
  median = calc_median(head_a, array);
  p = head_a->next;
  i = ft_lstsize(head_a);
  while(i-- > 0)
  {
    if(p->value < median)
    {
      p = p->next;
      push_b(head_a, head_b);
    }
    else
    {
      p = p->next;
      rotate_a(head_a);
    }
  }
}

void  b_half_a(t_list *head_a, t_list *head_b)
{
  int *array;
  int median;
  t_list *p;
  int i;

  array = bubble_sort(change_array(head_b), ft_lstsize(head_b));
  median = calc_median(head_b, array);
  p = head_b->next;
  i = ft_lstsize(head_b);
  while(i-- > 0)
  {
    if(p->value < median)
    {
      p = p->next;
      rotate_b(head_b);
    }
    else
    {
      p = p->next;
      push_a(head_a, head_b);
    }
  }
}
