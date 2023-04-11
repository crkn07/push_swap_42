/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_msg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:17:40 by crtorres          #+#    #+#             */
/*   Updated: 2023/04/10 12:51:14 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
