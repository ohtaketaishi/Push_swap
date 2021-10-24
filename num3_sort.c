#include "push_swap.h"
#include "libft.h"

void    sort_123(t_list *head_a, t_list *head_b, t_list *head_o)
{
    push_a(head_a, head_b, head_o);
    rotate_a(head_a, head_b, head_o);
    push_a(head_a, head_b, head_o);
    rotate_a(head_a, head_b, head_o);
    push_a(head_a, head_b, head_o);
    rotate_a(head_a, head_b, head_o);
}

void    sort_321(t_list *head_a, t_list *head_b, t_list *head_o)
{
    rotate_b(head_a, head_b, head_o);
    swap_b(head_a, head_b, head_o);
    sort_123(head_a, head_b, head_o);
}

void    sort_312(t_list  *head_a, t_list *head_b, t_list *head_o)
{
    rotate_b(head_a, head_b, head_o);
    sort_123(head_a, head_b, head_o);
}

void    sort_132(t_list *head_a, t_list *head_b, t_list *head_o)
{
    push_a(head_a, head_b, head_o);
    rotate_a(head_a, head_b, head_o);
    rotate_b(head_a, head_b, head_o);
    push_a(head_a, head_b, head_o);
    rotate_a(head_a, head_b, head_o);
    push_a(head_a, head_b, head_o);
    rotate_a(head_a, head_b, head_o);
}

void    sort_231(t_list *head_a, t_list *head_b, t_list *head_o)
{
    reverse_rotate_b(head_a, head_b, head_o);
    sort_123(head_a, head_b, head_o);
}

void    sort_213(t_list *head_a, t_list *head_b, t_list *head_o)
{
  swap_b(head_a, head_b, head_o);
  sort_123(head_a, head_b, head_o);
}
