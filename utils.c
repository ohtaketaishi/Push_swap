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

t_list *create_node(int value)
{
    t_list *node;
    node = (t_list *)malloc(sizeof(t_list));
    if (!node)
        return(NULL);
    node->value = value;
    node->next = NULL;
    node->prev = NULL;

    return (node);
}

void push(t_list *head, t_list *node)
{
  if (!node)
    return;
  if (head->next == head)
  {
      head->next = node;
      head->prev = node;
      node->next = head;
      node->prev = head;
  }
  else
  {
      t_list *now = head->next;
      head->next = node;
      node->next = now;
      node->prev = head;
      now->prev = node;
  }
}

void push_tail(t_list *head, t_list *node)
{
  if (!node)
    return;
    t_list *tail = search_tail(head);
    //headしかない時でもok
    tail->next = node;
    node->next = head;
    node->prev = tail;
    head->prev = node;
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
