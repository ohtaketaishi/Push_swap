#include "push_swap.h"
#include "libft.h"

int  half_a_to_b(t_list *head_a, t_list *head_b)
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
      push_b(head_a, head_b);
      count++;
    }
    else
    {
      p = p->next;
      rotate_a(head_a);
    }
  }
  return(count);
}

int  half_b_to_a(t_list *head_a, t_list *head_b)
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
      rotate_b(head_b);
    }
    else
    {
      p = p->next;
      push_a(head_a, head_b);
      count++;
    }
  }
  return (count);
}

void  count_a_to_b(t_list *head_a, t_list *head_b, int  count)
{
  int i;

  i = 0;
  while(i++ < count)
  {
    push_b(head_a, head_b);
  }
}

//int quick_sort(t_list *head_a, t_list *head_b)
//{
//    b_count = ft_lstsize(head_b);
//    if(b_count <= 3)
//    {
//        if(b_count == 3)
//            3num_sort(head_a, head_b);
//        else if(b_count == 2)
//            2num_sort(head_a, head_b);
//        else
//            1num_sort(head_a, head_b);
//        return(b_count);
//    }
//    half_b_to_a(head_a, head_b);
//    quick_sort(head_a, head_b, b_count);
//
//    return(b_count);
//}
