/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <lofiorin@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:36:53 by lofiorin          #+#    #+#             */
/*   Updated: 2024/04/25 09:40:04 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **dest, t_node **source, char stack)
{
	t_node	*push;

	if (!*source)
		return ;
	push = *source;
	*source = (*source)->next;
	if (*source)
		(*source)->prev = NULL;
	push->prev = NULL;
	if (!*dest)
	{
		*dest = push;
		push->next = NULL;
	}
	else
	{
		push->next = *dest;
		push->next->prev = push;
		*dest = push;
	}
	if (stack != 'c')
		ft_printf("p%c\n", stack);
}
