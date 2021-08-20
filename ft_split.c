/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 01:11:17 by otaishi           #+#    #+#             */
/*   Updated: 2020/10/19 18:14:42 by otaishi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	strings_count(char const *s, char c)
{
	int		s_count;
	int		new_word;

	s_count = 0;
	new_word = 1;
	if (!*s)
		return (0);
	while (*s)
	{
		if (*s == c)
			new_word = 1;
		else if (new_word == 1)
		{
			new_word = 0;
			s_count++;
		}
		s++;
	}
	return (s_count);
}

static int	chars_count(char const *s, char c, int i)
{
	int		len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static void	free_all(char **dst, int j)
{
	while (j-- > 0)
		free(dst[j]);
	free(dst);
}

static void	fill(char const *s, char c, char **dst, int s_count)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] && j < s_count)
	{
		while (s[i] == c)
			i++;
		if (!(dst[j] = (char *)malloc(chars_count(s, c, i) + 1)))
		{
			free_all(dst, j);
			*dst = NULL;
			return ;
		}
		ft_strlcpy(dst[j], &s[i], chars_count(s, c, i) + 1);
		i += chars_count(s, c, i);
		j++;
	}
}

char		**ft_split(char const *s, char c)
{
	char	**dst;
	int		s_count;

	if (s == NULL)
		return (NULL);
	s_count = strings_count(s, c);
	if (!(dst = (char **)malloc(sizeof(char *) * s_count + 1)))
		return (NULL);
	dst[s_count] = NULL;
	fill(s, c, dst, s_count);
	return (dst);
}
