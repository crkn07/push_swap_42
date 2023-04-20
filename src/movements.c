/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:04:11 by crtorres          #+#    #+#             */
/*   Updated: 2023/04/21 00:35:18 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * The function swaps the top two elements of a stack and prints the
 * corresponding command.
 *
 * @param stack A pointer to a pointer to a stack data structure.
 * @param c is an integer that is used to determine which stack is being
 * swapped. If c is 0, is the stack A, and if is 1,is the stack B.
 *
 * @return if the stack is empty or if it only has one element the function
 * will return without doing anything. Otherwise, the function will print "sa"
 * or "sb" depending on the value of `c`.
 */
void	ft_swap(t_stack **stack, int c)
{
	long	tmp;

	if (!*stack || !((*stack)->next))
		return ;
	tmp = (*stack)->nbr;
	(*stack)->nbr = (*stack)->next->nbr;
	(*stack)->next->nbr = tmp;
	if (c == 0)
		write(1, "sa\n", 3);
	else if (c == 1)
		write(1, "sb\n", 3);
}

/**
 * This function swaps the top two elements of a stack based on a
 * given parameter.
 *
 * @param stack A pointer to a stack structure which contains an array of
 * integers and information about the size and top index of the stack.
 * @param c determines which swap operation to perform. If c is 0, it swaps
 * the stack A. If is 1, swap stack B and if is 2, swap both stacks.
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
 * @param stack is a pointer to a pointer to a stack data structure.
 * @param c is an integer used to determine which stack is rotating.
 * If c is 0, it is stack A, and if it is 1, it is stack B.
 *
 * @return if the stack is empty or if it only has one element the function
 * will return without doing anything. Otherwise, the function will print "ra"
 * or "rb" depending on the value of `c`.
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
 *  in a sorting algorithm.
 * @param stack_b is a pointer to a stack data structure calling stack B.
 */
void	ft_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a, 2);
	ft_rotate(stack_b, 2);
	write(1, "rr\n", 3);
}

/**
 * The function performs a reverse rotation operation on a stack.
 *
 * @param stack is a pointer to a pointer to the first element of a linked list
 * representing a stack on which a reverse rotation operation is performed.
 * @param c is an integer that is used to determine which stack is being
 * operated on. If c is 0, then stack A is operated, and if c is 1,
 * stack B is operated.
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
	if (c == 0)
		write(1, "rra\n", 4);
	if (c == 1)
		write(1, "rrb\n", 4);
}
