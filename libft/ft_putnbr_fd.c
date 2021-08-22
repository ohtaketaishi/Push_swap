/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 00:57:11 by otaishi           #+#    #+#             */
/*   Updated: 2020/10/19 18:09:07 by otaishi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	un_nbr;

	un_nbr = (unsigned int)n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		un_nbr = (unsigned int)(-1 * n);
	}
	if (un_nbr > 9)
	{
		ft_putnbr_fd(un_nbr / 10, fd);
		ft_putchar_fd('0' + un_nbr % 10, fd);
	}
	else
		ft_putchar_fd('0' + un_nbr, fd);
}
