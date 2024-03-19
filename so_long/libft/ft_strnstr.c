/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:49:44 by lofiorin          #+#    #+#             */
/*   Updated: 2023/10/15 13:49:45 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*big_cpy;
	size_t	l_len;

	big_cpy = (char *) big;
	l_len = ft_strlen(little);
	if (ft_strlen(little) == 0)
		return (big_cpy);
	while (len > 0 && *big_cpy)
	{
		if (*big_cpy == *little)
		{
			if (ft_strncmp(big_cpy, little, l_len) == 0
				&& l_len <= len)
				return (big_cpy);
		}
		big_cpy++;
		len--;
	}
	return (NULL);
}
