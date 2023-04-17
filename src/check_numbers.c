/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:40:23 by crtorres          #+#    #+#             */
/*   Updated: 2023/04/17 13:24:29 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * The function checks if there are any duplicate numbers in a given stack.
 * 
 * @param stack_a a is a pointer to a stack data structure. The function 
 * `duplicate_nbr` checks if there are any duplicate integers in the stack.
 * 
 * @return The function `duplicate_nbr` is returning an integer value of 
 * either 0 or 1. It returns 1 if there are duplicate numbers in the given 
 * stack `a`, and 0 if there are no duplicates.
 */
int	duplicate_nbr(t_stack *stack_a)
{
	t_stack	*tmp;
 
	while (stack_a)
	{
		tmp = stack_a->next;
		while (tmp)
		{
			if (stack_a->nbr == tmp->nbr)
				return (1);
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
	return (0);
}
