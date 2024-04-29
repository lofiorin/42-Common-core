/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <lofiorin@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:36:33 by lofiorin          #+#    #+#             */
/*   Updated: 2024/04/29 20:41:57 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	read_moves(t_node **a, t_node **b, char *c)
{
	if (!c)
		return (0);
	if (!ft_strncmp(c, "pa\n", 3))
		return (free(c), push(a, b, 'c'), 1);
	else if (!ft_strncmp(c, "pb\n", 3))
		return (free(c), push(b, a, 'c'), 1);
	else if (!ft_strncmp(c, "sa\n", 3))
		return (free(c), s(a, 'a', false), 1);
	else if (!ft_strncmp(c, "sb\n", 3))
		return (free(c), s(b, 'b', false), 1);
	else if (!ft_strncmp(c, "ss\n", 3))
		return (free(c), ss(a, b, false), 1);
	else if (!ft_strncmp(c, "ra\n", 3))
		return (free(c), r(a, 'a', false), 1);
	else if (!ft_strncmp(c, "rb\n", 3))
		return (free(c), r(b, 'b', false), 1);
	else if (!ft_strncmp(c, "rr\n", 3))
		return (free(c), rs(a, b, false), 1);
	else if (!ft_strncmp(c, "rra\n", 4))
		return (free(c), rr(a, 'a', false), 1);
	else if (!ft_strncmp(c, "rrb\n", 4))
		return (free(c), rr(b, 'b', false), 1);
	else if (!ft_strncmp(c, "rrr\n", 4))
		return (free(c), rrs(a, b, false), 1);
	return (free(c), ft_putendl_fd("Error", 2), 2);
}

static int	ft_sorted(t_node *a)
{
	if (!a)
		return (0);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	char	**args;
	t_node	*a;
	t_node	*b;
	int		c;

	b = NULL;
	args = check_arg_num(ac, av);
	if (!args)
		return (0);
	a = stack_init(args, NULL);
	if (!a)
		return (ft_free_mat(args), 1);
	c = read_moves(&a, &b, get_next_line(0));
	while (c)
	{
		if (c == 2)
			return (ft_free_mat(args), free_list(&a), 1);
		c = read_moves(&a, &b, get_next_line(0));
	}
	ft_free_mat(args);
	if (ft_sorted(a))
		return (ft_printf("OK\n"), free_list(&a), 0);
	else
		return (ft_printf("KO\n"), free_list(&a), 0);
}
