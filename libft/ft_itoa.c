/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 20:16:01 by otaishi           #+#    #+#             */
/*   Updated: 2020/10/19 16:53:16 by otaishi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	buf[21];
	char	*p;
	char	*ret;
	int		flag;

	ft_bzero(buf, 21);
	p = buf + 20;
	flag = ((n < 0) ? 1 : 0);
	if (n == 0 || n == -0)
		*--p = '0';
	while (n)
	{
		if (n > 0)
			*--p = '0' + (n % 10);
		else if (n < 0)
			*--p = '0' - (n % 10);
		n /= 10;
	}
	if (flag)
		*--p = '-';
	if (!(ret = (char *)malloc(sizeof(char) * ft_strlen(p) + 1)))
		return (NULL);
	ft_strlcpy(ret, p, ft_strlen(p) + 1);
	return (ret);
}
