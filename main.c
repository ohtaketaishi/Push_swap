#include "push_swap.h"
#include "libft.h"

int main(int argc, char *argv[])
{
    t_list *head_a;
    t_list *head_b;

    head_a = (t_list *)malloc(sizeof(t_list));
    head_b = (t_list *)malloc(sizeof(t_list));
    if (!head_a || !head_b)
        return (-1);
    //aとbのstackのheadを作成
    init_head(head_a);
    init_head(head_b);
    //aに引数でもらった数字を末尾からつける head->12->22->11

    printf("--------------------\n");
    printf("引数の数:%d\n", argc - 1);
    int i1 = argc - 1;
    while (i1 > 0)
    {
        push(head_a, create_elem(ft_atoi(argv[i1])));
        i1--;
    }
    printf("--------------------\n");
    t_list *now;
    int i2= 0;
    now = head_a;
    printf("--------\n");
    while(!(now == head_a) || !i2)
    {
        printf("   %d   \n", now->value);
        //	printf("---%d---\n", i2);
        //	printf("value[%d]\n", now->value);
        //	printf("this[%p]\n", now);
        //	printf("next[%p]\n", now->next);
        //	printf("prev[%p]\n", now->prev);
        //	printf("---%d---\n", i2);
        i2++;
        now = now->next;
    }
    printf("   %d   \n", now->value);
    printf("--------\n");
    //system("leaks a.out");
    return (0);
}
