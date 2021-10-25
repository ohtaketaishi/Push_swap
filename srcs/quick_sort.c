/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:47:53 by otaishi           #+#    #+#             */
/*   Updated: 2021/10/26 02:07:11 by ootaketai        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	half_a_to_b(t_list *head_a, t_list *head_b, t_list *head_o, int len_a)
{
	int		*array;
	int		median;
	int		count;
	t_list	*p;

	array = bubble_sort(change_array(head_a), ft_lstsize(head_a));
	median = calc_median(head_a, array);
	count = 0;
	p = head_a->next;
	while (len_a-- != 0)
	{
		if (p->value < median)
		{
			p = p->next;
			push_b(head_a, head_b, head_o);
			count++;
		}
		else
		{
			p = p->next;
			rotate_a(head_a, head_b, head_o);
		}
	}
	ft_3free(array, NULL, NULL);
	return (count);
}

int	half_b_to_a(t_list *head_a, t_list *head_b, t_list *head_o, int len_b)
{
	int		*array;
	int		median;
	int		count;
	t_list	*p;

	array = bubble_sort(change_array(head_b), ft_lstsize(head_b));
	median = calc_median(head_b, array);
	count = 0;
	p = head_b->next;
	while (len_b-- != 0)
	{
		if (p->value < median)
		{
			p = p->next;
			rotate_b(head_a, head_b, head_o);
		}
		else
		{
			p = p->next;
			push_a(head_a, head_b, head_o);
			count++;
		}
	}
	ft_3free(array, NULL, NULL);
	return (count);
}

void	count_a_to_b(t_list *head_a, t_list *head_b, int count, t_list *head_o)
{
	int	i;

	i = 0;
	while (i++ < count)
	{
		push_b(head_a, head_b, head_o);
	}
}

int	quick_sort(t_list *head_a, t_list *head_b, t_list *head_o)
{
	int	is_rule_num;
	int	last_num;

	is_rule_num = ft_lstsize(head_b);
	if (is_rule_num <= 3)
	{
		rule_sort(head_a, head_b, is_rule_num, head_o);
		return (1);
	}
	last_num = half_b_to_a(head_a, head_b, head_o, ft_lstsize(head_b));
	quick_sort(head_a, head_b, head_o);
	count_a_to_b(head_a, head_b, last_num, head_o);
	quick_sort(head_a, head_b, head_o);
	return (1);
}

void	sorting_start(t_list *head_a, t_list *head_b, t_list *head_o)
{
	int	*answer_array;
	int	count_a;

	if (ft_lstsize(head_a) <= 6)
	{
		six_rule_sort(head_a, head_b, ft_lstsize(head_a), head_o);
		return ;
	}
	answer_array = bubble_sort(change_array(head_a), ft_lstsize(head_a));
	count_a = half_a_to_b(head_a, head_b, head_o, ft_lstsize(head_a));
	quick_sort(head_a, head_b, head_o);
	count_a_to_b(head_a, head_b, ft_lstsize(head_a) - count_a, head_o);
	quick_sort(head_a, head_b, head_o);
	print_head_o(head_o);
	ft_3lstfree(head_a, head_b, head_o);
	ft_3free(answer_array, NULL, NULL);
}
