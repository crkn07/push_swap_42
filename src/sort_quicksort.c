/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quicksort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:58:58 by crtorres          #+#    #+#             */
/*   Updated: 2023/04/17 16:44:11 by crtorres         ###   ########.fr       */
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
		ft_reverse_rotate(stack_a, 0);
	else if (index_in_stack(*stack_a, ft_min_int(*stack_a)) == 1)
		ft_swap_ab(stack_a, 0);
}

void	sort_with_quicksort(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		i;

	stack_b = NULL;
	if (ft_listsize(*stack_a) == 2)
		ft_swap_ab(stack_a, 0);
	else
	{
		stack_b = sorted_stack_b(stack_a);
		stack_a = sort_stack_a(stack_a, &stack_b);
		printf("entra\n");
		i = index_in_stack(*stack_a, ft_min_int(*stack_a));
		if (i < ft_listsize(*stack_a) - i)
		{
			while ((*stack_a)->nbr != ft_min_int(*stack_a))
				ft_rotate(stack_a, 0);
		}
		else
		{
			while ((*stack_a)->nbr != ft_min_int(*stack_a))
				ft_reverse_rotate(stack_a, 0);
		}
	}
}