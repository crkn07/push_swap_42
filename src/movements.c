/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:04:11 by crtorres          #+#    #+#             */
/*   Updated: 2023/04/05 13:34:00 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * The function swaps the top two elements of a stack and prints a 
 * corresponding
 * message depending on the stack being operated on.
 * 
 * @param stack A pointer to a pointer to a struct representing a stack.
 * @param c The parameter "c" is a character that specifies which stack to 
 * perform the swap operation on. It can be either 'a' or 'b', indicating 
 * whether the operation is to be performed on stack A or stack B.
 * 
 * @return If the condition `if (!*stack || !((*stack)->next))` is true, then
 * nothing is returned and the function exits. Otherwise, the function swaps 
 * the top two elements of the stack and prints "sa\n" or "sb\n" depending 
 * on the value of the parameter `c`. However, the function does not explicitly 
 * return anything.
 */
 void	ft_swap(t_stack **stack, char c)
 {
	t_stack	*tmp;
	
	if (!*stack || !((*stack)->next))
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->next = tmp;
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);		
 }

 /**
  * The function `ft_swap_ab` swaps the top elements of two stacks and 
  * prints "ss".
  * 
  * @param stack_a A pointer to a stack A, which is a linked list of integers.
  * @param stack_b The parameter `stack_b` is a pointer to a pointer to a 
  * `t_stack` struct. It is likely being used to represent a second stack in 
  * a stack-based algorithm or data structure.
  */
 void	ft_swap_ab(t_stack **stack_a, t_stack **stack_b)
 {
	ft_swap(stack_a, NULL);
	ft_swap(stack_b, NULL);
	write(1, "ss\n", 3);
 }

void	ft_rotate(t_stack **stack, char c)
{
	t_stack	*last;
	t_stack	*tmp;
	
	(*tmp) = (*stack);
		
}
/**
 * The function `ft_pa` moves the top element from stack B to stack A.
 * 
 * @param a The parameter "a" is a pointer to a stack, which is a data structure
 * used in the context of a sorting algorithm. It represents the first stack in the
 * algorithm.
 * @param i The parameter "i" is an integer variable that is used to determine
 * whether or not to print the "pa" command to the standard output. If "i" is equal
 * to 0, then the "pa" command will be printed. Otherwise, if "i" is not equal to
 * 
 * @return If `*b` is `NULL`, the function returns without doing anything.
 * Otherwise, the function performs the necessary operations to move the top
 * element of stack `b` to the top of stack `a`, and then prints "pa\n" to the
 * standard output if `i` is equal to 0. However, the function does not explicitly
 * return anything.
 */
void	ft_pa(t_stack **a, int i)
{
	t_stack	*tmp;
	
	if (!*b)
		return ;
	tmp = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = tmp;
	if (i == 0)
		write(1, "pa\n", 3);
}

void	ft_ra(t_stack **a, int i)
{
	t_stack	*tmp;

	if (!*a || !((*a)->next))
		return ;
	tmp = *a;
	*a = ft_listlast(*a);
	*a = tmp->next;
	tmp->next = NULL;
	if (i == 0)
		write(1, "ra\n", 3);
}

/* 
	if (c == 'a')
		print("sa");
	else if (c == 'b')
		print("sb");
} */