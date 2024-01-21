/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 10:44:48 by lofiorin          #+#    #+#             */
/*   Updated: 2023/10/15 10:44:51 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest_cpy;
	char	*src_cpy;

	dest_cpy = (char *)dest;
	src_cpy = (char *)src;
	if (!dest && !src)
		return (NULL);
	while (n-- > 0)
	{
		*dest_cpy = *src_cpy;
		dest_cpy++;
		src_cpy++;
	}
	return (dest);
}
