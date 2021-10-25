/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:02:36 by otaishi           #+#    #+#             */
/*   Updated: 2021/10/25 18:03:53 by otaishi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list *head_a, t_list *head_b, t_list *head_o)
{
	t_list	*node1;
	t_list	*node2;

	head_b = (t_list *)head_b;
	if (ft_lstsize(head_a) <= 1)
		return ;
	node1 = pop(head_a);
	node2 = pop(head_a);
	push(head_a, node1);
	push(head_a, node2);
	push_tail(head_o, create_node(1));
}

void	swap_b(t_list *head_a, t_list *head_b, t_list *head_o)
{
	t_list	*node1;
	t_list	*node2;

	head_a = (t_list *)head_a;
	if (ft_lstsize(head_b) <= 1)
		return ;
	node1 = pop(head_b);
	node2 = pop(head_b);
	push(head_b, node1);
	push(head_b, node2);
	push_tail(head_o, create_node(2));
}

void	sswap(t_list *head_a, t_list *head_b, t_list *head_o)
{
	swap_a(head_a, head_b, head_o);
	swap_b(head_a, head_b, head_o);
	push_tail(head_o, create_node(3));
}
