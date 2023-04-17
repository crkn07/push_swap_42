/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quicksort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:58:58 by crtorres          #+#    #+#             */
/*   Updated: 2023/04/17 10:53:59 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three_numbers(t_stack **stack_a)
{
	if (ft_min_int(*stack_a) == (*stack_a)->nbr)
	{
		ft_reverse_rotate(stack_a, 0);
		ft_swap_ab(stack_a, 0);
	}
	else if (ft_max_int(*stack_a) == (*stack_a)->nbr)
	{
		ft_rotate(stack_a, 0);
		if (!ft_is_sorted(*stack_a))
			ft_swap_ab(stack_a, 0);
	}
	else if (index_in_stack(*stack_a, ft_max_int(*stack_a)) == 1)
		ft_reverse_rotate(*stack_a, 0);
	else if (index_in_stack(*stack_a, ft_min_int(*stack_a)) == 1)
		ft_swap_ab(stack_a, 0);
}

void	sort_with_quicksort(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		i;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) == 2)
		ft_swap_ab(stack_a, 0);
	else
	{
		stack_b = sorted_stack_b(stack_a);
		stack_a = sorted_stack_a(stack_a, stack_b);
		i = index_in_stack(*stack_a, ft_min_int(*stack_a));
		if ()
	}
}