/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_stack_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:22:43 by crtorres          #+#    #+#             */
/*   Updated: 2023/04/17 16:44:37 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	times_rotate_stacks(t_stack *stack_1, t_stack *stack_2, int j)
{
	int	i;

	i = checkplace_instack(stack_2, j);
	if (i < index_in_stack(stack_1, j))
		i = index_in_stack(stack_1, j);
	return (i);
}

int	times_reverse_rotate_stacks(t_stack *stack_1, t_stack *stack_2, int j)
{
	int	i;

	i = 0;
	if (checkplace_instack(stack_2, j))
		i = ft_listsize(stack_2) - checkplace_instack(stack_2, j);
	if ((i < (ft_listsize(stack_1) - index_in_stack(stack_1, j)))
		&& index_in_stack(stack_1, j))
		i = ft_listsize(stack_1) - index_in_stack(stack_1, j);
	return (i);
}

int	times_revrota_rotb(t_stack *stack_1, t_stack *stack_2, int j)
{
	int	i;

	i = 0;
	if (checkplace_instack(stack_1, j))
		i = ft_listsize(stack_1) - checkplace_instack(stack_1, j);
	i = index_in_stack(stack_2, j) - i;
	return (i);
}

int	times_rot_a_revrotb(t_stack *stack_1, t_stack *stack_2, int j)
{
	int	i;

	i = 0;
	if (index_in_stack(stack_2, j))
		i = ft_listsize(stack_2) - index_in_stack(stack_2, j);
	i = checkplace_instack(stack_1, j) + i;
	return (i);
}

int	what_type_rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	t_stack	*tmp;

	tmp = stack_a;
	i = times_reverse_rotate_stacks(stack_a, stack_b, stack_a->nbr);
	while (tmp)
	{
		if (i > times_rotate_stacks(stack_a, stack_b, tmp->nbr))
			i = times_rotate_stacks(stack_a, stack_b, tmp->nbr);
		if (i > times_reverse_rotate_stacks(stack_a, stack_b, tmp->nbr))
			i = times_reverse_rotate_stacks(stack_a, stack_b, tmp->nbr);
		if (i > times_revrota_rotb(stack_a, stack_b, tmp->nbr))
			i = times_revrota_rotb(stack_a, stack_b, tmp->nbr);
		if (i > times_rot_a_revrotb(stack_a, stack_b, tmp->nbr))
			i = times_rot_a_revrotb(stack_a, stack_b, tmp->nbr);
		tmp = tmp->next;
	}
	return (i);
}

int	what_type_rotate_ba(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	t_stack	*tmp;

	tmp = stack_b;
	i = times_reverse_rotate_stacks(stack_b, stack_a, stack_b->nbr);
	while (tmp)
	{
		if (i > times_rotate_stacks(stack_b, stack_a, tmp->nbr))
			i = times_rotate_stacks(stack_b, stack_a, tmp->nbr);
		if (i > times_reverse_rotate_stacks(stack_b, stack_a, tmp->nbr))
			i = times_reverse_rotate_stacks(stack_b, stack_a, tmp->nbr);
		if (i > times_revrota_rotb(stack_a, stack_b, tmp->nbr))
			i = times_revrota_rotb(stack_a, stack_b, tmp->nbr);
		if (i > times_rot_a_revrotb(stack_a, stack_b, tmp->nbr))
			i = times_rot_a_revrotb(stack_a, stack_b, tmp->nbr);
		tmp = tmp->next;
	}
	return (i);
}