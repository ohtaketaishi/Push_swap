#include "push_swap.h"
#include "libft.h"

void    ft_lstclear(t_list *head)
{
    t_list  *p;
    t_list  *tmp;

    if (head)
    {
        p = head->next;
        while (p != head)
        {
            tmp = p->next;
            free(p);
            p = tmp;
        }
        free(head);
        head = NULL;
    }
}

void    ft_free(int *p)
{
    if (p)
    {
        free(p);
        p = NULL;
    }
}
