/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_msg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:17:40 by crtorres          #+#    #+#             */
/*   Updated: 2023/03/31 16:45:48 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
/**
 * It takes a string of numbers separated by spaces, and returns a linked list of
 * those numbers
 * 
 * @param argv the arguments passed to the program
 * 
 * @return A pointer to a stack.
 */
t_stack	*ft_sub_process(char **argv)
{
	t_stack	*a;
	char	**tmp;
	int		i;
	int		j;

	a = NULL;
	i = 0;
	tmp = ft_split(argv[1], 32);
	while (tmp[i])
	{
		j = ft_atoi2(tmp[i]);
		ft_add_back(&a, ft_stack_new(j));
		i++;
	}
	ft_freestr(tmp);
	free(tmp);
	return (a);
}