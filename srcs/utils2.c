/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:04:46 by otaishi           #+#    #+#             */
/*   Updated: 2021/10/25 18:11:42 by otaishi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list *head, t_list *node)
{
	t_list	*now;

	if (!node)
		return ;
	if (head->next == head)
	{
		head->next = node;
		head->prev = node;
		node->next = head;
		node->prev = head;
	}
	else
	{
		now = head->next;
		head->next = node;
		node->next = now;
		node->prev = head;
		now->prev = node;
	}
}

void	push_tail(t_list *head, t_list *node)
{
	t_list	*tail;

	if (!node)
		return ;
	tail = search_tail(head);
	tail->next = node;
	node->next = head;
	node->prev = tail;
	head->prev = node;
}

t_list	*pop(t_list *head)
{
	t_list	*node1;

	node1 = head->next;
	if (node1 == head)
		return (NULL);
	else if (node1->next == head)
	{
		head->next = head;
		head->prev = head;
		return (node1);
	}
	else
	{
		head->next = node1->next;
		node1->next->prev = head;
		return (node1);
	}
}

t_list	*pop_tail(t_list *head)
{
	t_list	*tail;

	tail = search_tail(head);
	head->prev = tail->prev;
	head->prev->next = head;
	return (tail);
}
