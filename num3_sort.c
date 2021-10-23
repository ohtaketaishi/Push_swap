#include "push_swap.h"
#include "libft.h"

void    sort_123(t_list *head_a, t_list *head_b, int *operation)
{
    push_a(head_a, head_b, operation);
    rotate_a(head_a, operation);
    push_a(head_a, head_b, operation);
    rotate_a(head_a, operation);
    push_a(head_a, head_b, operation);
    rotate_a(head_a, operation);
}

void    sort_321(t_list *head_a, t_list *head_b, int *operation)
{
    rotate_b(head_b, operation);
    swap_b(head_b, operation);
    sort_123(head_a, head_b, operation);
}

void    sort_312(t_list  *head_a, t_list *head_b, int *operation)
{
    rotate_b(head_b, operation);
    sort_123(head_a, head_b, operation);
}

void    sort_132(t_list *head_a, t_list *head_b, int *operation)
{
    push_a(head_a, head_b, operation);
    rrotate(head_a, head_b, operation);
    push_a(head_a, head_b, operation);
    rotate_a(head_a, operation);
    push_a(head_a, head_b, operation);
    rotate_a(head_a, operation);
}

void    sort_231(t_list *head_a, t_list *head_b, int *operation)
{
    reverse_rotate_b(head_b, operation);
    sort_123(head_a, head_b, operation);
}
