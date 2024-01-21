/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 10:45:57 by lofiorin          #+#    #+#             */
/*   Updated: 2023/10/15 10:45:58 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*res;

	i = 0;
	res = (char *)s;
	while (i <= ft_strlen(s))
	{
		if (res[i] == (unsigned char)c)
			return (&res[i]);
		i++;
	}
	return (0);
}
