/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 20:46:09 by yogun             #+#    #+#             */
/*   Updated: 2023/04/25 20:46:38 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_checker_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit (EXIT_FAILURE);
}

char	*check_moves(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		ft_swap(stack_a, 0);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		ft_swap(stack_b, 1);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		ft_rotate(stack_a, 0);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		ft_rotate(stack_b, 1);
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		ft_push_ab(stack_a, stack_b, 0);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		ft_push_ab(stack_a, stack_b, 1);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		ft_swap_ab(stack_a, stack_b, 2);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		ft_rotate_ab(stack_a, stack_b);
	else if (line[0] == 'r' && line[2] == 'a' && line[3] == '\n')
		ft_reverse_rotate(stack_a, 0);
	else if (line[0] == 'r' && line[2] == 'b' && line[3] == '\n')
		ft_reverse_rotate(stack_b, 1);
	else if (line[0] == 'r' && line[2] == 'r' && line[3] == '\n')
		ft_rotate_ab(stack_a, stack_b);
	else
		ft_checker_error("error\n");
	return (get_next_line(0));
}

void	checker(t_stack **stack_a, t_stack **stack_b, char *line)
{
	char	*tmp;

	while (line && *line != '\n')
	{
		tmp = line;
		line = check_moves(stack_a, stack_b, line);
		free (tmp);
	}
	if (*stack_b)
		write(1, "KO\n", 3);
	else if (!ft_is_sorted(*stack_a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free (line);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	stack_b = NULL;
	stack_a = create_stack(argc, argv);
	if (duplicate_nbr(stack_a))
	{
		ft_free_stack(&stack_a);
		exit_error("duplicated number or no stack");
	}
	if (!stack_a)
		exit (0);
	line = get_next_line(0);
	if (!line && !ft_is_sorted(stack_a))
		write(1, "KO\n", 3);
	else if (!line && ft_is_sorted(stack_a))
		write(1, "OK\n", 3);
	else
		checker(&stack_a, &stack_b, line);
	ft_free_stack(&stack_b);
	ft_free_stack(&stack_a);
	return (0);
}
