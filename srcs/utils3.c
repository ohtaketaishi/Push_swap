/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:11:52 by otaishi           #+#    #+#             */
/*   Updated: 2021/10/26 02:14:46 by ootaketai        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*change_array(t_list *head)
{
	int		*array;
	int		i;
	t_list	*p;

	p = head->next;
	i = 0;
	array = (int *)malloc((ft_lstsize(head)) * sizeof(int));
	malloc_check(array);
	while (p != head)
	{
		array[i] = p->value;
		p = p->next;
		i++;
	}
	return (array);
}

void	bubble_swap(int *x, int *y)
{
	int	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

int	*bubble_sort(int array[], int array_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < array_size - 1)
	{
		j = array_size - 1;
		while (j > i)
		{
			if (array[j - 1] > array[j])
			{
				bubble_swap(&array[j - 1], &array[j]);
			}
			j--;
		}
		i++;
	}
	return (array);
}

int	calc_median(t_list *head, int *array)
{
	int	i;
	int	median;

	i = ft_lstsize(head) / 2.0;
	median = array[i];
	return (median);
}
