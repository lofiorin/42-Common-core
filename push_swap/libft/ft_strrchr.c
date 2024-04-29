/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 10:47:09 by lofiorin          #+#    #+#             */
/*   Updated: 2023/10/15 10:47:11 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s_cpy;
	size_t	i;

	i = ft_strlen(s);
	s_cpy = (char *)s;
	while (i > 0)
	{
		if (s_cpy[i] == (unsigned char)c)
			return (&s_cpy[i]);
		i--;
	}
	if (s_cpy[i] == (unsigned char) c)
		return (&s_cpy[i]);
	return (NULL);
}
