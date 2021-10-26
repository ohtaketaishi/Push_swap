/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:56:11 by otaishi           #+#    #+#             */
/*   Updated: 2021/10/26 10:48:02 by otaishi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_num(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] != '-' && (argv[i][j] < '0' || argv[i][j] > '9'))
			return (1);
		if (check_int(argv[i]))
			return (1);
		j++;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_int(char *str)
{
	int					sign;
	unsigned long long	result;

	sign = 1;
	result = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if ((*str == '0' && *(str + 1) != '\0') || (*str == '0' && sign == -1))
		return (1);
	while (*str)
	{
		result = 10 * result + *str - '0';
		str++;
		if (result > 2147483647 && !(sign == -1 && result == 2147483648))
			return (1);
	}
	return (0);
}

int	check_dup(t_list *head_a)
{
	t_list	*p;
	t_list	*check_p;
	int		count;

	p = head_a->next;
	while (p != head_a)
	{
		check_p = head_a->next;
		count = 0;
		while (check_p != head_a)
		{
			if (check_p->value == p->value)
				count++;
			check_p = check_p->next;
		}
		if (count >= 2)
			return (1);
		p = p->next;
	}
	return (0);
}

int	argv_to_lst(t_list *head_a, t_list *head_b, char *argv[], int argc)
{
	t_list	*p;
	int		i;

	head_b = (t_list *)head_b;
	i = argc - 1;
	while (i)
	{
		p = create_node(ft_atoi(argv[i]));
		push(head_a, p);
		i--;
	}
	return (0);
}

int	check_sorted(t_list *head_a, t_list *head_b, t_list *head_o)
{
	int	i;
	int	count;
	int	*answer_array;
	int	*a_array;

	i = 0;
	count = 0;
	a_array = change_array(head_a);
	answer_array = bubble_sort(change_array(head_a), ft_lstsize(head_a));
	while (i != ft_lstsize(head_a))
	{
		if (answer_array[i] == a_array[i])
			count++;
		i++;
	}
	if (count == ft_lstsize(head_a))
	{
		ft_3lstfree(head_a, head_b, head_o);
		ft_3free(a_array, answer_array, NULL);
		return (1);
	}
	ft_3free(a_array, answer_array, NULL);
	return (0);
}
