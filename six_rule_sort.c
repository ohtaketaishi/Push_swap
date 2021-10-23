#include "push_swap.h"
#include "libft.h"

void    six_num3_sort(t_list *head_a, t_list *head_b, int *operation)
{
    int  node1;
    int  node2;
    int  node3;

    node1 = head_a->next->value;
    node2 = head_a->next->next->value;
    node3 = head_a->next->next->next->value;

    //3 2 1
    if(node1 > node2 && node2 > node3)
    {
      swap_a(head_a, operation);
      reverse_rotate_a(head_a, operation);
    }
    //3 1 2
    if(node1 > node2 && node2 < node3 && node3 < node1)
      rotate_a(head_a, operation);
    //1 3 2
    if(node1 < node2 && node2 > node3 && node3 > node1)
    {
      swap_a(head_a, operation);
      rotate_a(head_a, operation);
    }
    //2 3 1
    if(node1 < node2 && node2 > node3 && node3 < node1)
      reverse_rotate_a(head_a, operation);
    //2 1 3
    if(node1 > node2 && node2 < node3 && node3 > node1)
      swap_a(head_a, operation);
}

void  six_rule_sort(t_list *head_a, t_list *head_b, int count, int *operation)
{
  if(count == 6)
    six_sort(head_a, head_b, operation);
  else if(count == 5)
    five_sort(head_a, head_b, operation);
  else if(count == 4)
    four_sort(head_a, head_b, operation);
  else if(count == 3)
    six_num3_sort(head_a, head_b, operation);
  else if(count == 2 && head_a->next->value > head_a->next->next->value)
      swap_a(head_a, operation);
  print_operation(operation);
  //show_lst(head_a, head_b);
  ft_lstfree(head_a);
  ft_lstfree(head_b);
  ft_free(operation, NULL, NULL);
}

void six_sort(t_list *head_a, t_list *head_b, int *operation)
{
  int *answer_array;
  int count;

  answer_array = bubble_sort(change_array(head_a), ft_lstsize(head_a));
  count = 0;
  while(count != 3)
  {
    if(head_a->next->value == answer_array[count])
    {
      push_b(head_a, head_b, operation);
      count++;
    }
    rotate_a(head_a, operation);
  }
  if (ft_lstsize(head_a) == 3)
    six_num3_sort(head_a, head_b, operation);
  push_a(head_a, head_b, operation);
  push_a(head_a, head_b, operation);
  push_a(head_a, head_b, operation);
  ft_free(answer_array, NULL, NULL);
}

void five_sort(t_list *head_a, t_list *head_b, int *operation)
{
  int *answer_array;
  int count;

  answer_array = bubble_sort(change_array(head_a), ft_lstsize(head_a));
  count = 0;
  while(count != 2)
  {
    if(head_a->next->value == answer_array[count])
    {
      push_b(head_a, head_b, operation);
      count++;
    }
    rotate_a(head_a, operation);
  }
  if (ft_lstsize(head_a) == 3)
    six_num3_sort(head_a, head_b, operation);
  push_a(head_a, head_b, operation);
  push_a(head_a, head_b, operation);
  ft_free(answer_array, NULL, NULL);
}

void four_sort(t_list *head_a, t_list *head_b, int *operation)
{
  int *answer_array;
  int count;

  answer_array = bubble_sort(change_array(head_a), ft_lstsize(head_a));
  count = 0;
  while(count != 1)
  {
    if(head_a->next->value == answer_array[count])
    {
      push_b(head_a, head_b, operation);
      count++;
    }
    rotate_a(head_a, operation);
  }
  if (ft_lstsize(head_a) == 3)
    six_num3_sort(head_a, head_b, operation);
  push_a(head_a, head_b, operation);
  ft_free(answer_array, NULL, NULL);
}
