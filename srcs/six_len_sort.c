/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   six_len_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:59:33 by otaishi           #+#    #+#             */
/*   Updated: 2021/11/18 00:46:54 by ootaketai        ###   ########.fr       */
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
	if (count == 6 || count == 5 || count == 4)
		six_sort(head_a, head_b, head_o);
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

	answer_array = bubble_sort(change_array(head_a), ft_lstsize(head_a));
	high_low(head_a, head_b, head_o, answer_array);
	ft_3free(answer_array, NULL, NULL);
	if (ft_lstsize(head_a) == 3)
		six_num3_sort(head_a, head_b, head_o);
	while (ft_lstsize(head_b))
		push_a(head_a, head_b, head_o);
}

void	high_low(t_list *head_a, t_list *head_b, t_list *head_o,
int *answer_array)
{
	int		count;

	count = 0;
	while (ft_lstsize(head_a) > 3)
	{
		if (check_high_low(head_a, answer_array[count]))
		{
			if (head_a->next->value == answer_array[count])
				count += push_b_plus(head_a, head_b, head_o);
			else
				rotate_a(head_a, head_b, head_o);
		}
		else
		{
			if (!(head_a->next->value == answer_array[count]))
				reverse_rotate_a(head_a, head_b, head_o);
			else
				count += push_b_plus(head_a, head_b, head_o);
		}
	}
}

int	check_high_low(t_list *head_a, int min)
{
	int		i;
	t_list	*p;

	i = 0;
	p = head_a->next;
	while (p->next != head_a)
	{
		if ((p->value == min)
			&& i + 1 <= (ft_lstsize(head_a) + 1) / 2)
			return (1);
		i++;
		p = p->next;
	}
	return (0);
}
