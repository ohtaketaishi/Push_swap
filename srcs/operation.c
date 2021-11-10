/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:14:28 by otaishi           #+#    #+#             */
/*   Updated: 2021/11/04 09:53:06 by ootaketai        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_head_o(t_list *head_o)
{
	t_list	*p;

	optimize_w(head_o);
	optimize_del(head_o);
	p = head_o->next;
	while (p != head_o)
	{
		print_sub(p->value);
		p = p->next;
	}
}

void	print_sub(int p_value)
{
	if (p_value == 1)
		write(1, "sa\n", 3);
	else if (p_value == 2)
		write(1, "sb\n", 3);
	else if (p_value == 3)
		write(1, "ss\n", 3);
	else if (p_value == 4)
		write(1, "pa\n", 3);
	else if (p_value == 5)
		write(1, "pb\n", 3);
	else if (p_value == 6)
		write(1, "ra\n", 3);
	else if (p_value == 7)
		write(1, "rb\n", 3);
	else if (p_value == 8)
		write(1, "rr\n", 3);
	else if (p_value == 9)
		write(1, "rra\n", 4);
	else if (p_value == 10)
		write(1, "rrb\n", 4);
	else if (p_value == 11)
		write(1, "rrr\n", 4);
}

void	optimize_w(t_list *head_o)
{
	t_list	*p;
	int		tmp;

	p = head_o->next;
	while(p != head_o)
	{
		if ((tmp == 1 && p->value == 2) || (tmp == 2 && p->value == 1))
		{
			del(p->prev);
			p->value = 3;
		}
		if ((tmp == 6 && p->value == 7) || (tmp == 7 && p->value == 6))
		{
			del(p->prev);
			p->value = 8;
		}
		if ((tmp == 9 && p->value == 10) || (tmp == 10 && p->value == 9))
		{
			del(p->prev);
			p->value = 11;
		}
		tmp = p->value;
		p = p->next;
	}
}

void	optimize_del(t_list *head_o)
{
	t_list	*p;
	int		tmp;

	p = head_o->next;
	while(p != head_o)
	{
		if ((tmp == 4 && p->value == 5) || (tmp == 5 && p->value == 4))
		{
			del(p->prev);
			del(p);
		}
		if ((tmp == 6 && p->value == 9) || (tmp == 9 && p->value == 6))
		{
			del(p->prev);
			del(p);
		}
		if ((tmp == 7 && p->value == 10) || (tmp == 10 && p->value == 7))
		{
			del(p->prev);
			del(p);
		}
		tmp = p->value;
		p = p->next;
	}
}
