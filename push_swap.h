#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef  struct s_list {
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
t_list  *ft_init_head(t_list *head);
int ft_lstsize(t_list *head);
t_list *search_tail(t_list *head);
t_list *create_node(int value);
void push(t_list *head, t_list *node);
void push_tail(t_list *head, t_list *node);
t_list *pop(t_list *head);
t_list *pop_tail(t_list *head);
//back_sort.c
int *change_array(t_list  *head);
void  bubble_swap(int *x, int *y);
int *bubble_sort(int  array[], int array_size);
int calc_median(t_list *head, int *array);
//quick_sort.c
int  half_a_to_b(t_list *head_a, t_list *head_b);
int  half_b_to_a(t_list *head_a, t_list *head_b);
int quick_sort(t_list *head_a, t_list *head_b);
void  count_a_to_b(t_list *head_a, t_list *head_b, int count);
//free.c
void    ft_lstclear(t_list *head);
void    ft_free(int *p);
//rule_sort.c
void    num3_sort(t_list *head_a, t_list *head_b);
void    num2_sort(t_list *head_a, t_list *head_b);
void    num1_sort(t_list *head_a, t_list *head_b);
void  rule_sort(t_list *head_a, t_list *head_b, int count);
//3num_sort.c
void    sort_123(t_list *head_a, t_list *head_b);
void    sort_321(t_list *head_a, t_list *head_b);
void    sort_312(t_list  *head_a, t_list *head_b);
void    sort_132(t_list *head_a, t_list *head_b);
void    sort_231(t_list *head_a, t_list *head_b);
#endif
