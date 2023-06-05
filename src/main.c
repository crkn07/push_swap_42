/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:37:00 by crtorres          #+#    #+#             */
/*   Updated: 2023/06/05 16:27:42 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_leaks()
{
	system("leaks -q push_swap");
}
int	main(int argc, char **argv)
{
	t_stack		*stack_a;

	//atexit(ft_leaks);
	if (argc < 2)
		exit_error("error\n");
	stack_a = create_stack(argc, argv);
	if (duplicate_nbr(stack_a))
	{
		ft_free_stack(&stack_a);
		exit_error("error\n");
	}
	if (!stack_a)
		exit_error ("error\n");
	if (!ft_is_sorted(stack_a))
		sort_with_quicksort(&stack_a);
	ft_free_stack(&stack_a);
	return (0);
}
