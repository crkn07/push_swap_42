/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:37:00 by crtorres          #+#    #+#             */
/*   Updated: 2023/04/24 16:37:49 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		*stack_a;

	if (argc < 2)
		exit_error("Invalid numbers of arguments\n");
	stack_a = create_stack(argc, argv);
	if (!stack_a || duplicate_nbr(stack_a))
	{
		ft_free_stack(&stack_a);
		exit_error("duplicated number or no stack");
	}
	if (!ft_is_sorted(stack_a))
		sort_with_quicksort(&stack_a);
	ft_free_stack(&stack_a);
	return (0);
}