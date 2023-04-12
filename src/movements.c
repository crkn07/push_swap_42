/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:04:11 by crtorres          #+#    #+#             */
/*   Updated: 2023/04/12 14:38:13 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * The function swaps the top two elements of a stack and prints the 
 * corresponding command.
 * 
 * @param stack A pointer to a pointer to a struct of type t_stack, which
 * represents a stack data structure.
 * @param c The parameter "c" is an integer that is used to determine which 
 * stack is being swapped. If c is 0, it means we are swapping the first 
 * stack (stack A), and if c is 1, it means we are swapping the second 
 * stack (stack B).
 * 
 * @return If the condition `if (!*stack || !((*stack)->next))` is true, 
 * then the function will return without doing anything. Otherwise, the 
 * function will swap the top two elements of the stack and print "sa\n" 
 * if `c` is 0 or "sb\n" if `c` is 1. However, the function does not have 
 * a return type specified, so
 */
void	ft_swap(t_stack **stack, int c)
 {
	t_stack	*tmp;
	
	if (!*stack || !((*stack)->next))
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->next = tmp;
	if (c == 0)
		write(1, "sa\n", 3);
	else if (c == 1)
		write(1, "sb\n", 3);		
 }

/**
 * The function `ft_swap_ab` swaps the top two elements of a stack based on a 
 * given parameter.
 * 
 * @param stack A pointer to a pointer to a stack structure. The stack 
 * structure contains an array of integers and information about the size and 
 * top index of the stack.
 * @param c The parameter "c" is an integer that determines which swap 
 * operation to perform. If c is 0, it swaps the top two elements of stack A. 
 * If c is 1, it swaps the top two elements of stack B. If c is 3, it swaps 
 * the top two elements
 */
void	ft_swap_ab(t_stack **stack, int c)
 {
	if (c == 0)
		ft_swap(stack, 0);
	if (c == 1)
		ft_swap(stack, 1);
	if (c == 2)
	{
		ft_swap(stack, 2);
		ft_swap(stack, 2);
		write(1, "ss\n", 3);
	}
 }

/**
 * The function rotates a stack by moving the first element to the end.
 * 
 * @param stack The parameter "stack" is a pointer to a pointer to a struct of 
 * type "t_stack". This is likely a linked list implementation of a stack data
 * structure.
 * @param c The parameter "c" is an integer that determines which stack to 
 * rotate.
 * If c is 0, then the "stack" parameter is the stack A that needs to 
 * be rotated.
 * If c is 1, then the "stack" parameter is the stack B that needs to 
 * be rotated.
 * 
 * @return The function does not return anything, it is a void function.
 */
void	ft_rotate(t_stack **stack, int c)
{
	t_stack	*tmp;
	
	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = ft_listlast(*stack);
	(*stack)->next = tmp;
	(*stack) = tmp->next;
	tmp->next = NULL;
	if (c == 0)
		write(1, "ra\n", 3);
	else if (c == 1)
		write(1, "rb\n", 3);
}

/**
 * The function rotates both stacks and prints "rr\n".
 * 
 * @param stack_a A pointer to a stack representing stack A 
 * in a sorting algorithm.
 * @param stack_b The parameter `stack_b` is a pointer to a stack data 
 * structure in C. It is likely being used in a program that implements 
 * a sorting algorithm using two stacks, commonly known as the "push_swap" 
 * algorithm. The `ft_rotate_ab` function is used to rotate both stacks 
 * simultaneously by calling
 */
void	ft_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a, 2);
	ft_rotate(stack_b, 1);
	write(1, "rr\n", 3);
}

/**
 * The function performs a reverse rotation operation on a stack.
 * 
 * @param stack The "stack" parameter is a pointer to a pointer to the first
 * element of a linked list representing a stack. The function performs a 
 * reverse rotation operation on this stack.
 * @param c The parameter "c" is an integer that is used to determine which 
 * stack is being operated on. If c is 0, then the "ft_reverse_rotate" 
 * function is being applied to stack A, and if c is 1, then it is being 
 * applied to stack B. This is used
 */
void	ft_reverse_rotate(t_stack **stack, int c)
{
	t_stack	*last;
	t_stack	*tmp;

	tmp = *stack;
	last = ft_listlast(tmp);
	while (tmp->next != NULL && tmp->next != last)
		tmp = tmp->next;
	tmp->next = NULL;
	ft_stacklist_add_front(stack, last);
	free(last);
	if (c == 0)
		write(1, "rra\n", 4);
	if (c == 1)
		write(1, "rrb\n", 4);
}
