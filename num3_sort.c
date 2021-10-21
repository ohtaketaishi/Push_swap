#include "push_swap.h"
#include "libft.h"

void    sort_123(t_list *head_a, t_list *head_b)
{
    push_a(head_a, head_b);
    rotate_a(head_a);
    push_a(head_a, head_b);
    rotate_a(head_a);
    push_a(head_a, head_b);
    rotate_a(head_a);
}

void    sort_321(t_list *head_a, t_list *head_b)
{
    rotate_b(head_b);
    swap_b(head_b);
    sort_123(head_a, head_b);
}

void    sort_312(t_list  *head_a, t_list *head_b)
{
    rotate_b(head_b);
    sort_123(head_a, head_b);
}

void    sort_132(t_list *head_a, t_list *head_b)
{
    push_a(head_a, head_b);
    rrotate(head_a, head_b);
    push_a(head_a, head_b);
    rotate_a(head_a);
    push_a(head_a, head_b);
    rotate_a(head_a);
}

void    sort_231(t_list *head_a, t_list *head_b)
{
    reverse_rotate_b(head_b);
    sort_123(head_a, head_b);
}
