/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 16:48:55 by otaishi           #+#    #+#             */
/*   Updated: 2020/10/22 13:10:18 by otaishi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;

	if (!(dup = (char*)malloc(ft_strlen(s1) + 1)))
		return (NULL);
	ft_memcpy(dup, s1, ft_strlen(s1) + 1);
	return (dup);
}
