/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverce_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:57:03 by otaishi           #+#    #+#             */
/*   Updated: 2021/10/25 17:58:09 by otaishi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_list *head_a, t_list *head_b, t_list *head_o)
{
	t_list	*tail;

	head_b = (t_list *)head_b;
	tail = pop_tail(head_a);
	push(head_a, tail);
	push_tail(head_o, create_node(9));
}

void	reverse_rotate_b(t_list *head_a, t_list *head_b, t_list *head_o)
{
	t_list	*tail;

	head_a = (t_list *)head_a;
	tail = pop_tail(head_b);
	push(head_b, tail);
	push_tail(head_o, create_node(10));
}

void	rreverse_rotate(t_list *head_a, t_list *head_b, t_list *head_o)
{
	reverse_rotate_a(head_a, head_b, head_o);
	reverse_rotate_b(head_a, head_b, head_o);
	push_tail(head_o, create_node(11));
}
