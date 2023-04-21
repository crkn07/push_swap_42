/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   times_types_rotations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 00:47:26 by crtorres          #+#    #+#             */
/*   Updated: 2023/04/21 12:10:16 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	times_rotate_stacks(t_stack *stack_a, t_stack *stack_b, int j, char c)
{
	int	i;

	i = 0;
	if (c == 'B')
	{
		i = checkplace_instack(stack_b, j);
		if (i < index_in_stack(stack_a, j))
			i = index_in_stack(stack_a, j);
	}
	else if (c == 'A')
	{
		i = checkplace_instack_a(stack_a, j);
		if (i < index_in_stack(stack_b, j))
			i = index_in_stack(stack_b, j);
	}
	return (i);
}

int	times_revrot_both(t_stack *stack_a, t_stack *stack_b, int j, char c)
{
	int	i;

	i = 0;
	if (c == 'B')
	{
		if (checkplace_instack(stack_b, j))
			i = ft_listsize(stack_b) - checkplace_instack(stack_b, j);
		if ((i < (ft_listsize(stack_a) - index_in_stack(stack_a, j)))
			&& index_in_stack(stack_a, j))
			i = ft_listsize(stack_a) - index_in_stack(stack_a, j);
	}
	else if (c == 'A')
	{
		if (checkplace_instack_a(stack_a, j))
			i = ft_listsize(stack_a) - checkplace_instack_a(stack_a, j);
		if ((i < (ft_listsize(stack_b) - index_in_stack(stack_b, j)))
			&& index_in_stack(stack_b, j))
			i = ft_listsize(stack_b) - index_in_stack(stack_b, j);
	}
	return (i);
}

int	times_revrota_rotb(t_stack *stack_a, t_stack *stack_b, int j, char c)
{
	int	i;

	i = 0;
	if (c == 'B')
	{
		if (index_in_stack(stack_a, j))
			i = ft_listsize(stack_a) - index_in_stack(stack_a, j);
		i = checkplace_instack(stack_b, j) + i;
	}
	else if (c == 'A')
	{
		if (checkplace_instack_a(stack_a, j))
			i = ft_listsize(stack_a) - checkplace_instack_a(stack_a, j);
		i = index_in_stack(stack_b, j) + i;
	}
	return (i);
}
