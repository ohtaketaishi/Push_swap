/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:58:32 by otaishi           #+#    #+#             */
/*   Updated: 2021/10/25 17:59:04 by otaishi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list *head_a, t_list *head_b, t_list *head_o)
{
	t_list	*node1;

	head_b = (t_list *)head_b;
	node1 = pop(head_a);
	push_tail(head_a, node1);
	push_tail(head_o, create_node(6));
}

void	rotate_b(t_list *head_a, t_list *head_b, t_list *head_o)
{
	t_list	*node1;

	head_a = (t_list *)head_a;
	node1 = pop(head_b);
	push_tail(head_b, node1);
	push_tail(head_o, create_node(7));
}

void	rrotate(t_list *head_a, t_list *head_b, t_list *head_o)
{
	rotate_a(head_a, head_b, head_o);
	rotate_b(head_a, head_b, head_o);
	push_tail(head_o, create_node(8));
}
