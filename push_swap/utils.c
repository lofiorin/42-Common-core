/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <lofiorin@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 20:07:48 by lofiorin          #+#    #+#             */
/*   Updated: 2024/04/25 11:13:51 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_dllstnew(int content)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node) * 1);
	if (!new)
		return (NULL);
	new -> value = content;
	new -> prev = NULL;
	new -> next = NULL;
	new -> target = NULL;
	new -> above_m = false;
	new -> cheap = false;
	return (new);
}

t_node	*ft_dllstlast(t_node *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst)
	{
		if (lst -> next == NULL)
			return (lst);
		lst = lst -> next;
	}
	return (lst);
}

void	ft_dllstadd_back(t_node **lst, t_node *new)
{
	t_node	*last;

	if (new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_dllstlast(*lst);
		last -> next = new;
		last -> next -> prev = last;
	}
}

int	ft_dllstsize(t_node *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int	ft_list_sorted(t_node *a)
{
	t_node	*min;
	t_node	*tmp;

	if (!a)
		return (0);
	min = min_node(a);
	tmp = min;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	if (tmp->value > a->value && min != a)
		return (0);
	tmp = a;
	while (tmp->next != min && min != a)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
