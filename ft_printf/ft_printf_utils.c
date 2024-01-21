/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <lofiorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:06:30 by lofiorin          #+#    #+#             */
/*   Updated: 2024/01/14 18:41:23 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return (ft_putstr_fd("(null)", fd));
	return (write(fd, s, ft_strlen(s)));
}

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

int	ft_putptr(void *p)
{
	int			len;
	uintptr_t	v;

	v = (uintptr_t)p;
	len = 0;
	if (!p)
		return (ft_putstr_fd("(nil)", 1));
	len += write(1, "0x", 2);
	len += ft_putnbr_base(v, "0123456789abcdef");
	return (len);
}
