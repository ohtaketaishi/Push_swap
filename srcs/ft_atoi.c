/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:01:11 by otaishi           #+#    #+#             */
/*   Updated: 2021/10/25 17:01:27 by otaishi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_atoi(const char *str)
{
	unsigned long long		result;
	int						sign;

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
	while (ft_isdigit(*str))
	{
		result = 10 * result + *str - '0';
		str++;
		if (result > LLONG_MAX)
			break ;
	}
	if ((result == (unsigned long long)LLONG_MAX + 1 && sign == -1)
		|| result <= LLONG_MAX)
		return (sign * result);
	return (sign);
}
