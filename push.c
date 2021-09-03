#include "push_swap.h"
#include "libft.h"

void  push_a(t_list *head_a, t_list *head_b)
{
  t_list  *node1;

  node1 = pop(head_b);
  push(head_a, node1);
}

void  push_b(t_list *head_a, t_list *head_b)
{
  t_list  *node1;

  node1 = pop(head_a);
  push(head_b, node1);
}
