/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:27:59 by crtorres          #+#    #+#             */
/*   Updated: 2023/04/19 18:09:43 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

//===SETTINGS COLORS===/
//===Color font code===/
# define BLACK   "\x1B[30m"
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define WHITE   "\x1B[37m"
# define ORANGE  "\x1B[38;2;255;128;0m"
# define ROSE    "\x1B[38;2;255;151;203m"
# define LBLUE   "\x1B[38;2;53;149;240m"
# define LGREEN  "\x1B[38;2;17;245;120m"
# define GRAY    "\x1B[38;2;176;174;174m"
//===Color background code===/
# define BG_BLACK   "\x1B[40m"
# define BG_RED     "\x1B[41m"
# define BG_GREEN   "\x1B[42m"
# define BG_YELLOW  "\x1B[43m"
# define BG_BLUE    "\x1B[44m"
# define BG_MAGENTA "\x1B[45m"
# define BG_CYAN    "\x1B[46m"
# define BG_WHITE   "\x1B[47m"
# define BG_ORANGE  "\x1B[48;2;255;128;0m"
# define BG_LBLUE   "\x1B[48;2;53;149;240m"
# define BG_LGREEN  "\x1B[48;2;17;245;120m"
# define BG_GRAY    "\x1B[48;2;176;174;174m"
# define BG_ROSE    "\x1B[48;2;255;151;203m"

# define RESET   "\x1b[0m"

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

void	exit_error(char *msg);
void	ft_stacklist_add_back(t_stack **stack, t_stack *new_node);
void	ft_stacklist_add_front(t_stack **stack, t_stack *new_node);
int		ft_atoi_ps(const char *str);
t_stack	*ft_stack_new(int content);
t_stack	*ft_listlast(t_stack *lst);
void	free_str(char **lst);
void	ft_free_stack(t_stack **stack);
int		duplicate_nbr(t_stack *a);
int		ft_is_sorted(t_stack *stack_a);
void	sort_three_numbers(t_stack **stack_a);
int		ft_listsize(t_stack *lst);
void	ft_push_ab(t_stack **stack_a, t_stack **stack_b, int c);
void	ft_swap_ab(t_stack **stack, int c);
void	ft_rotate(t_stack **stack, int c);
void	ft_rotate_ab(t_stack **stack_a, t_stack **stack_b);
void	ft_reverse_rotate(t_stack **stack, int c);
t_stack	*sorted_stack_b(t_stack **stack_a);
t_stack	**sort_stack_a(t_stack **stack_a, t_stack **stack_b);
int		ft_max_int(t_stack *stack);
int		ft_min_int(t_stack *stack);
int		checkplace_instack(t_stack *stack, int nbr_push);
int		checkplace_instack_b(t_stack *stack, int nbr_push);
int		index_in_stack(t_stack *stack, int num);
int		times_rotate_stacks(t_stack *stack_1, t_stack *stack_2, int j, char c);
int		times_reverse_rotate_stacks(t_stack *stack_1, t_stack *stack_2, int j, char c);
int		times_revrota_rotb(t_stack *stack_1, t_stack *stack_2, int j, char c);
int		times_rot_a_revrotb(t_stack *stack_1, t_stack *stack_2, int j, char c);
int		what_type_rotate_ab(t_stack *stack_a, t_stack *stack_b);
int		what_type_rotate_ba(t_stack *stack_a, t_stack *stack_b);
int		do_rot_push_stacks(t_stack **stack_a, t_stack **stack_b, int j, char c);
int		do_revrot_push_stacks(t_stack **stack_a, t_stack **stack_b, int j, char c);
int		do_revrot_a_rev_b(t_stack **stack_a, t_stack **stack_b, int j, char c);
int		do_rot_a_revrot_b(t_stack **stack_a, t_stack **stack_b, int j, char c);
void	ft_reverse_rotate_both(t_stack **stack_a, t_stack **stack_b);
void	sort_with_quicksort(t_stack **stack_a);

#endif