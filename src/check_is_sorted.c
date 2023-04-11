/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:19:33 by crtorres          #+#    #+#             */
/*   Updated: 2023/04/10 15:49:00 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_is_sorted(t_stack *stack_a)
{
	int	i;

	i = stack_a->nbr;
	while (stack_a)
	{
		if (stack_a->nbr < i)
			return (0);
		i = stack_a->nbr;
		stack_a = stack_a->next;
	}
	return (1);
}

t_stack	*sorted_stack_b(t_stack **stack_a)
{
	t_stack	*stack_b;
	
	stack_b = NULL;
	if (ft_lstsize(*stack_a) > 3 && !ft_is_sorted(*stack_a))
		
	
}
