#include "push_swap.h"
#include "libft.h"

void  push_a(t_list *head_a, t_list *head_b, t_list *head_o)
{
  t_list  *node1;

  node1 = pop(head_b);
  push(head_a, node1);
  push_tail(head_o, create_node(4));
  //puts("pa");
}

void  push_b(t_list *head_a, t_list *head_b, t_list *head_o)
{
  t_list  *node1;

  node1 = pop(head_a);
  push(head_b, node1);
  push_tail(head_o, create_node(5));
  //puts("pb");
}
