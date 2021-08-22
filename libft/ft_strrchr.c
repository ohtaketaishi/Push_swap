/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 17:32:02 by otaishi           #+#    #+#             */
/*   Updated: 2020/10/19 18:42:35 by otaishi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*copybuf;

	copybuf = NULL;
	while (*s)
	{
		if (*s++ == (char)c)
		{
			copybuf = (char *)s - 1;
		}
	}
	if (*s == (char)c)
		copybuf = (char *)s;
	return (copybuf);
}
