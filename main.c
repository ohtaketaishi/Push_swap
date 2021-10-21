#include "push_swap.h"
#include "libft.h"


void show_lst(t_list *head_a, t_list *head_b)
{
  t_list  *pa;
  t_list  *pb;

  pa = head_a;
  pb = head_b;
  printf("\n\n//==//== a //==//==\n");
  while(pa->next != head_a)
  {
    pa = pa->next;
    printf("%d, ", pa->value);
  }
  printf("\n//==//== b //==//==\n");
  while(pb->next != head_b)
  {
    pb = pb->next;
    printf("%d, ", pb->value);
  }
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
    //初期化
    //==//==//==//==//==//==//==//==//==//==
    //head_a head_bを確保してhead_aを引数で初期化
    //head->引数1->引数2->引数3
    t_list *head_a;
    t_list *head_b;
    head_a = ft_init_head(head_a);
    head_b = ft_init_head(head_b);
    if (!head_a || !head_b)
        return (-1);
    int i1 = 0;
   // while (i1 < argc - 1)
   //     push(head_a, create_node(ft_atoi(argv[argc - 1 - i1++])));
   while (i1++ < 20)
       push(head_a, create_node(i1));

    //quick_sort
    //==//==//==//==//==//==//==//==//==//== 
    int *array;
    int i = 0;
    int lstsize;

    show_lst(head_a, head_b);
    lstsize = ft_lstsize(head_a);
    array = bubble_sort(change_array(head_a), ft_lstsize(head_a));
    half_a_to_b(head_a, head_b);
    show_lst(head_a,head_b);
    quick_sort(head_a, head_b);

    //最後に開放
    //==//==//==//==//==//==//==//==//==//== 
    ft_lstclear(head_a);
    ft_lstclear(head_b);
    //system("leaks a.out");
    return (0);
}

int quick_sort(t_list *head_a, t_list *head_b)
{
    int b_count;

    b_count = ft_lstsize(head_b);
    if(b_count <= 3)
    {
        if(b_count == 3)
            num3_sort(head_a, head_b);
        else if(b_count == 2)
            num2_sort(head_a, head_b);
        else
            num1_sort(head_a, head_b);
        show_lst(head_a, head_b);
        return(b_count);
    }
    half_b_to_a(head_a, head_b);
    show_lst(head_a, head_b);
    quick_sort(head_a, head_b);

    return(b_count);
}



