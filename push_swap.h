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
void swap_a(t_list *head_a);
void swap_b(t_list *head_b);
void sswap(t_list *head_a, t_list *head_b);
//push.c
void  push_a(t_list *head_a, t_list *head_b);
void  push_b(t_list *head_a, t_list *head_b);
//rotate.c
void rotate_a(t_list *head_a);
void rotate_b(t_list *head_b);
void rrotate(t_list *head_a, t_list *head_b);
//reverce_rotate.c
void reverse_rotate_a(t_list *head_a);
void reverse_rotate_b(t_list *head_b);
void  rreverse_rotate(t_list *head_a, t_list  *head_b);
//utils.c
void    ft_init_head(t_list *head);
int ft_lstsize(t_list *head);
t_list *search_tail(t_list *head);
t_list *create_elem(int value);
void push(t_list *head, t_list *elem);
void push_tail(t_list *head, t_list *elem);
t_list *pop(t_list *head);
t_list *pop_tail(t_list *head);
#endif
