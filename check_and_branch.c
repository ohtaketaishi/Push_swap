#include "push_swap.h"
#include "libft.h"

int check_num(int argc, char *argv[])
{
  int i;
  int j;

  i = 1;
  while (i < argc)
  {
    j = 0;
    if(argv[i][j] != '-' && (argv[i][j] < '0' || argv[i][j] > '9'))
      return(1);
    if(check_int(argv[i]))
      return(1);
    j++;
    while(argv[i][j])
    {
      if(argv[i][j] < '0' || argv[i][j] > '9')
        return(1);
      j++;
    }
    i++;
  }
  return(0);
}

int check_int(char *str)
{
  int sign;
  unsigned long long result;

  sign = 1;
  result = 0;
  while (*str == '\t' || *str == '\n' || *str == '\v'
      || *str == '\f' || *str == '\r' || *str == ' ')
    str++;
  if (*str == '+' || *str == '-')
  {
    if (*str == '-')
      sign = -1;
    str++;
  }
  if (*str == '0')
    return(1);
	while (*str)
	{
		result = 10 * result + *str - '0';
		str++;
		if (result > 2147483647 && !(sign == -1 && result == 2147483648))
      return (1);
	}
  return(0);
}

int check_dup(t_list *head_a)
{
  t_list *p;
  t_list *check_p;
  int count;

  p = head_a->next;
  while(p != head_a)
  {
    check_p = head_a->next;
    count = 0;
    while(check_p != head_a)
    {
      if(check_p->value == p->value)
        count++;
      check_p = check_p->next;
    }
    if (count >= 2)
      return(1);
    p = p->next;
  }
  return(0);
}

int argv_to_lst(t_list *head_a, t_list *head_b, char *argv[], int argc)
{
  t_list *p;
  int i;
  int j;


  i = argc - 1;
  while (i)
  {
    p = create_node(ft_atoi(argv[i]));
    if (!p)
      return(1);
    push(head_a, p);
    i--;
  }
  return (0);
}
