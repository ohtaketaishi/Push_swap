/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   six_len_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:59:33 by otaishi           #+#    #+#             */
/*   Updated: 2021/10/25 18:02:23 by otaishi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	six_num3_sort(t_list *head_a, t_list *head_b, t_list *head_o)
{
	int	node1;
	int	node2;
	int	node3;

	node1 = head_a->next->value;
	node2 = head_a->next->next->value;
	node3 = head_a->next->next->next->value;
	if (node1 > node2 && node2 > node3)
	{
		swap_a(head_a, head_b, head_o);
		reverse_rotate_a(head_a, head_b, head_o);
	}
	if (node1 > node2 && node2 < node3 && node3 < node1)
		rotate_a(head_a, head_b, head_o);
	if (node1 < node2 && node2 > node3 && node3 > node1)
	{
		swap_a(head_a, head_b, head_o);
		rotate_a(head_a, head_b, head_o);
	}
	if (node1 < node2 && node2 > node3 && node3 < node1)
		reverse_rotate_a(head_a, head_b, head_o);
	if (node1 > node2 && node2 < node3 && node3 > node1)
		swap_a(head_a, head_b, head_o);
}

void	six_rule_sort(t_list *head_a, t_list *head_b, int count, t_list *head_o)
{
	if (count == 6)
		six_sort(head_a, head_b, head_o);
	else if (count == 5)
		five_sort(head_a, head_b, head_o);
	else if (count == 4)
		four_sort(head_a, head_b, head_o);
	else if (count == 3)
		six_num3_sort(head_a, head_b, head_o);
	else if (count == 2 && head_a->next->value > head_a->next->next->value)
		swap_a(head_a, head_b, head_o);
	print_head_o(head_o);
	ft_3lstfree(head_a, head_b, head_o);
}

void	six_sort(t_list *head_a, t_list *head_b, t_list *head_o)
{
	int	*answer_array;
	int	count;

	answer_array = bubble_sort(change_array(head_a), ft_lstsize(head_a));
	count = 0;
	while (count != 3)
	{
		if (head_a->next->value == answer_array[count])
		{
			push_b(head_a, head_b, head_o);
			count++;
		}
		rotate_a(head_a, head_b, head_o);
	}
	if (ft_lstsize(head_a) == 3)
		six_num3_sort(head_a, head_b, head_o);
	push_a(head_a, head_b, head_o);
	push_a(head_a, head_b, head_o);
	push_a(head_a, head_b, head_o);
	ft_3free(answer_array, NULL, NULL);
}

void	five_sort(t_list *head_a, t_list *head_b, t_list *head_o)
{
	int	*answer_array;
	int	count;

	answer_array = bubble_sort(change_array(head_a), ft_lstsize(head_a));
	count = 0;
	while (count != 2)
	{
		if (head_a->next->value == answer_array[count])
		{
			push_b(head_a, head_b, head_o);
			count++;
		}
		rotate_a(head_a, head_b, head_o);
	}
	if (ft_lstsize(head_a) == 3)
		six_num3_sort(head_a, head_b, head_o);
	push_a(head_a, head_b, head_o);
	push_a(head_a, head_b, head_o);
	ft_3free(answer_array, NULL, NULL);
}

void	four_sort(t_list *head_a, t_list *head_b, t_list *head_o)
{
	int	*answer_array;
	int	count;

	answer_array = bubble_sort(change_array(head_a), ft_lstsize(head_a));
	count = 0;
	while (count != 1)
	{
		if (head_a->next->value == answer_array[count])
		{
			push_b(head_a, head_b, head_o);
			count++;
		}
		rotate_a(head_a, head_b, head_o);
	}
	if (ft_lstsize(head_a) == 3)
		six_num3_sort(head_a, head_b, head_o);
	push_a(head_a, head_b, head_o);
	ft_3free(answer_array, NULL, NULL);
}
