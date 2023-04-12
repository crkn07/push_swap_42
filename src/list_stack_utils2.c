/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_stack_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:19:32 by crtorres          #+#    #+#             */
/*   Updated: 2023/04/12 17:34:35 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * This function adds a new node to the front of a stack.
 * 
 * @param stack A pointer to a pointer to the first node of a stack 
 * (i.e. a pointer to the head of the stack).
 * @param new_node A pointer to a new node that needs to be added to the front 
 * of the stack.
 */
void	ft_stacklist_add_front(t_stack **stack, t_stack *new_node)
{
	if (new_node)
	{
		new_node->next = *stack;
		*stack = new_node;
	}
}

/**
 * The function returns the minimum integer value in a given stack.
 * 
 * @param stack The parameter "stack" is a pointer to a linked list of integers.
 * Each node in the linked list contains an integer value and a pointer to the 
 * next node in the list. The function is designed to find the minimum integer 
 * value in the linked list.
 * 
 * @return The function `ft_min_int` is returning the minimum integer value 
 * present in the given `t_stack` linked list.
 */
int	ft_min_int(t_stack *stack)
{
	int	i;

	i = stack->nbr;
	while (stack)
	{
		if (stack->nbr < i)
			i = stack->nbr;
		stack = stack->next;
	}
	return (i);
}

/**
 * The function returns the maximum integer value in a given stack.
 * 
 * @param stack The parameter "stack" is a pointer to the top element of a 
 * stack data structure.
 */
int	ft_max_int(t_stack *stack)
{
	int	i;

	i = stack->nbr;
	while (stack)
	{
		if (stack->nbr > i)
			i = stack->nbr;
		stack = stack->next;
	}
	return (i);
}