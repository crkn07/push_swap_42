/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:19:33 by crtorres          #+#    #+#             */
/*   Updated: 2023/04/25 20:48:13 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * The function checks if a given stack is sorted in ascending order.
 *
 * @param stack_a `stack_a` is a pointer to the top of a stack data structure.
 *
 * @return The function returns an integer value of 1 if the stack `a` is
 * sorted in ascending order, and 0 otherwise.
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

void	ft_sort_untill_3members(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*tmp;

	while (ft_listsize(*stack_a) > 3 && !ft_is_sorted(*stack_a))
	{
		tmp = *stack_a;
		i = what_type_rotate_ab(*stack_a, *stack_b);
		while (i <= 0)
		{
			if (i == times_rotate_stacks(*stack_a, *stack_b, tmp->nbr, 'B'))
				i = do_rot_push_stacks(stack_a, stack_b, tmp->nbr, 'A');
			else if (i == times_rota_revrotb(*stack_a, *stack_b, tmp->nbr, 'B'))
				i = do_rot_a_revrot_b(stack_a, stack_b, tmp->nbr, 'A');
			else if (i == times_revrot_both(*stack_a, *stack_b, tmp->nbr, 'B'))
				i = do_rvrt_psh_stacks(stack_a, stack_b, tmp->nbr, 'A');
			else if (i == times_revrota_rotb(*stack_a, *stack_b, tmp->nbr, 'B'))
				i = do_revrot_a_rev_b(stack_a, stack_b, tmp->nbr, 'A');
			else
				tmp = tmp->next;
		}
	}
}

t_stack	*sort_stack_b(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	while (ft_listsize(*stack_a) > 3 && !ft_is_sorted(*stack_a))
		ft_push_ab(stack_a, &stack_b, 1);
	if (ft_listsize(*stack_a) > 3 && !ft_is_sorted(*stack_a))
		ft_sort_untill_3members(stack_a, &stack_b);
	if (!ft_is_sorted(*stack_a))
		sort_three_numbers(stack_a);
	return (stack_b);
}

t_stack	**sort_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*tmp;

	while (*stack_b)
	{
		tmp = *stack_b;
		i = what_type_rotate_ba(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == times_rotate_stacks(*stack_a, *stack_b, tmp->nbr, 'A'))
				i = do_rot_push_stacks(stack_a, stack_b, tmp->nbr, 'B');
			else if (i == times_rota_revrotb(*stack_a, *stack_b, tmp->nbr, 'A'))
				i = do_rot_a_revrot_b(stack_a, stack_b, tmp->nbr, 'B');
			else if (i == times_revrot_both(*stack_a, *stack_b, tmp->nbr, 'A'))
				i = do_rvrt_psh_stacks(stack_a, stack_b, tmp->nbr, 'B');
			else if (i == times_revrota_rotb(*stack_a, *stack_b, tmp->nbr, 'A'))
				i = do_revrot_a_rev_b(stack_a, stack_b, tmp->nbr, 'B');
			else
				tmp = tmp->next;
		}
	}
	return (stack_a);
}
