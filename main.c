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
  int *operation;

  head_a = ft_init_head(head_a);
  head_b = ft_init_head(head_b);
  operation = (int *)malloc(sizeof(int) * 10000);
  if (!head_a || !head_b || !operation)
    return (-1);
  ft_bzero(operation, sizeof(int) * 10000);

  int i1 = 0;
   while (i1 < argc - 1)
       push(head_a, create_node(ft_atoi(argv[argc - 1 - i1++])));
  //while (i1++ < 42)
    //push(head_a, create_node(i1));

  //quick_sort
  //==//==//==//==//==//==//==//==//==//== 
  int *array;
  int i = 0;
  int lstsize;
  int half_a_count;

  show_lst(head_a, head_b);
  lstsize = ft_lstsize(head_a);
  array = bubble_sort(change_array(head_a), ft_lstsize(head_a));
  half_a_count = half_a_to_b(head_a, head_b, operation);
  show_lst(head_a,head_b);
  quick_sort(head_a, head_b, operation);

  count_a_to_b(head_a, head_b, ft_lstsize(head_a) - half_a_count, operation);
  show_lst(head_a, head_b);
  quick_sort(head_a, head_b, operation);
  print_operation(operation);

  //最後に開放
  //==//==//==//==//==//==//==//==//==//== 
  ft_lstclear(head_a);
  ft_lstclear(head_b);
  system("leaks a.out");
  return (0);
}

//int quick_sort(t_list *head_a, t_list *head_b)
//{
//    int is_rule_num;
//    int last_num;
//
//    is_rule_num = ft_lstsize(head_b);
//    if (is_rule_num <= 3)
//      return (is_rule_num);
//    last_num = half_b_to_a(head_a, head_b);
//    show_lst(head_a, head_b);
//    is_rule_num = quick_sort(head_a, head_b, operation);
//
//    //3以下になったらソートしてaの末尾につける
//    rule_sort(head_a, head_b, is_rule_num);
//    show_lst(head_a, head_b);
//    //ここでbは空
//    num);
//    show_lst(head_a, head_b);
//    is_rule_num = quick_sort(head_a, head_b, operation);
//    rule_sort(head_a, head_b, is_rule_num);
//    show_lst(head_a, head_b);
//
//    return(is_rule_num);
//}

int quick_sort(t_list *head_a, t_list *head_b, int *operation)
{
  int is_rule_num;
  int last_num;

  is_rule_num = ft_lstsize(head_b);
  if (is_rule_num <= 3)
  {
    rule_sort(head_a, head_b, is_rule_num, operation);
    return (1);
  }
  last_num = half_b_to_a(head_a, head_b, operation);
  show_lst(head_a, head_b);
  quick_sort(head_a, head_b, operation);
  //bは空
  show_lst(head_a, head_b);
  count_a_to_b(head_a, head_b, last_num, operation);
  quick_sort(head_a, head_b, operation);
  show_lst(head_a, head_b);

  return(1);
}
