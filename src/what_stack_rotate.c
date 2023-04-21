/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_stack_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:22:43 by crtorres          #+#    #+#             */
/*   Updated: 2023/04/21 12:18:40 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * The function calculates the number of times to rotate or reverse rotate 
 * a stack based on the position of a given element.
 * 
 * @param stack_a The first stack.
 * @param stack_b is a pointer to a stack data structure.
 * @param j is the number or value being searched for in the stacks. It is 
 * used to determine the index or position of the value in the stacks.
 * @param c is a character that specifies which stack to perform the operation 
 * on. It can be either 'A' or 'B'.
 * 
 * @return an integer value which is the number of times stack A or  B needs 
 * to be rotated in order to bring the element `j` to the top of the  stack,
 * followed by the number of times stack A or  B needs to be reversed in order
 * to bring the element `j` to the bottom of the stack.
 */
int	times_rota_revrotb(t_stack *stack_a, t_stack *stack_b, int j, char c)
{
	int	i;

	i = 0;
	if (c == 'B')
	{
		if (checkplace_instack(stack_b, j))
			i = ft_listsize(stack_b) - checkplace_instack(stack_b, j);
		i = index_in_stack(stack_a, j) + i;
	}
	else if (c == 'A')
	{
		if (index_in_stack(stack_b, j))
			i = ft_listsize(stack_b) - index_in_stack(stack_b, j);
		i = checkplace_instack_a(stack_a, j) + i;
	}
	return (i);
}

int	what_type_rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_stack	*tmp;

	tmp = stack_a;
	i = times_revrot_both(stack_a, stack_b, stack_a->nbr, 'B');
	while (tmp)
	{
		if (i > times_rotate_stacks(stack_a, stack_b, tmp->nbr, 'B'))
			i = times_rotate_stacks(stack_a, stack_b, tmp->nbr, 'B');
		if (i > times_rota_revrotb(stack_a, stack_b, tmp->nbr, 'B'))
			i = times_rota_revrotb(stack_a, stack_b, tmp->nbr, 'B');
		if (i > times_revrot_both(stack_a, stack_b, tmp->nbr, 'B'))
			i = times_revrot_both(stack_a, stack_b, tmp->nbr, 'B');
		if (i > times_revrota_rotb(stack_a, stack_b, tmp->nbr, 'B'))
			i = times_revrota_rotb(stack_a, stack_b, tmp->nbr, 'B');
		tmp = tmp->next;
	}
	return (i);
}

/**
 * The function calculates the minimum number of operations required to rotate 
 * or reverse rotate stack A and B in a specific order.
 * 
 * @param stack_a The first stack that is being manipulated in the program.
 * @param stack_b The second stack in the program.
 * 
 * @return the minimum number of operations required to rotate or reverse 
 * rotate both stacks in order to bring the smallest element of`stack_b` 
 * to the top of `stack_a`.
 */
int	what_type_rotate_ba(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_stack	*tmp;

	tmp = stack_b;
	i = times_revrot_both(stack_a, stack_b, stack_b->nbr, 'A');
	while (tmp)
	{
		if (i > times_rotate_stacks(stack_a, stack_b, tmp->nbr, 'A'))
			i = times_rotate_stacks(stack_a, stack_b, tmp->nbr, 'A');
		if (i > times_revrot_both(stack_a, stack_b, tmp->nbr, 'A'))
			i = times_revrot_both(stack_a, stack_b, tmp->nbr, 'A');
		if (i > times_rota_revrotb(stack_a, stack_b, tmp->nbr, 'A'))
			i = times_rota_revrotb(stack_a, stack_b, tmp->nbr, 'A');
		if (i > times_revrota_rotb(stack_a, stack_b, tmp->nbr, 'A'))
			i = times_revrota_rotb(stack_a, stack_b, tmp->nbr, 'A');
		tmp = tmp->next;
	}
	return (i);
}
