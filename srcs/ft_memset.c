/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:02:41 by otaishi           #+#    #+#             */
/*   Updated: 2021/10/25 17:02:43 by otaishi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*copybuf;

	copybuf = (unsigned char *)s;
	while (n-- > 0)
	{
		*copybuf++ = (unsigned char)c;
	}
	return (s);
}
