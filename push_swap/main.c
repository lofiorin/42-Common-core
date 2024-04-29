/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <lofiorin@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:51:44 by lofiorin          #+#    #+#             */
/*   Updated: 2024/04/24 11:37:34 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	**args;
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	args = check_arg_num(ac, av);
	if (!args)
		return (0);
	a = stack_init(args, a);
	if (!a)
		return (ft_free_mat(args), 1);
	if (!ft_list_sorted(a))
	{
		if (ft_dllstsize(a) == 2)
			s(&a, 'a', true);
		else if (ft_dllstsize(a) == 3)
			minisort(&a, 'a');
		else
			sort(&a, &b);
	}
	min_up(&a);
	free_list(&a);
	ft_free_mat(args);
	return (0);
}
