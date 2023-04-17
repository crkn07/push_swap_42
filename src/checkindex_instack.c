/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkindex_instack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:34:39 by crtorres          #+#    #+#             */
/*   Updated: 2023/04/17 16:03:25 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * The function finds the index of a given number in a stack and sets its index 
 * to 0.
 * 
 * @param stack a pointer to a stack structure
 * @param num The integer value that we are searching for in the stack.
 * 
 * @return the index of the node in the stack that contains the integer "num".
 */
int	index_in_stack(t_stack *stack, int num)
{
	int	i;

	i = 0;
	while (stack->nbr != num)
	{
		i++;
		stack = stack->next;
	}
	stack->index = 0;
	return (i);
}

/**
 * The function checks the position of a given number in a stack.
 * 
 * @param stack a pointer to a stack structure
 * @param nbr_push The number that needs to be pushed onto the stack.
 * 
 * @return an integer value, which represents the index at which a given number
 * should be pushed into a stack.
 */
int	checkplace_instack(t_stack *stack, int nbr_push)
{
	int	i;
	t_stack *tmp;

	i = 1;
	if (nbr_push < stack->nbr && nbr_push > ft_listlast(stack)->nbr)
		i = 0;
	else if (nbr_push > ft_max_int(stack) || nbr_push < ft_min_int(stack))
		i = index_in_stack(stack, ft_min_int(stack));
	else
	{
		tmp = stack->next;
		while (stack->index > nbr_push || tmp->nbr < nbr_push)
		{
			stack = stack->next;
			tmp = stack->next;
			i++;
		}
	}
	return (i);
}
