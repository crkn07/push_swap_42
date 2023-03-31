/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:20:18 by crtorres          #+#    #+#             */
/*   Updated: 2023/03/31 17:25:34 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * If the list is empty, make the new node the head of the list. Otherwise, 
 * add the new node to the end of the list
 * 
 * @param lst A pointer to the first link of a list.
 * @param new the new element to add to the list
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!ft_lstlast(*lst))
		*lst = new;
	else
		ft_lstlast(*lst)-> next = new;
}

/**
 * It adds a new node to the end of a linked list
 * 
 * @param stack a pointer to a pointer to a t_stack.
 * @param stack_new the new node to add to the end of the list
 * 
 * @return The last element of the list.
 */
void	ft_add_back(t_stack **stack, t_stack *stack_new)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = stack_new;
	else
		(ft_lstlast(*stack))->next = stack_new;
}