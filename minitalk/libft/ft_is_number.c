/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <lofiorin@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:57:04 by lofiorin          #+#    #+#             */
/*   Updated: 2024/04/23 21:32:08 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_number(char *s)
{
	int	num;
	int	sign;

	num = 0;
	sign = 0;
	while (s && *s)
	{
		if ((*s < '0' || *s > '9') && *s != '+' && *s != '-')
			return (0);
		else if (*s >= '0' && *s <= '9')
			num++;
		else if (num != 0 && (*s < '0' || *s > '9'))
			return (0);
		else if (*s == '+' || *s == '-')
			sign++;
		s++;
	}
	if (num == 0 || sign > 1)
		return (0);
	return (1);
}
