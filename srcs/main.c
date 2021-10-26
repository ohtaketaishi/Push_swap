/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaishi <otaishi@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:02:56 by otaishi           #+#    #+#             */
/*   Updated: 2021/10/26 11:16:19 by otaishi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*head_a;
	t_list	*head_b;
	t_list	*head_o;

	if (argc == 1)
		return (0);
	head_a = ft_init_head();
	head_b = ft_init_head();
	head_o = ft_init_head();
	if (check_num(argc, argv) || argv_to_lst(head_a, head_b, argv, argc)
		|| check_dup(head_a))
	{
		ft_3lstfree(head_a, head_b, head_o);
		write(2, "Error\n", 6);
		return (-1);
	}
	if (check_sorted(head_a, head_b, head_o))
		return (0);
	sorting_start(head_a, head_b, head_o);
	return (0);
}
