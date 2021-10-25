/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:14:28 by otaishi           #+#    #+#             */
/*   Updated: 2021/10/26 02:08:17 by ootaketai        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_head_o(t_list *head_o)
{
	t_list	*p;

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
