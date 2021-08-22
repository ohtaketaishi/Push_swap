#include "push_swap.h"
#include "libft.h"

void    ft_init_head(t_list *head)
{
    head->value = 0;
    head->next = head;
    head->prev = head;
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

void rotate(t_list *head)
{
    t_list *node1;

    node1 = pop(head);
   push_tail(head, node1);
}

void reverse_rotate(t_list *head)
{
    t_list *tail;

    tail = pop_tail(head);
    push(head, tail);
}

void num3_ver(t_list *head)
{
    int node1;
    int node2;
    int third;

    //	if (node1 > 

    //	if ();
}
//とりあえずpopとpushを作る

int main(int ac, char *av[])
{
    t_list *head_a;
    t_list *head_b;

    head_a = (t_list *)malloc(sizeof(t_list));
    head_b = (t_list *)malloc(sizeof(t_list));
    if (!head_a || !head_b)
        return (-1);
    //aとbのstackのheadを作成
    init_head(head_a);
    init_head(head_b);
    //aに引数でもらった数字を末尾からつける head->12->22->11

    printf("--------------------\n");
    printf("引数の数:%d\n", ac - 1);
    int i1 = ac - 1;
    while (i1 > 0)
    {
        push(head_a, create_elem(ft_atoi(av[i1])));
        i1--;
    }
    printf("--------------------\n");
    t_list *now;
    int i2= 0;
    now = head_a;
    printf("--------\n");
    while(!(now == head_a) || !i2)
    {
        printf("   %d   \n", now->value);
        //	printf("---%d---\n", i2);
        //	printf("value[%d]\n", now->value);
        //	printf("this[%p]\n", now);
        //	printf("next[%p]\n", now->next);
        //	printf("prev[%p]\n", now->prev);
        //	printf("---%d---\n", i2);
        i2++;
        now = now->next;
    }
    printf("   %d   \n", now->value);
    printf("--------\n");
    //system("leaks a.out");
    return (0);
}
