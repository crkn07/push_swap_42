/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:52:09 by crtorres          #+#    #+#             */
/*   Updated: 2023/04/11 16:30:22 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * The function performs a reverse rotation on both stack A and stack B and 
 * prints "rrr".
 * 
 * @param stack_a A pointer to a stack (presumably stack A) that needs to be
 * reverse rotated along with stack B.
 * @param stack_b The parameter `stack_b` is a pointer to a stack 
 * (presumably a linked list implementation) in a stack-based data structure. 
 * It is being passed as an argument to the function `ft_reverse_rotate_both`, 
 * which is expected to perform a reverse rotation operation on this stack.
 */
void	ft_reverse_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse_rotate(stack_a, 0);
	ft_reverse_rotate(stack_b, 1);
	write(1, "rrr\n", 4);
}

/**
 * The function `ft_push` takes two stacks and an integer as input, pops the 
 * top element from the first stack and pushes it onto the second stack, and 
 * prints "pa" or "pb" depending on the value of the integer.
 * 
 * @param stack_a A pointer to a stack (linked list) representing stack A in a
 * push-swap program.
 * @param stack_b The parameter `stack_b` is a pointer to a pointer to a 
 * `t_stack` struct, which represents a stack in a stack-based data structure. 
 * It is used in the `ft_push` function to push the top element of `stack_a` 
 * onto `stack_b`.
 * @param c The parameter "c" is an integer that is used to determine whether 
 * the function is pushing to stack A or stack B. If c is equal to 0, the 
 * function is pushing to stack A, and if c is equal to 1, the function is 
 * pushing to stack B.
 */
void	ft_push(t_stack **stack_a, t_stack **stack_b, int c)
{
	t_stack *tmp;
	
	if (stack_a && *stack_a)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		ft_stacklist_add_front(&*stack_b, tmp);
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
 * It is likely being used in a program that implements a sorting algorithm 
 * such as the popular "push_swap" game. The `ft_push_ab` function is 
 * responsible for pushing an element from one stack to another. In this case
 * @param c The parameter "c" is an integer that determines which stack to push
 * from and which stack to push to. If c is 0, then the function will push from
 * stack_b to stack_a. If c is 1, then the function will push from stack_a to
 * stack_b.
 */
void	ft_push_ab(t_stack **stack_a, t_stack **stack_b, int c)
{
	if (c == 0)
		ft_push(stack_a, stack_b, 0);
	if (c == 1)
		ft_push(stack_b, stack_a, 1);
}

