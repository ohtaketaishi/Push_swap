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
  puts("\n");
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

  if (argc == 1)
    return(0);
  head_a = ft_init_head(head_a);
  head_b = ft_init_head(head_b);
  operation = (int *)malloc(sizeof(int) * 100000);
  if (argc == 1 || !head_a || !head_b || !operation || check_num(argc, argv))
  {
    ft_lstfree(head_a);
    ft_lstfree(head_b);
    ft_free(operation, NULL, NULL);
    write(2, "ERROR\n", 6);
    return (-1);
  }
  ft_bzero(operation, sizeof(int) * 100000);

  if (argv_to_lst(head_a, head_b, argv, argc) || check_dup(head_a))
  {
    ft_free(operation, NULL, NULL);
    ft_lstfree(head_a);
    ft_lstfree(head_b);
    write(2, "ERROR\n", 6);
    return(-1);
  }
  if (check_sorted(head_a, head_b, operation))
    return (0);
  //show_lst(head_a, head_b);
  sorting_start(head_a, head_b, operation);
  //system("leaks a.out");
  return (0);
}
