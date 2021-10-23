#include "push_swap.h"
#include "libft.h"

void  add_operation(int *operation, int num)
{
  int i;

  i = 0;
  while(operation[i] != 0)
    i++;
  operation[i] = num;
}

void  print_operation(int *operation)
{
  int i;

  i = 0;
  while(operation[i] != 0)
  {
    if (operation[i] == 1)
      write(1, "sa\n", 3);
    else if(operation[i] == 2)
      write(1, "sb\n", 3);
    else if(operation[i] == 3)
      write(1, "ss\n", 3);
    else if(operation[i] == 4)
      write(1, "pa\n", 3);
    else if(operation[i] == 5)
      write(1, "pb\n", 3);
    else if(operation[i] == 6)
      write(1, "ra\n", 3);
    else if(operation[i] == 7)
      write(1, "rb\n", 3);
    else if(operation[i] == 8)
      write(1, "rr\n", 3);
    else if(operation[i] == 9)
      write(1, "rra\n", 4);
    else if(operation[i] == 10)
      write(1, "rrb\n", 4);
    else if(operation[i] == 11)
      write(1, "rrr\n", 4);
    i++;

  }
}
