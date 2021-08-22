#include "push_swap.h"


void swap_a(t_list *head)
{
    if (ft_lstsize(head) <= 2)
        return;
    t_list *node1;
    t_list *node2;

    node1 = pop(head);
    node2 = pop(head);
    push(head, node1);
    push(head, node2);
}

void swap_b(t_list *head)
{
    if (ft_lstsize(head) <= 2)
        return;
    t_list *node1;
    t_list *node2;

    node1 = pop(head);
    node2 = pop(head);
    push(head, node1);
    push(head, node2);
}
