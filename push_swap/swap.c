/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <lofiorin@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:37:15 by lofiorin          #+#    #+#             */
/*   Updated: 2024/04/25 09:41:57 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_node **node, char stack, bool print)
{
	if (!*node || !(*node)->next)
		return ;
	*node = (*node)->next;
	(*node)->prev->prev = *node;
	(*node)->prev->next = (*node)->next;
	if ((*node)->next)
		(*node)->next->prev = (*node)->prev;
	(*node)->next = (*node)->prev;
	(*node)->prev = NULL;
	if (print == true)
		ft_printf("s%c\n", stack);
}

void	ss(t_node **a, t_node **b, bool print)
{
	if (print == true)
		ft_printf("ss\n");
	s(a, 'a', false);
	s(b, 'b', false);
}
