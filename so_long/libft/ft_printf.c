/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <lofiorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:57:18 by lofiorin          #+#    #+#             */
/*   Updated: 2024/01/26 14:28:11 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putptr(void *p)
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

static int	check_conv(const char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		len += ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'p')
		len += ft_putptr(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		len += ft_putnbr_base(va_arg(args, int), "0123456789");
	else if (c == 'u')
		len += ft_putnbr_base(va_arg(args, unsigned int), "0123456789");
	else if (c == 'x')
		len += ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		len += ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		len += ft_putchar_fd('%', 1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			len += check_conv(str[++i], args);
		else
			len += ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
