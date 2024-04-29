/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minisort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <lofiorin@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:36:45 by lofiorin          #+#    #+#             */
/*   Updated: 2024/04/24 11:37:37 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	minisort(t_node **node, char stack)
{
	t_node	*biggest;

	biggest = max_node(*node);
	if (biggest == *node)
		r(node, stack, true);
	else if ((*node)->next == biggest)
		rr(node, stack, true);
	if ((*node)->value > (*node)->next->value)
		s(node, stack, true);
}
