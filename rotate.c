#include "push_swap.h"
#include "libft.h"

void rotate_a(t_list *head_a, int *operation)
{
  t_list *node1;

  node1 = pop(head_a);
  push_tail(head_a, node1);
  add_operation(operation, 6);
  //puts("ra");
}

void rotate_b(t_list *head_b, int *operation)
{
  t_list *node1;

  node1 = pop(head_b);
  push_tail(head_b, node1);
  add_operation(operation, 7);
  //puts("rb");
}

void rrotate(t_list *head_a, t_list *head_b, int *operation)
{
  rotate_a(head_a, operation);
  rotate_b(head_b, operation);
  add_operation(operation, 8);
  //puts("rr");
}
