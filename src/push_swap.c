/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:22:02 by crtorres          #+#    #+#             */
/*   Updated: 2023/04/19 18:29:09 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	if (str[i] == '-')
	{
		sign = -1;
		i++;	
	}
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != 32 && (str[i] != 43 || str[i] != 45))
			exit_error("No number\n");
		j = (j * 10) + (str[i] - '0');
		i++;
	}
	if ((sign * j) > 2147483647 || (sign * j) < -2147483648)
		exit_error("the number must be between the MAX and MIN value of int\n");
		//printf("sign = %lld\n", j);
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
		i++;
	}
	free_str(tmp);
	free (tmp);
	return (a);
}

/**
 * The function checks the arguments passed to the program and creates a stack
 * based on the arguments.
 * 
 * @param argc The number of arguments passed to the program, including the name of
 * the program itself.
 * @param argv An array of strings containing the command line arguments passed to
 * the program, where each string represents a number to be sorted by the program.
 * 
 * @return The function `check_args_create_stack` is returning a pointer to a
 * `t_stack` struct.
 */
t_stack	*check_args_create_stack(int argc, char **argv)
{
	t_stack		*stack_a;
	int			i;
	int			j;

	i = 1;
	j = 0;
	stack_a = NULL;
	if (argc < 2)
		exit_error("Invalid numbers of arguments\n");
	if (argc == 2)
		stack_a = swap_spaces_for_nodes(argv);
	else
	{
		while (i < argc)
		{
			j = ft_atoi_ps(argv[i]);
			ft_stacklist_add_back(&stack_a, ft_stack_new(j));
			i++;
		}
	}
	return (stack_a);
}
void	ft_leaks()
{
	system("leaks -q push_swap");
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	
	atexit(ft_leaks);
	stack_a = check_args_create_stack(argc, argv);
	if (!stack_a || duplicate_nbr(stack_a))
	{
		ft_free_stack(&stack_a);
		exit_error("no stack o nº duplicado");
	}
	if (!ft_is_sorted(stack_a))
		sort_with_quicksort(&stack_a);
	ft_free_stack(&stack_a);
	return (0);
}
