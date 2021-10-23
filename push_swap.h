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
void swap_a(t_list *head_a, int *operation);
void swap_b(t_list *head_b, int *operation);
void sswap(t_list *head_a, t_list *head_b, int *operation);
//push.c
void  push_a(t_list *head_a, t_list *head_b, int *operation);
void  push_b(t_list *head_a, t_list *head_b, int *operation);
//rotate.c
void rotate_a(t_list *head_a, int *operation);
void rotate_b(t_list *head_b, int *operation);
void rrotate(t_list *head_a, t_list *head_b, int *operation);
//reverce_rotate.c
void reverse_rotate_a(t_list *head_a, int *operation);
void reverse_rotate_b(t_list *head_b, int *operation);
void  rreverse_rotate(t_list *head_a, t_list  *head_b, int *operation);
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
int  half_a_to_b(t_list *head_a, t_list *head_b, int *operation);
int  half_b_to_a(t_list *head_a, t_list *head_b, int *operation);
int quick_sort(t_list *head_a, t_list *head_b, int *operation);
void  count_a_to_b(t_list *head_a, t_list *head_b, int count, int *operation);
void sorting_start(t_list *head_a, t_list *head_b, int *operation);
//free.c
void    ft_lstfree(t_list *head);
void    ft_free(void *p1, void *p2, void *p3);
//rule_sort.c
void    num3_sort(t_list *head_a, t_list *head_b, int *operation);
void    num2_sort(t_list *head_a, t_list *head_b, int *operation);
void    num1_sort(t_list *head_a, t_list *head_b, int *operation);
void  rule_sort(t_list *head_a, t_list *head_b, int count, int *operation);
//3num_sort.c
void    sort_123(t_list *head_a, t_list *head_b, int *operation);
void    sort_321(t_list *head_a, t_list *head_b, int *operation);
void    sort_312(t_list  *head_a, t_list *head_b, int *operation);
void    sort_132(t_list *head_a, t_list *head_b, int *operation);
void    sort_231(t_list *head_a, t_list *head_b, int *operation);
void    sort_213(t_list *head_a, t_list *head_b, int *operation);
//operation.c
void  add_operation(int *operation, int num);
void  print_operation(int *operation);
//check_and_branch.c
int check_num(int argc, char *argv[]);
int check_int(char *str);
int check_dup(t_list *head_a);
int argv_to_lst(t_list *head_a, t_list *head_b, char *argv[], int argc);
//main.c
void show_lst(t_list *head_a, t_list *head_b);
void show_struct(t_list *head_a, t_list *head_b);

#endif
