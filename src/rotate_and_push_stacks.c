/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_and_push_stacks.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:59:07 by crtorres          #+#    #+#             */
/*   Updated: 2023/04/17 11:43:21 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	do_rot_push_stacks(t_stack **stack_a, t_stack **stack_b, int j, char c)
{
	if (c == 'A')
	{
		while ((*stack_a)->nbr != j && checkplace_instack(*stack_b, j) > 0)
			ft_rotate_ab(stack_a,  stack_b);
		while ((*stack_a)->nbr != j)
			ft_rotate(stack_a, 0);
		while (checkplace_instack(*stack_b, j) > 0)
			ft_rotate(stack_b, 1);
		ft_push_ab(stack_a, stack_a, 1);
	}
	if (c == 'B')
	{
		while ((*stack_b)->nbr != j && checkplace_instack(*stack_a, j) > 0)
			ft_rotate_ab(stack_a,  stack_b);
		while ((*stack_b)->nbr != j)
			ft_rotate(stack_b, 1);
		while (checkplace_instack(*stack_a, j) > 0)
			ft_rotate(stack_a, 0);
		ft_push_ab(stack_b, stack_a, 0);
	}
	return (-1);
}

int	do_revrot_push_stacks(t_stack **stack_a, t_stack **stack_b, int j, char c)
{
	if (c == 'A')
	{
		while ((*stack_a)->nbr != j && checkplace_instack(*stack_a, j) > 0)
			ft_reverse_rotate_both(stack_a, stack_b);
		while ((*stack_a)->nbr != j)
			ft_reverse_rotate(stack_a, 0);
		while (checkplace_instack(*stack_b, j) > 0)
			ft_reverse_rotate(stack_b, 1);
		ft_push_ab(stack_a, stack_b,  1);
	}
	if (c == 'B')
	{
		while ((*stack_b)->nbr != j && checkplace_instack(*stack_b, j) > 0)
			ft_reverse_rotate_both(stack_a, stack_b);
		while ((*stack_b)->nbr != j)
			ft_reverse_rotate(stack_b, 1);
		while (checkplace_instack(*stack_a, j) > 0)
			ft_reverse_rotate(stack_a, 0);
		ft_push_ab(stack_b, stack_a, 0);
	}
	return (-1);
}

int	do_revrot_a_rev_b(t_stack **stack_a, t_stack **stack_b, int j, char c)
{
	if (c == 'A')
	{
		while ((*stack_a)->nbr != j)
			ft_reverse_rotate(stack_a, 0);
		while (checkplace_instack(*stack_b, j) > 0)
			ft_rotate(stack_b, 1);
		ft_push_ab(stack_a, stack_b, 1);
	}
	if (c == 'B')
	{
		while (checkplace_instack(*stack_a, j))
			ft_reverse_rotate(stack_a, 0);
		while ((*stack_b)->nbr != j)
			ft_rotate(stack_b, 1);
		ft_push_ab(stack_b, stack_a, 0);
	}
	return (-1);
}
int	do_rot_a_revrot_b(t_stack **stack_a, t_stack **stack_b, int j, char c)
{
	if (c == 'A')
	{
		while ((*stack_a)->nbr != j)
			ft_rotate(stack_a, 0);
		while (checkplace_instack(*stack_b, j) > 0)
			ft_reverse_rotate(stack_b, 0);
		ft_push_ab(stack_a, stack_b, 1);
	}
	if (c == 'B')
	{
		while (checkplace_instack(*stack_a, j))
			ft_rotate(stack_a, 0);
		while ((*stack_b)->nbr != j)
			ft_reverse_rotate(stack_b, 1);
		ft_push_ab(stack_b, stack_a, 0);
	}
	return (-1);
}