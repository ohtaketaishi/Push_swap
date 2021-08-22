/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 18:30:46 by otaishi           #+#    #+#             */
/*   Updated: 2020/10/19 17:17:47 by otaishi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newlst;

	if (!(newlst = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	newlst->content = content;
	newlst->next = NULL;
	return (newlst);
}
