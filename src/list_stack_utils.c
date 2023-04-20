/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:26:50 by crtorres          #+#    #+#             */
/*   Updated: 2023/04/20 23:35:31 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * The function adds a new node to the end of a linked list representing a
 * stack.
 *
 * @param stack A pointer to a pointer to the first node of a stack
 * @param new_node The new node that needs to be added to the end of the stack.
 *
 * @return If the `stack` parameter is `NULL`, the function returns without
 * doing anything. Otherwise, the function adds the `new_node` to the end of
 * the `stack` and does not return anything.
 */
void	ft_stacklist_add_back(t_stack **stack, t_stack *new_node)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = new_node;
	else
		(ft_listlast(*stack))->next = new_node;
}

int	ft_listsize(t_stack *lst)
{
	size_t	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

/**
 * The function creates a new stack node with the given content.
 *
 * @param content This parameter is an integer value that will be assigned
 * to the "nbr" field of the newly created t_stack struct.
 *
 * @return The function returns a pointer to a newly created structure.
 */
t_stack	*ft_new_stack(int content)
{
	t_stack	*new;

	new = malloc(sizeof (t_stack));
	if (!new)
		exit_error("no hay nuevo");
	new->nbr = content;
	new->next = NULL;
	return (new);
}

/**
 * The function returns the last element of a linked list.
 *
 * @param lst lst is a pointer to the first node of a linked list.
 *
 * @return The function returns a pointer to the last node of the linked list.
 * If the list is empty, the function returns `0` (or `NULL`).
 */
t_stack	*ft_listlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
