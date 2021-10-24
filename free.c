#include "push_swap.h"
#include "libft.h"

void    ft_lstfree(t_list *head)
{
    t_list  *p;
    t_list  *tmp;

    if (head)
    {
        p = head->next;
        while (p != head)
        {
            tmp = p->next;
            ft_3free(p, NULL, NULL);
            p = tmp;
        }
        ft_3free(head, NULL, NULL);
        head = NULL;
    }
}

void    ft_3lstfree(t_list *head_1, t_list *head_2, t_list *head_3)
{
  ft_lstfree(head_1);
  ft_lstfree(head_2);
  ft_lstfree(head_3);
}

void    ft_3free(void *p1, void *p2, void *p3)
{
    if (p1)
    {
        free(p1);
        p1 = NULL;
    }
    if (p2)
    {
        free(p2);
        p2 = NULL;
    }
    if (p3)
    {
        free(p3);
        p3 = NULL;
    }
}

void  malloc_check(void *p)
{
  if (!p)
  {
    write(2, "ERROR\n", 6);
    exit(1);
  }
}
