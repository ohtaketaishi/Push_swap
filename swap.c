#include "push_swap.h"
#include "libft.h"


void swap_a(t_list *head_a, t_list *head_b, t_list *head_o)
{
    if (ft_lstsize(head_a) <= 1)
        return;
    t_list *node1;
    t_list *node2;

    node1 = pop(head_a);
    node2 = pop(head_a);
    push(head_a, node1);
    push(head_a, node2);
    push_tail(head_o, create_node(1));
    //puts("sa");
}

void swap_b(t_list *head_a, t_list *head_b, t_list *head_o)
{
    if (ft_lstsize(head_b) <= 1)
        return;
    t_list *node1;
    t_list *node2;

    node1 = pop(head_b);
    node2 = pop(head_b);
    push(head_b, node1);
    push(head_b, node2);
    push_tail(head_o, create_node(2));
    //puts("sb");
}

void sswap(t_list *head_a, t_list *head_b, t_list *head_o)
{
  swap_a(head_a, head_b, head_o);
  swap_b(head_a, head_b, head_o);
  push_tail(head_o, create_node(3));
  //puts("ss");
}
