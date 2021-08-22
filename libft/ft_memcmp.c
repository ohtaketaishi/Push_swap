/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 10:42:57 by otaishi           #+#    #+#             */
/*   Updated: 2020/10/19 17:44:53 by otaishi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *copybuf1;
	unsigned char *copybuf2;

	copybuf1 = (unsigned char *)s1;
	copybuf2 = (unsigned char *)s2;
	while (n--)
	{
		if (*copybuf1++ != *copybuf2++)
		{
			return (*--copybuf1 - *--copybuf2);
		}
	}
	return (0);
}
