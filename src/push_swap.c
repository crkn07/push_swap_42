/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:22:02 by crtorres          #+#    #+#             */
/*   Updated: 2023/04/04 18:37:56 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_atoi_ps(const char *str)
{
	int				sign;
	int				i;
	long long int	j;

	i = 0;
	j = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i++] == '-')
		sign = -1;
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			exit_error("No number\n");
		j = (j * 10) + (str[i] - '0');
		i++;
	}
	if ((sign * j) > 2147483647 || (sign * j) < -2147483648)
		exit_error("the number must be between the MAX and MIN value of int\n");
	return (sign * j);
}

/**
 * It takes a string of numbers separated by spaces, and returns a linked list
 * of those numbers
 * 
 * @param argv the arguments passed to the program
 * 
 * @return A pointer to a stack.
 */
t_stack	*swap_spaces_for_nodes(char **argv)
{
	t_stack	*a;
	int		i;
	int		j;
	char 	**tmp;

	a = NULL;
	i = 0;
	tmp = ft_split(argv[1], 32);
	while (tmp[i])
	{
		j = ft_atoi_ps(tmp[i]);
		ft_stacklist_add_back(&a, ft_stack_new(j));
	}
	free_str(tmp);
	free (tmp);
	return (a);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	int			i;
	int			j;
	
	if (argc < 2)
		exit_error("Invalid numbers of arguments\n");
	if (argc == 2)
		a = swap_spaces_for_nodes(argv);
	else
	{
		i = 1;
		while (i < argc)
		{
			j = ft_atoi_ps(argv[i]);
			ft_stacklist_add_back(&a, ft_stack_new(j));
			i++;
		}
	}
	if (!a || duplicate_nbr(a))
	{
		ft_free_stack(a);
		exit_error("no stack o nº duplicado");
	}
	return (a);
}
