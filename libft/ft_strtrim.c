/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 22:47:14 by otaishi           #+#    #+#             */
/*   Updated: 2020/10/19 18:44:17 by otaishi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	if (*s1 == '\0')
		return (ft_substr(s1, i, 0));
	while (is_in_set(s1[i], set))
		i++;
	j = ft_strlen(s1) - 1;
	while (j >= i && is_in_set(s1[j], set))
		j--;
	len = j - i + 1;
	return (ft_substr(s1, i, len));
}
