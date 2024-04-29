/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <lofiorin@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:37:23 by lofiorin          #+#    #+#             */
/*   Updated: 2024/04/24 11:37:48 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*max_node(t_node *node)
{
	t_node	*max;

	if (!node)
		return (NULL);
	max = node;
	node = node->next;
	while (node)
	{
		if (node->value > max->value)
			max = node;
		node = node->next;
	}
	return (max);
}

t_node	*min_node(t_node *node)
{
	t_node	*min;

	if (!node)
		return (NULL);
	min = node;
	node = node->next;
	while (node)
	{
		if (node->value < min->value)
			min = node;
		node = node->next;
	}
	return (min);
}

void	push_init(t_node **node, t_node *top, char stack)
{
	while (*node != top)
	{
		if (top->above_m)
			r(node, stack, true);
		else
			rr(node, stack, true);
	}
}

t_node	*get_cheap(t_node *node)
{
	if (!node)
		return (NULL);
	while (node)
	{
		if (node->cheap)
			return (node);
		node = node->next;
	}
	return (NULL);
}

void	*free_list(t_node **node)
{
	t_node	*tmp;
	t_node	*node_cpy;

	if (!node)
		return (NULL);
	node_cpy = *node;
	while (node_cpy)
	{
		tmp = node_cpy->next;
		free(node_cpy);
		node_cpy = tmp;
	}
	*node = NULL;
	return (NULL);
}
