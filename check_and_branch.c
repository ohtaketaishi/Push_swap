#include "push_swap.h"
#include "libft.h"

int check_arg(t_list *head_a)
{
  t_list *p;

  p = head_a->next;
  while(p != head_a)
  {
    if (p_value < -2147483648 || p_value > 2147483647)

    p = p->next;
  }
