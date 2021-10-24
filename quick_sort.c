#include "push_swap.h"
#include "libft.h"

int  half_a_to_b(t_list *head_a, t_list *head_b, t_list *head_o)
{
  int *array;
  int median;
  t_list *p;
  int i;
  int count;

  array = bubble_sort(change_array(head_a), ft_lstsize(head_a));
  median = calc_median(head_a, array);
  ft_3free(array, NULL, NULL);
  p = head_a->next;
  i = ft_lstsize(head_a);
  count = 0;
  while(i-- > 0)
  {
    if(p->value < median)
    {
      p = p->next;
      push_b(head_a, head_b, head_o);
      count++;
    }
    else
    {
      p = p->next;
      rotate_a(head_a, head_b, head_o);
    }
  }
  return(count);
}

int  half_b_to_a(t_list *head_a, t_list *head_b, t_list *head_o)
{
  int *array;
  int median;
  t_list *p;
  int i;
  int count;

  array = bubble_sort(change_array(head_b), ft_lstsize(head_b));
  median = calc_median(head_b, array);
  ft_3free(array, NULL, NULL);
  p = head_b->next;
  i = ft_lstsize(head_b);
  count = 0;
  while(i-- > 0)
  {
    if(p->value < median)
    {
      p = p->next;
      rotate_b(head_a, head_b, head_o);
    }
    else
    {
      p = p->next;
      push_a(head_a, head_b, head_o);
      count++;
    }
  }
  return (count);
}

void  count_a_to_b(t_list *head_a, t_list *head_b, int  count, t_list *head_o)
{
  int i;

  i = 0;
  while(i++ < count)
  {
    push_b(head_a, head_b, head_o);
  }
}

int quick_sort(t_list *head_a, t_list *head_b, t_list *head_o)
{
  int is_rule_num;
  int last_num;

  is_rule_num = ft_lstsize(head_b);
  if (is_rule_num <= 3)
  {
    rule_sort(head_a, head_b, is_rule_num, head_o);
    //show_lst(head_a, head_b);
    return (1);
  }
  last_num = half_b_to_a(head_a, head_b, head_o);
  //show_lst(head_a, head_b);
  quick_sort(head_a, head_b, head_o);
  //bは空
  count_a_to_b(head_a, head_b, last_num, head_o);
  //show_lst(head_a, head_b);
  quick_sort(head_a, head_b, head_o);

  return(1);
}

void sorting_start(t_list *head_a, t_list *head_b, t_list *head_o)
{
  int *answer_array;
  int count_a;

  if (ft_lstsize(head_a) <= 6)
  {
    six_rule_sort(head_a, head_b, ft_lstsize(head_a), head_o);
    return;
  }
  answer_array = bubble_sort(change_array(head_a), ft_lstsize(head_a));
  //show_lst(head_a, head_b);
  count_a = half_a_to_b(head_a, head_b, head_o);
  //show_lst(head_a, head_b);
  quick_sort(head_a, head_b, head_o);
  count_a_to_b(head_a, head_b, ft_lstsize(head_a) - count_a, head_o);
  //show_lst(head_a, head_b);
  quick_sort(head_a, head_b, head_o);
  //puts("\n");
  print_head_o(head_o);
  //show_lst(head_a, head_b);
  ft_3lstfree(head_a, head_b, head_o);
  ft_3free(answer_array, NULL, NULL);
}
