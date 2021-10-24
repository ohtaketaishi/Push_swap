#include "push_swap.h"
#include "libft.h"

void    num3_sort(t_list *head_a, t_list *head_b, int *operation)
{
    int  node1;
    int  node2;
    int  node3;

    node1 = head_b->next->value;
    node2 = head_b->next->next->value;
    node3 = head_b->next->next->next->value;

    //1 2 3
    if(node1 < node2 && node2 < node3)
        sort_123(head_a, head_b, operation);
    //3 2 1
    if(node1 > node2 && node2 > node3)
        sort_321(head_a, head_b, operation);
    //3 1 2
    if(node1 > node2 && node2 < node3 && node3 < node1)
        sort_312(head_a, head_b, operation);
    //1 3 2
    if(node1 < node2 && node2 > node3 && node3 > node1)
        sort_132(head_a, head_b, operation);
    //2 3 1
    if(node1 < node2 && node2 > node3 && node3 < node1)
        sort_231(head_a, head_b, operation);
    //2 1 3
    if(node1 > node2 && node2 < node3 && node3 > node1)
      sort_213(head_a, head_b, operation);
}

void    num2_sort(t_list *head_a, t_list *head_b, int *operation)
{
    int  node1;
    int  node2;

    node1 = head_b->next->value;
    node2 = head_b->next->next->value;
    if(node1 < node2)
    {
        push_a(head_a, head_b, operation);
        rotate_a(head_a, operation);
        push_a(head_a, head_b, operation);
        rotate_a(head_a, operation);
    }
    else
    {
        rotate_b(head_b, operation);
        push_a(head_a, head_b, operation);
        rotate_a(head_a, operation);
        push_a(head_a, head_b, operation);
        rotate_a(head_a, operation);
    }
}

void    num1_sort(t_list *head_a, t_list *head_b, int *operation)
{
    push_a(head_a, head_b, operation);
    rotate_a(head_a, operation);
}

void  rule_sort(t_list *head_a, t_list *head_b, int count, int *operation)
{
      if(count <= 3)
    {
        if(count == 3)
            num3_sort(head_a, head_b, operation);
        else if(count == 2)
            num2_sort(head_a, head_b, operation);
        else
            num1_sort(head_a, head_b, operation);
    }
}
