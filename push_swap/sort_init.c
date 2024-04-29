/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <lofiorin@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:37:00 by lofiorin          #+#    #+#             */
/*   Updated: 2024/04/24 11:46:51 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_node *node)
{
	int	i;
	int	len;

	i = 0;
	len = ft_dllstsize(node);
	while (node)
	{
		node->index = i;
		if (node->index <= len / 2)
			node->above_m = true;
		else
			node->above_m = false;
		i++;
		node = node->next;
	}
}

static void	set_target_a(t_node *a, t_node *b)
{
	long	diff;
	t_node	*b_cpy;

	while (a)
	{
		diff = MAX_LONG;
		b_cpy = b;
		while (b_cpy)
		{
			if (b_cpy->value < a->value)
			{
				if (a->value - b_cpy->value < diff)
				{
					diff = a->value - b_cpy->value;
					a->target = b_cpy;
				}
			}
			b_cpy = b_cpy->next;
		}
		if (diff == MAX_LONG)
			a->target = max_node(b);
		a = a->next;
	}
}

static void	set_target_b(t_node *a, t_node *b)
{
	t_node	*a_cpy;
	t_node	*target;
	long	nbr;

	while (b)
	{
		nbr = MAX_LONG;
		a_cpy = a;
		while (a_cpy)
		{
			if (a_cpy->value > b->value && a_cpy->value < nbr)
			{
				nbr = a_cpy->value;
				target = a_cpy;
			}
			a_cpy = a_cpy->next;
		}
		if (nbr == MAX_LONG)
			b->target = min_node(a);
		else
			b->target = target;
		b = b->next;
	}
}

static void	set_cost(t_node *a, t_node *b)
{
	int		a_len;
	int		b_len;
	int		cheap;
	t_node	*cheap_node;

	a_len = ft_dllstsize(a);
	b_len = ft_dllstsize(b);
	cheap = MAX_INT;
	while (a)
	{
		a->cost = a->index;
		if (!(a->above_m))
			a->cost = a_len - (a->index);
		if (a->target->above_m)
			a->cost += a->target->index;
		else
			a->cost += b_len - (a->target->index);
		if (a->cost < cheap)
		{
			cheap = a->cost;
			cheap_node = a;
		}
		a = a->next;
	}
	cheap_node->cheap = true;
}

void	sort_init(t_node *a, t_node *b)
{
	set_index(a);
	set_index(b);
	set_target_a(a, b);
	set_target_b(a, b);
	set_cost(a, b);
}
