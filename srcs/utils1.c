/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:06:22 by otaishi           #+#    #+#             */
/*   Updated: 2021/10/25 18:09:26 by otaishi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_init_head(void)
{
	t_list	*head;

	head = (t_list *)malloc(sizeof(t_list));
	malloc_check(head);
	head->value = 0;
	head->next = head;
	head->prev = head;
	return (head);
}

int	ft_lstsize(t_list *head)
{
	int		count;
	t_list	*p;

	count = 0;
	p = head;
	while (p->next != head)
	{
		p = p->next;
		count++;
	}
	return (count);
}

t_list	*search_tail(t_list *head)
{
	t_list	*p;

	p = head;
	while (p->next != head)
		p = p->next;
	return (p);
}

t_list	*create_node(int value)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	malloc_check(node);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
