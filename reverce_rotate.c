#include "push_swap.h"
#include "libft.h"

void reverse_rotate_a(t_list *head_a)
{
    t_list *tail;

    tail = pop_tail(head_a);
    push(head_a, tail);
}

void reverse_rotate_b(t_list *head_b)
{
    t_list *tail;

    tail = pop_tail(head_b);
    push(head_b, tail);
}

void  rreverse_rotate(t_list *head_a, t_list  *head_b)
{
  reverse_rotate_a(head_a);
  reverse_rotate_b(head_b);
}
