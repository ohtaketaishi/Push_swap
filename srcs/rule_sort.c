/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:11:27 by otaishi           #+#    #+#             */
/*   Updated: 2021/10/25 17:13:59 by otaishi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	num3_sort(t_list *head_a, t_list *head_b, t_list *head_o)
{
	int	node1;
	int	node2;
	int	node3;

	node1 = head_b->next->value;
	node2 = head_b->next->next->value;
	node3 = head_b->next->next->next->value;
	if (node1 < node2 && node2 < node3)
		sort_123(head_a, head_b, head_o);
	if (node1 > node2 && node2 > node3)
		sort_321(head_a, head_b, head_o);
	if (node1 > node2 && node2 < node3 && node3 < node1)
		sort_312(head_a, head_b, head_o);
	if (node1 < node2 && node2 > node3 && node3 > node1)
		sort_132(head_a, head_b, head_o);
	if (node1 < node2 && node2 > node3 && node3 < node1)
		sort_231(head_a, head_b, head_o);
	if (node1 > node2 && node2 < node3 && node3 > node1)
		sort_213(head_a, head_b, head_o);
}

void	num2_sort(t_list *head_a, t_list *head_b, t_list *head_o)
{
	int	node1;
	int	node2;

	node1 = head_b->next->value;
	node2 = head_b->next->next->value;
	if (node1 < node2)
	{
		push_a(head_a, head_b, head_o);
		rotate_a(head_a, head_b, head_o);
		push_a(head_a, head_b, head_o);
		rotate_a(head_a, head_b, head_o);
	}
	else
	{
		rotate_b(head_a, head_b, head_o);
		push_a(head_a, head_b, head_o);
		rotate_a(head_a, head_b, head_o);
		push_a(head_a, head_b, head_o);
		rotate_a(head_a, head_b, head_o);
	}
}

void	num1_sort(t_list *head_a, t_list *head_b, t_list *head_o)
{
	push_a(head_a, head_b, head_o);
	rotate_a(head_a, head_b, head_o);
}

void	rule_sort(t_list *head_a, t_list *head_b, int count, t_list *head_o)
{
	if (count <= 3)
	{
		if (count == 3)
			num3_sort(head_a, head_b, head_o);
		else if (count == 2)
			num2_sort(head_a, head_b, head_o);
		else
			num1_sort(head_a, head_b, head_o);
	}
}

void	sort_123(t_list *head_a, t_list *head_b, t_list *head_o)
{
	push_a(head_a, head_b, head_o);
	rotate_a(head_a, head_b, head_o);
	push_a(head_a, head_b, head_o);
	rotate_a(head_a, head_b, head_o);
	push_a(head_a, head_b, head_o);
	rotate_a(head_a, head_b, head_o);
}
