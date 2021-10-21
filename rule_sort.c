#include "push_swap.h"
#include "libft.h"

void    num3_sort(t_list *head_a, t_list *head_b)
{
    int  node1;
    int  node2;
    int  node3;

    node1 = head_b->next->value;
    node2 = head_b->next->next->value;
    node3 = head_b->next->next->next->value;

    //1 2 3
    if(node1 < node2 && node2 < node3)
        sort_123(head_a, head_b);
    //3 2 1
    if(node1 > node2 && node2 > node1)
        sort_321(head_a, head_b);
    //3 1 2
    if(node1 > node2 && node2 < node3)
        sort_312(head_a, head_b);
    //1 3 2
    if(node1 < node2 && node2 > node3)
        sort_132(head_a, head_b);
    //2 3 1
    if(node1 < node2 && node2 > node3)
        sort_231(head_a, head_b);
}

void    num2_sort(t_list *head_a, t_list *head_b)
{
    int  node1;
    int  node2;

    node1 = head_b->next->value;
    node2 = head_b->next->next->value;
    if(node1 < node2)
    {
        push_a(head_a, head_b);
        rotate_a(head_a);
        push_a(head_a, head_b);
        rotate_a(head_a);
    }
    else
    {
        rotate_b(head_b);
        push_a(head_a, head_b);
        rotate_a(head_a);
        push_a(head_a, head_b);
        rotate_a(head_a);
    }
}

void    num1_sort(t_list *head_a, t_list *head_b)
{
    push_a(head_a, head_b);
    rotate_a(head_a);
}

void  rule_sort(t_list *head_a, t_list *head_b, int count)
{
      if(count <= 3)
    {
        if(count == 3)
            num3_sort(head_a, head_b);
        else if(count == 2)
            num2_sort(head_a, head_b);
        else
            num1_sort(head_a, head_b);
    }
}
