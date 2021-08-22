#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedf  struct s_list {
    int value;
    struct s_list   *next;
    struct s_list   *prev;
}   t_list;

//swap.c
void    swap_a(t_list *head);
void    swap_b(t_list *head);

#endif
