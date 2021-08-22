/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 13:56:06 by otaishi           #+#    #+#             */
/*   Updated: 2020/10/23 00:26:33 by otaishi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest < src)
	{
		while (n-- > 0)
		{
			*(unsigned char*)(dest + i) = *(const unsigned char*)(src + i);
			i++;
		}
	}
	else if (src < dest)
	{
		while (n-- > 0)
		{
			*(unsigned char*)(dest + n) = *(const unsigned char*)(src + n);
		}
	}
	return (dest);
}
