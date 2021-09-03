#include "push_swap.h"
#include "libft.h"


void swap_a(t_list *head_a)
{
    if (ft_lstsize(head_a) <= 2)
        return;
    t_list *node1;
    t_list *node2;

    node1 = pop(head_a);
    node2 = pop(head_a);
    push(head_a, node1);
    push(head_a, node2);
}

void swap_b(t_list *head_b)
{
    if (ft_lstsize(head_b) <= 2)
        return;
    t_list *node1;
    t_list *node2;

    node1 = pop(head_b);
    node2 = pop(head_b);
    push(head_b, node1);
    push(head_b, node2);
}

void sswap(t_list *head_a, t_list *head_b)
{
  swap_a(head_a);
  swap_b(head_b);
}
