#include "push_swap.h"
#include "libft.h"


void show_lst(t_list *head_a, t_list *head_b)
{
  t_list  *pa;
  t_list  *pb;

  pa = head_a;
  pb = head_b;
  printf("---a---\n");
  while(pa->next != head_a)
  {
    printf("%d\n", pa->value);
    pa = pa->next;
  }
  printf("%d\n", pa->value);
  printf("---b---\n");
  while(pb->next != head_b)
  {
    printf("%d\n", pb->value);
    pb = pb->next;
  }
  printf("%d\n", pb->value);
}

void show_struct(t_list *head_a, t_list *head_b)
{
  t_list *p;
  int flag = 1;

  
  printf("---a---\n");
  p = head_a;
  while( p != head_a || flag)
  {
    printf("value:%d\n", p->value);
    printf("own  :%p\n", p);
    printf("next :%p\n", p->next);
    printf("prev :%p\n", p->prev);
    p = p->next;
    flag = 0;
  }
  printf("---b---\n");
  flag = 1;
  p = head_b;
  while( p != head_b || flag)
  {
    printf("value:%d\n", p->value);
    printf("own  :%p\n", p);
    printf("next :%p\n", p->next);
    printf("prev :%p\n", p->prev);
    p = p->next;
    flag = 0;
  }
}

int main(int argc, char *argv[])
{
    t_list *head_a;
    t_list *head_b;

    head_a = ft_init_head(head_a);
    head_b = ft_init_head(head_b);
    if (!head_a || !head_b)
        return (-1);
    //aに引数でもらった数字を末尾からつける head->12->22->11

    int i1 = argc - 1;
    while (i1 > 0)
    {
        push(head_a, create_elem(ft_atoi(argv[i1])));
        i1--;
    }
  
    int *array;
    int i = 0;
    int lstsize;

    lstsize = ft_lstsize(head_a);
    show_lst(head_a, head_b);
    array = bubble_sort(change_array(head_a), ft_lstsize(head_a));
    while(lstsize--)
    {
      printf("array[%d]=%d\n", i, array[i]);
      i++;
    }
    printf("median:%d\n", calc_median(head_a, array));
    a_half_b(head_a, head_b);
    show_lst(head_a,head_b);
    b_half_a(head_a, head_b);
    show_lst(head_a, head_b);
    system("leaks a.out");
    return (0);
}

