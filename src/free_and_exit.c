/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:19:15 by crtorres          #+#    #+#             */
/*   Updated: 2023/04/21 12:06:09 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// The function frees a stack by iterating through it and freeing each node.
void	ft_free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		(*stack)->nbr = 0;
		free(*stack);
		*stack = tmp;
	}
}

/**
 * The function frees the memory allocated for a matrix of strings.
 *
 * @param c c is a pointer to a pointer of characters, which represents a
 * 2D matrix (array of strings).
 */
void	free_matrix(char **c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		free(c[i]);
		i++;
	}
	free (c);
}

void	exit_error(char *msg)
{
	ft_putstr_fd(RED "-*-*-*-*-*-*-*-*-*-*-\n\n" RESET, 2);
	ft_putstr_fd(BG_RED, 2);
	ft_putstr_fd("Error", 2);
	ft_putstr_fd(RESET, 2);
	ft_putstr_fd("\n\n", 2);
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("-*-*-*-*-*-*-*-*-*-*-*-*-\n", 2);
	ft_putstr_fd(RESET, 2);
	exit (EXIT_FAILURE);
}
