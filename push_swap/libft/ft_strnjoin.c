/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <lofiorin@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:57:54 by lofiorin          #+#    #+#             */
/*   Updated: 2024/04/23 21:02:27 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char *s1, char *s2, size_t size)
{
	char	*res;
	size_t	len;
	size_t	i;
	size_t	j;

	len = ft_strlen((const char *)s1);
	res = malloc((len + size + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (i < len && s1 && s1[i])
		res[i++] = s1[j++];
	j = 0;
	while (j < size && s2 && s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	free(s1);
	return (res);
}
