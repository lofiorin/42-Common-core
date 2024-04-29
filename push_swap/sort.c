/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <lofiorin@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:37:09 by lofiorin          #+#    #+#             */
/*   Updated: 2024/04/25 11:07:35 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	r_both(t_node **a, t_node **b, t_node *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		rs(a, b, true);
	set_index(*a);
	set_index(*b);
}

static void	rr_both(t_node **a, t_node **b, t_node *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		rrs(a, b, true);
	set_index(*a);
	set_index(*b);
}

static void	sort_a(t_node **a, t_node **b)
{
	t_node	*cheapest;

	cheapest = get_cheap(*a);
	if (cheapest->above_m && cheapest->target->above_m)
		r_both(a, b, cheapest);
	else if (!(cheapest->above_m) && !(cheapest->target->above_m))
		rr_both(a, b, cheapest);
	push_init(a, cheapest, 'a');
	push_init(b, cheapest->target, 'b');
	push(b, a, 'b');
}

static void	sort_b(t_node **a, t_node **b)
{
	push_init(a, (*b)->target, 'a');
	push(a, b, 'a');
}

void	sort(t_node **a, t_node **b)
{
	int	a_len;

	a_len = ft_dllstsize(*a);
	if (a_len-- > 3 && !ft_list_sorted(*a))
		push(b, a, 'b');
	while (a_len-- > 3 && !ft_list_sorted(*a))
	{
		sort_init(*a, *b);
		sort_a(a, b);
	}
	minisort(a, 'a');
	while (*b)
	{
		sort_init(*a, *b);
		sort_b(a, b);
	}
	set_index(*a);
	min_up(a);
}
