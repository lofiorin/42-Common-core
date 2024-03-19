/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 11:27:06 by lofiorin          #+#    #+#             */
/*   Updated: 2023/10/15 11:27:12 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = ft_calloc(len, sizeof (char));
	if (!res)
		return (NULL);
	ft_strlcat(res, s1, len);
	ft_strlcat(res, s2, len);
	return (res);
}
