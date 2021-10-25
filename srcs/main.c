/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:02:56 by otaishi           #+#    #+#             */
/*   Updated: 2021/10/25 18:15:36 by otaishi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//void	show_lst(t_list *head_a, t_list *head_b)
//{
//	t_list	*pa;
//	t_list	*pb;
//
//	pa = head_a;
//	pb = head_b;
//	printf("\n\n//==//== a //==//==\n");
//	while (pa->next != head_a)
//	{
//		pa = pa->next;
//		printf("%d, ", pa->value);
//	}
//	printf("\n//==//== b //==//==\n");
//	while (pb->next != head_b)
//	{
//		pb = pb->next;
//		printf("%d, ", pb->value);
//	}
//	puts("\n");
//}
//
//void	show_struct(t_list *head_a, t_list *head_b)
//{
//	t_list	*p;
//	int		flag;
//
//	flag = 1;
//	printf("---a---\n");
//	p = head_a;
//	while( p != head_a || flag)
//	{
//		printf("value:%d\n", p->value);
//		printf("own  :%p\n", p);
//		printf("next :%p\n", p->next);
//		printf("prev :%p\n", p->prev);
//		p = p->next;
//		flag = 0;
//	}
//	printf("---b---\n");
//	flag = 1;
//	p = head_b;
//	while( p != head_b || flag)
//	{
//		printf("value:%d\n", p->value);
//		printf("own  :%p\n", p);
//		printf("next :%p\n", p->next);
//		printf("prev :%p\n", p->prev);
//		p = p->next;
//		flag = 0;
//	}
//}

int	main(int argc, char *argv[])
{
	t_list	*head_a;
	t_list	*head_b;
	t_list	*head_o;

	if (argc == 1)
		return (0);
	head_a = ft_init_head();
	head_b = ft_init_head();
	head_o = ft_init_head();
	if (check_num(argc, argv) || argv_to_lst(head_a, head_b, argv, argc)
		|| check_dup(head_a))
	{
		ft_3lstfree(head_a, head_b, head_o);
		write(2, "ERROR\n", 6);
		return (-1);
	}
	if (check_sorted(head_a, head_b, head_o))
		return (0);
	sorting_start(head_a, head_b, head_o);
	system("leaks a.out");
	return (0);
}
