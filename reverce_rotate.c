#include "push_swap.h"
#include "libft.h"

void reverse_rotate_a(t_list *head_a, int *operation)
{
  t_list *tail;

  tail = pop_tail(head_a);
  push(head_a, tail);
  add_operation(operation, 9);
  //puts("rra");
}

void reverse_rotate_b(t_list *head_b, int *operation)
{
  t_list *tail;

  tail = pop_tail(head_b);
  push(head_b, tail);
  add_operation(operation, 10);
  //puts("rrb");
}

void  rreverse_rotate(t_list *head_a, t_list  *head_b, int *operation)
{
  reverse_rotate_a(head_a, operation);
  reverse_rotate_b(head_b, operation);
  add_operation(operation, 11);
  //puts("rrr");
}
