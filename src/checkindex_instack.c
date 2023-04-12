/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkindex_instack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:34:39 by crtorres          #+#    #+#             */
/*   Updated: 2023/04/11 22:15:06 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	index_in_stack(t_stack *stack, int num)
{
	int	i;

	i = 0;
	while (stack->nbr != num)
	{
		stack = stack->next;
		i++;
	}
	stack->index = 0;
	return (i);
}

int	checkindex_stack_a(t_stack *stack_a, int nbr_push)
{
	int	i;
	t_stack *tmp;

	i = 1;
	
}