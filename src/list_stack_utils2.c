/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_stack_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:19:32 by crtorres          #+#    #+#             */
/*   Updated: 2023/04/19 17:25:55 by crtorres         ###   ########.fr       */
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
 * @param stack The parameter "stack" is a pointer to a linked list data structure,
 * specifically a stack. Each node in the stack contains an integer value "nbr" and
 * a pointer to the next node in the stack. The function "ft_min_int" is designed
 * to traverse the stack and return the minimum integer
 * 
 * @return The function `ft_min_int` is returning the minimum integer value present
 * in the given `t_stack` linked list.
 */
int	ft_min_int(t_stack *stack)
{
	int	i;

	i = stack->nbr;
	/* printf("Stack: %li\n", stack->nbr);
	stack = stack->next;
	printf("Stack: %li\n", stack->nbr);
	stack = stack->next;
	printf("Stack: %li\n", stack->nbr); */
	while (stack)
	{
		if (stack->nbr < i)
			i = stack->nbr;
		//printf("Stack: %li\n", stack->nbr);
		stack = stack->next;
	}
	//printf("I: %d\n", i);
	//printf("entra\n");
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