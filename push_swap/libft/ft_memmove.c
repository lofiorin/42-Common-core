/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 10:45:23 by lofiorin          #+#    #+#             */
/*   Updated: 2023/10/15 10:45:24 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_cpy;
	unsigned char	*src_cpy;

	src_cpy = (unsigned char *) src;
	dest_cpy = (unsigned char *) dest;
	if (dest_cpy == src_cpy)
		return (dest);
	if (dest_cpy >= src_cpy && dest_cpy <= src_cpy + n)
	{
		dest_cpy += n;
		src_cpy += n;
		while (n--)
			*--dest_cpy = *--src_cpy;
		return (dest);
	}
	while (n--)
		*dest_cpy++ = *src_cpy++;
	return (dest);
}
