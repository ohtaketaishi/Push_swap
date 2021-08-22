/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 11:48:08 by otaishi           #+#    #+#             */
/*   Updated: 2021/06/21 17:08:03 by ootaketai        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
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
	return (sign == 1 ? -1 : 0);
}
/*
#include <stdio.h>
int main()
{
	printf("%d\n", ft_atoi("99999999999999999999999999999999999999999999999999999"));
	printf("%d\n", ft_atoi("-9223372036854775808"));
	printf("%d\n", ft_atoi("92233720368547758077"));
	printf("%d\n", atoi("99999999999999999999999999999999999999999999999999999"));
	printf("%d\n", atoi("-9223372036854775808"));
	printf("%d\n", atoi("92233720368547758077"));
	return 0;
}
*/
