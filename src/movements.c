/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:04:11 by crtorres          #+#    #+#             */
/*   Updated: 2023/04/10 16:21:19 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * The function swaps the top two elements of a stack and prints the corresponding
 * command.
 * 
 * @param stack A pointer to a pointer to a struct of type t_stack, which
 * represents a stack data structure.
 * @param c The parameter "c" is an integer that is used to determine which stack
 * is being swapped. If c is 0, it means we are swapping the first stack (stack A),
 * and if c is 1, it means we are swapping the second stack (stack B).
 * 
 * @return If the condition `if (!*stack || !((*stack)->next))` is true, then the
 * function will return without doing anything. Otherwise, the function will swap
 * the top two elements of the stack and print "sa\n" if `c` is 0 or "sb\n" if `c`
 * is 1. However, the function does not have a return type specified, so
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
 * The function `ft_swap_ab` swaps the top two elements of both stacks and prints
 * "ss".
 * 
 * @param stack_a A pointer to a stack (presumably stack A) that needs to be
 * swapped with another stack (presumably stack B).
 * @param stack_b The parameter `stack_b` is a pointer to a pointer to a `t_stack`
 * struct. It is likely being used to represent a stack data structure in a sorting
 * algorithm.
 */
 void	ft_swap_ab(t_stack **stack_a, t_stack **stack_b)
 {
	ft_swap(stack_a, 0);
	ft_swap(stack_b, 1);
	write(1, "ss\n", 3);
 }

/**
 * The function rotates a stack by moving the first element to the end.
 * 
 * @param stack The parameter "stack" is a pointer to a pointer to a struct of type
 * "t_stack". This is likely a linked list implementation of a stack data
 * structure.
 * @param c The parameter "c" is an integer that determines which stack to rotate.
 * If c is 0, then the "stack" parameter is the stack A that needs to be rotated.
 * If c is 1, then the "stack" parameter is the stack B that needs to be rotated.
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
 * The function `ft_rotate_ab` rotates both stacks `stack_a` and `stack_b` and
 * prints "rr\n".
 * 
 * @param stack_a A pointer to a stack representing stack A.
 * @param stack_b The parameter `stack_b` is a pointer to a pointer to a 
 * `t_stack` struct. It is likely part of a larger program that implements 
 * a stack data structure using linked lists. The `ft_rotate_ab` function takes
 * two stacks (`stack_a` and `stack_b`) and rotates them
 */
void	ft_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a, 0);
	ft_rotate(stack_b, 1);
	write(1, "rr\n", 3);
}

void	ft_reverse_rotate(t_stack **stack, char c)
{
	t_stack	*last;
	t_stack	*tmp;

	tmp = *stack;
	last = ft_stacklast(tmp);
	while (tmp->next != NULL && tmp->next != last)
		tmp = tmp->next;
	tmp->next = NULL;
	ft_stackadd_front(stack, last);
	free(last);
}

/**
 * The function adds a new node to the front of a stack.
 * 
 * @param stack A pointer to a pointer to the top node of a stack. This allows the
 * function to modify the stack by adding a new node to the front.
 * @param new The parameter `new` is a pointer to a `t_stack` structure, which
 * contains a `number` field and a `next` field. It represents the node that we
 * want to add to the front of the stack.
 */
void	ft_stackadd_front(t_stack **stack, t_stack *new)
{
	t_stack	*new_node;

	new_node = ft_newnode(new->number);
	new_node->next = *stack;
	*stack = new_node;
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

/* void	ft_ra(t_stack **a, int i)
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
} */

/* 
	if (c == 'a')
		print("sa");
	else if (c == 'b')
		print("sb");
} */