/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:19:33 by crtorres          #+#    #+#             */
/*   Updated: 2023/04/13 17:24:50 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * The function checks if a given stack is sorted in ascending order.
 * 
 * @param stack_a `stack_a` is a pointer to the top of a stack data structure. 
 * The function `ft_is_sorted` checks if the elements in the stack are sorted 
 * in ascending order.
 * 
 * @return The function `ft_is_sorted` is returning an integer value of 1 if 
 * the stack `stack_a` is sorted in ascending order, and 0 otherwise.
 */
int	ft_is_sorted(t_stack *stack_a)
{
	int	i;

	i = stack_a->nbr;
	while (stack_a)
	{
		if (stack_a->nbr < i)
			return (0);
		i = stack_a->nbr;
		stack_a = stack_a->next;
	}
	return (1);
}
//?falta completar las funciones
void	ft_sort_untill_3members(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*tmp;

	while (ft_listsize(*stack_a) > 3 && !ft_is_sorted(*stack_a))
	{
		tmp = stack_a;
		i = what_type_rotate_ab
	}
}
//?falta completar las funciones
t_stack	*sorted_stack_b(t_stack **stack_a)
{
	t_stack	*stack_b;
	
	stack_b = NULL;
	while (ft_listsize(*stack_a) > 3 && !ft_is_sorted(*stack_a))
		ft_push_ab(stack_a, &stack_b, 1);
	if (ft_listsize(*stack_a) > 3 && !ft_is_sorted(*stack_a))
	if (!ft_is_sorted(*stack_a))
	return (stack_b);
}
