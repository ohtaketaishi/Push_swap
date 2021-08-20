/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 00:11:12 by otaishi           #+#    #+#             */
/*   Updated: 2020/10/19 17:36:46 by otaishi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *copybuf;

	copybuf = (unsigned char *)s;
	while (n-- > 0)
	{
		if (*copybuf++ == (unsigned char)c)
		{
			return (--copybuf);
		}
	}
	return (NULL);
}
