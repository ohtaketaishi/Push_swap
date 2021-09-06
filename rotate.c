#include "push_swap.h"
#include "libft.h"

void rotate_a(t_list *head_a)
{
    t_list *node1;

    node1 = pop(head_a);
   push_tail(head_a, node1);
}

void rotate_b(t_list *head_b)
{
    t_list *node1;

    node1 = pop(head_b);
   push_tail(head_b, node1);
}

void rrotate(t_list *head_a, t_list *head_b)
{
  rotate_a(head_a);
  rotate_b(head_b);
}
