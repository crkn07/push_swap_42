/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_stack_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:19:32 by crtorres          #+#    #+#             */
/*   Updated: 2023/04/21 12:06:37 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * This function adds a new node to the front of a stack.
 *
 * @param stack A pointer to a pointer to the first node of a stack.
 * @param new_node A pointer to a new node.
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
 * This function is designed to traverse the stack and returns the minimum
 * integer value present in the given linked list..
 *
 * @param stack is a pointer to a linked list data structure, specifically
 * a stack. Each node in the stack contains an integer value "nbr" and a
 * pointer to the next node in the stack.
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
 * @param stack is a pointer to the top element of a stack data structure.
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
