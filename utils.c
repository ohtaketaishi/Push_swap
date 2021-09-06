#include "push_swap.h"
#include "libft.h"

t_list  *ft_init_head(t_list *head)
{
  head = (t_list *)malloc(sizeof(t_list));
  if (!head)
    return (NULL);
  head->value = 0;
  head->next = head;
  head->prev = head;
  return (head);
}

int ft_lstsize(t_list *head)
{
    int     count;
    t_list  *p;

    count = 0;
    p = head;
    while (p->next != head)
    {
        p = p->next;
        count++;
    }

    return (count);
}

t_list *search_tail(t_list *head)
{
    t_list *p = head;

    while (p->next != head)
        p = p->next;

    return (p);
}

t_list *create_elem(int value)
{
    t_list *elem;
    elem = (t_list *)malloc(sizeof(t_list));
    if (!elem)
        return(NULL);
    elem->value = value;
    elem->next = NULL;
    elem->prev = NULL;

    return (elem);
}

void push(t_list *head, t_list *elem)
{
    if (head->next == head)
    {
        head->next = elem;
        head->prev = elem;
        elem->next = head;
        elem->prev = head;
    }
    else
    {
        t_list *now = head->next;
        head->next = elem;
        elem->next = now;
        elem->prev = head;
        now->prev = elem;
    }
}

void push_tail(t_list *head, t_list *elem)
{
    t_list *tail = search_tail(head);
    //headしかない時でもok
    tail->next = elem;
    elem->next = head;
    elem->prev = tail;
    head->prev = elem;
}

t_list *pop(t_list *head)
{
    t_list *node1;

    node1 = head->next;
    if (node1 == head)
        return (NULL);
    else if (node1->next == head)
    {
        head->next = head;
        head->prev = head;
        return (node1);
    }
    else
    {
        head->next = node1->next;
        node1->next->prev = head;
        return (node1);
    }
}

t_list *pop_tail(t_list *head)
{
    t_list *tail;
    //headしかない時でもok
    tail = search_tail(head);
    head->prev = tail->prev;
    head->prev->next = head;

    return (tail);
}
