/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <lofiorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:17:55 by lofiorin          #+#    #+#             */
/*   Updated: 2024/01/26 14:28:17 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_base_nb(long long nbr, char *base, int size)
{
	char			a;
	unsigned long	n;
	int				len;

	len = 0;
	if (nbr < 0 && size == 10)
	{
		len += write(1, "-", 1);
		n = nbr * (-1);
	}
	else
		n = nbr;
	if (n >= (unsigned long)size)
		len += print_base_nb(n / size, base, size);
	a = base[n % size];
	len += write(1, &a, 1);
	return (len);
}

int	ft_putnbr_base(unsigned long nbr, char *base)
{
	int	b_size;
	int	len;

	b_size = 0;
	len = 0;
	while (base[b_size] != '\0')
		b_size++;
	len += print_base_nb(nbr, base, b_size);
	return (len);
}
