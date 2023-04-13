/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:19:15 by crtorres          #+#    #+#             */
/*   Updated: 2023/04/13 11:50:45 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// * The function frees a stack by iterating through it and freeing each node.
void	ft_free_stack(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)-> next;
		(*lst)->nbr = 0;
		free(*lst);
		*lst = tmp;
	}
}

//* libera un string cuando se pasa entre comillas 
void	free_str(char **lst)
{
	char	*n1;

	if (!lst)
		return ;
	while (*lst)
	{
		n1 = *lst;
		lst++;
		free(n1);
	}
	*lst = NULL;
}