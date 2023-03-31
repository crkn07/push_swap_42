/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:22:02 by crtorres          #+#    #+#             */
/*   Updated: 2023/03/31 17:29:19 by crtorres         ###   ########.fr       */
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
		ft_stacklist_add_back(&a, )
	}
}
int	main(int argc, char **argv)
{
	t_stack		*a;

	if (argc < 2)
		exit_error("Invalid numbers of arguments\n");
	if (argc == 2)
	{
		
	}
}