/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:31:00 by otaishi           #+#    #+#             */
/*   Updated: 2021/11/18 00:46:42 by ootaketai        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_list *head_a, t_list *head_b, t_list *head_o)
{
	t_list	*node1;

	node1 = pop(head_b);
	push(head_a, node1);
	push_tail(head_o, create_node(4));
}

void	push_b(t_list *head_a, t_list *head_b, t_list *head_o)
{
	t_list	*node1;

	node1 = pop(head_a);
	push(head_b, node1);
	push_tail(head_o, create_node(5));
}

int	push_b_plus(t_list *head_a, t_list *head_b, t_list *head_o)
{
	push_b(head_a, head_b, head_o);
	return (1);
}
