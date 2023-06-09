/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:22:02 by crtorres          #+#    #+#             */
/*   Updated: 2023/05/30 17:08:04 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_atoi_ps(char *str)
{
	int				sign;
	int				i;
	long long int	j;

	i = 0;
	j = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (ft_is_nbr_space_valid(str) == 0)
		exit_error("error\n");
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i])
	{
		j = (j * 10) + (str[i] - '0');
		i++;
	}
	if ((sign * j) > 2147483647 || (sign * j) < -2147483648)
		exit_error("error\n");
	return (sign * j);
}

int	ft_is_nbr_space_valid(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) > 11)
		exit_error("error\n");
	while (str[i])
	{
		if (str[i] == ' ' || ft_isdigit(str[i]) == 1)
			i++;
		else if (i == 0 && ((str[i] == '-' || str[i] == '+')
				&& ft_isdigit(str[i + 1]) == 1))
			i++;
		else
			return (0);
	}
	return (1);
}

/**
 * This function creates a stack by parsing command line arguments and adding
 * them to the stack.
 *
 * @param argc The number of arguments passed to the program.
 * @param argv argv is a pointer to an array of strings, where each string
 * represents a command line argument passed to the program.
 *
 * @return The function returns a pointer to a stack data structure.
 */
t_stack	*create_stack(int argc, char **argv)
{
	t_stack		*stack_a;
	int			i;
	int			j;
	int			y;
	char		**tmp;

	i = 1;
	stack_a = NULL;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			exit_error("error\n");
		tmp = ft_split(argv[i], 32);
		y = 0;
		while (tmp[y])
		{
			j = ft_atoi_ps(tmp[y]);
			ft_stacklist_add_back(&stack_a, ft_new_stack(j));
			y++;
		}
		free_matrix (tmp);
		i++;
	}
	return (stack_a);
}

int	duplicate_nbr(t_stack *stack_a)
{
	t_stack	*tmp;

	while (stack_a)
	{
		tmp = stack_a->next;
		while (tmp)
		{
			if (stack_a->nbr == tmp->nbr)
				return (1);
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
	return (0);
}
