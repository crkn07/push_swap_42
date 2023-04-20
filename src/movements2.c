/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:52:09 by crtorres          #+#    #+#             */
/*   Updated: 2023/04/21 00:43:15 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * The function performs a reverse rotation on both stack A and stack B and
 * prints "rrr".
 *
 * @param stack_a A pointer to a stack A that will be rotated in the
 * reverse direction together with stack B.
 * @param stack_b is a pointer to a stack (a linked list implementation).
 */
void	ft_reverse_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse_rotate(stack_a, 2);
	ft_reverse_rotate(stack_b, 2);
	write(1, "rrr\n", 4);
}

void	ft_push(t_stack **stack_a, t_stack **stack_b, int c)
{
	t_stack *tmp;

	if (!stack_a)
		return ;
	if (stack_a)
	{
		tmp = *stack_a;
		*stack_a = *stack_b;
		*stack_b = (*stack_b)->next;
		(*stack_a)->next = tmp;
		if (c == 0)
			write(1, "pa\n", 3);
		if (c == 1)
			write(1, "pb\n", 3);
	}
}

/**
 * The function `ft_push_ab` pushes an element from one stack to another stack
 * based on the value of the parameter `c`.
 *
 * @param stack_a A pointer to a stack representing stack A.
 * @param stack_b The parameter `stack_b` is a pointer to a stack data
 * structure.
 * @param c is an integer that determines which stack to push from and which
 * stack to push to. If c is 0, the function will push from stack_b to
 * stack_a. If c is 1, the function will push from stack_a to stack_b.
 */
void	ft_push_ab(t_stack **stack_a, t_stack **stack_b, int c)
{
	if (c == 0)
		ft_push(stack_a, stack_b, 0);
	if (c == 1)
		ft_push(stack_b, stack_a, 1);
}
