#include "push_swap.h"
#include "libft.h"

void rotate_a(t_list *head_a, t_list *head_b, t_list *head_o)
{
  t_list *node1;

  node1 = pop(head_a);
  push_tail(head_a, node1);
  push_tail(head_o, create_node(6));
  //puts("ra");
}

void rotate_b(t_list *head_a, t_list *head_b, t_list *head_o)
{
  t_list *node1;

  node1 = pop(head_b);
  push_tail(head_b, node1);
  push_tail(head_o, create_node(7));
  //puts("rb");
}

void rrotate(t_list *head_a, t_list *head_b, t_list *head_o)
{
  rotate_a(head_a, head_b, head_o);
  rotate_b(head_a, head_b, head_o);
  push_tail(head_o, create_node(8));
  //puts("rr");
}
