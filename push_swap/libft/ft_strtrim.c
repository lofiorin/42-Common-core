/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <lofiorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:16:52 by lofiorin          #+#    #+#             */
/*   Updated: 2024/01/18 16:48:13 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, char *set)
{
	size_t	start;
	size_t	end;
	char	*res;

	start = 0;
	end = ft_strlen(s1);
	while (ft_strchr(set, (int)s1[start]) && start <= end)
		start++;
	while (ft_strchr(set, (int)s1[end]) && start <= end)
		end--;
	res = ft_calloc(end - start + 2, sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, &s1[start], end - start + 2);
	return (res);
}
