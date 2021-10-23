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
  while(operation[i++] != 0)
  {
    if (operation[i] == 1)
      write(1, "sa, ", 4);
    else if(operation[i] == 2)
      write(1, "sb, ", 4);
    else if(operation[i] == 3)
      write(1, "ss, ", 4);
    else if(operation[i] == 4)
      write(1, "pa, ", 4);
    else if(operation[i] == 5)
      write(1, "pb, ", 4);
    else if(operation[i] == 6)
      write(1, "ra, ", 4);
    else if(operation[i] == 7)
      write(1, "ra, ", 4);
    else if(operation[i] == 7)
      write(1, "rr, ", 4);
    else if(operation[i] == 8)
      write(1, "rra, ", 5);
    else if(operation[i] == 9)
      write(1, "rrb, ", 5);
    else if(operation[i] == 10)
      write(1, "rrr, ", 5);

  }
 printf("\n\n\n*******%d*******\n", i);
}
