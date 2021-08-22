/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:58:31 by otaishi           #+#    #+#             */
/*   Updated: 2020/10/19 17:59:42 by otaishi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*copybuf;

	copybuf = (unsigned char*)s;
	while (n-- > 0)
	{
		*copybuf++ = (unsigned char)c;
	}
	return (s);
}
