/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_stack_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:22:43 by crtorres          #+#    #+#             */
/*   Updated: 2023/04/13 15:31:41 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	times_rotate_ab(t_stack **stack_a, t_stack **stack_b, int j)
{
	int	i;

	i = checkplace_instack(stack_b, j);
	if (i < index_in_stack(stack_a, j))
		i = index_in_stack(stack_a, j);
	return (i);
}

int	times_reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b, int j)
{
	int	i;

	i = 0;
	if (checkplace_instack(stack_b, j))
		i = ft_listsize(stack_b) - checkplace_instack(stack_b, j);
	if ((i < (ft_listsize(stack_a) - index_in_stack(stack_a, j)))
		&& index_in_stack(stack_a, j))
		i = ft_listsize(stack_a) - index_in_stack(stack_a, j);
	return (i);
}

int	times_rra_rb(t_stack **stack_a, t_stack **stack_b, int j)
{
	int	i;
	
	i = 0;
	if (index_in_stack(stack_a, j))
		i = ft_listsize(stack_a) - index_in_stack(stack_a, j);
	i = checkplace_instack(stack_b, j) - i;
	return (i);
}

int	times_ra_rrb(t_stack **stack_a, t_stack **stack_b, int j)
{
	int	i;

	i = 0;
	if (checkplace_instack(stack_b, j))
		i = ft_listsize(stack_b) - checkplace_instack(stack_b, j);
	i = index_in_stack(stack_a, j) - i;
}

int	what_type_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	t_stack	*tmp;

	tmp = stack_b;
	
}