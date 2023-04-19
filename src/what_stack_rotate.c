/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_stack_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:22:43 by crtorres          #+#    #+#             */
/*   Updated: 2023/04/19 15:25:48 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	times_rotate_stacks(t_stack *stack_a, t_stack *stack_b, int j, char c)
{
	int	i;

	i = 0;
	if (c == 'B')
	{
		i = checkplace_instack_b(stack_b, j);
		if (i < index_in_stack(stack_a, j))
			i = index_in_stack(stack_a, j);
	}
	else if (c == 'A')
	{
		i = checkplace_instack(stack_a, j);
		if (i < index_in_stack(stack_b, j))
			i = index_in_stack(stack_b, j);
	}	
	return (i);
}

int	times_reverse_rotate_stacks(t_stack *stack_a, t_stack *stack_b, int j, char c)
{
	int	i;

	i = 0;
	if (c == 'B')
	{
		if (checkplace_instack_b(stack_b, j))
			i = ft_listsize(stack_b) - checkplace_instack(stack_b, j);
		if ((i < (ft_listsize(stack_a) - index_in_stack(stack_a, j))) && index_in_stack(stack_a, j))
			i = ft_listsize(stack_a) - index_in_stack(stack_a, j);
	}
	else if (c == 'A')
	{
		//printf("%ld\n", stack_a->nbr);
		if (checkplace_instack(stack_a, j))
			i = ft_listsize(stack_a) - checkplace_instack(stack_a, j);
		if ((i < (ft_listsize(stack_b) - index_in_stack(stack_b, j))) && index_in_stack(stack_b, j))
			i = ft_listsize(stack_b) - index_in_stack(stack_b, j);
		//!printf("entra\n");
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
		i = checkplace_instack_b(stack_b, j) + i;
	}	
	else if (c == 'A')
	{
		if (checkplace_instack(stack_a, j))
			i = ft_listsize(stack_a) - checkplace_instack(stack_a, j);
		i = index_in_stack(stack_b, j) + i;
	}
	return (i);
}

int	times_rot_a_revrotb(t_stack *stack_a, t_stack *stack_b, int j, char c)
{
	int	i;

	i = 0;
	if (c == 'B')
	{
		if (checkplace_instack_b(stack_b, j))
			i = ft_listsize(stack_b) - checkplace_instack_b(stack_b, j);
		i = index_in_stack(stack_a, j) + i;
	}
	else if (c == 'A')
	{
		if (index_in_stack(stack_b, j))
			i = ft_listsize(stack_b) - index_in_stack(stack_b, j);
		i = checkplace_instack(stack_a, j) + i;
	}
	return (i);
}

int	what_type_rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	t_stack	*tmp;

	tmp = stack_a;
	i = times_reverse_rotate_stacks(stack_a, stack_b, stack_a->nbr, 'B');
	while (tmp)
	{
		if (i > times_rotate_stacks(stack_a, stack_b, tmp->nbr, 'B'))
			i = times_rotate_stacks(stack_a, stack_b, tmp->nbr, 'B');
		if (i > times_reverse_rotate_stacks(stack_a, stack_b, tmp->nbr, 'B'))
			i = times_reverse_rotate_stacks(stack_a, stack_b, tmp->nbr, 'B');
		if (i > times_revrota_rotb(stack_a, stack_b, tmp->nbr, 'B'))
			i = times_revrota_rotb(stack_a, stack_b, tmp->nbr, 'B');
		if (i > times_rot_a_revrotb(stack_a, stack_b, tmp->nbr, 'B'))
			i = times_rot_a_revrotb(stack_a, stack_b, tmp->nbr, 'B');
		tmp = tmp->next;
	}
	return (i);
}

int	what_type_rotate_ba(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	t_stack	*tmp;

	tmp = stack_b;
	i = times_reverse_rotate_stacks(stack_a, stack_b, stack_b->nbr, 'A');
	while (tmp)
	{
		if (i > times_rotate_stacks(stack_a, stack_b, tmp->nbr, 'A'))
			i = times_rotate_stacks(stack_a, stack_b, tmp->nbr, 'A');
		if (i > times_reverse_rotate_stacks(stack_a, stack_b, tmp->nbr, 'A'))
			i = times_reverse_rotate_stacks(stack_a, stack_b, tmp->nbr, 'A');
		if (i > times_revrota_rotb(stack_a, stack_b, tmp->nbr, 'A'))
			i = times_revrota_rotb(stack_a, stack_b, tmp->nbr, 'A');
		if (i > times_rot_a_revrotb(stack_a, stack_b, tmp->nbr, 'A'))
			i = times_rot_a_revrotb(stack_a, stack_b, tmp->nbr, 'A');
		tmp = tmp->next;
	}
	return (i);
}