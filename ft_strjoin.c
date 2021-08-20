/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 12:15:49 by otaishi           #+#    #+#             */
/*   Updated: 2020/10/19 18:24:19 by otaishi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;

	if (!s1 || !s2 ||
			!(ret = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	ft_strlcat(ft_memcpy(ret, s1, ft_strlen(s1) + 1),
			s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (ret);
}
