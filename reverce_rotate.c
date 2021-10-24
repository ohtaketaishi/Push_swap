#include "push_swap.h"
#include "libft.h"

void reverse_rotate_a(t_list *head_a, t_list *head_b, t_list *head_o)
{
  t_list *tail;

  tail = pop_tail(head_a);
  push(head_a, tail);
  push_tail(head_o, create_node(9));
  //puts("rra");
}

void reverse_rotate_b(t_list *head_a, t_list *head_b, t_list *head_o)
{
  t_list *tail;

  tail = pop_tail(head_b);
  push(head_b, tail);
  push_tail(head_o, create_node(10));
  //puts("rrb");
}

void  rreverse_rotate(t_list *head_a, t_list  *head_b, t_list *head_o)
{
  reverse_rotate_a(head_a, head_b, head_o);
  reverse_rotate_b(head_a, head_b, head_o);
  push_tail(head_o, create_node(11));
  //puts("rrr");
}
