/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <lofiorin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:44:02 by lofiorin          #+#    #+#             */
/*   Updated: 2024/01/26 14:27:11 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	return (i);
}

static int	ft_size(const char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			words++;
		i++;
	}
	return (words);
}

static char	**ft_my_free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		j;
	char	*s_cpy;
	char	**dest;

	j = 0;
	s_cpy = (char *)s;
	if (s == NULL)
		return (NULL);
	dest = malloc((ft_size(s, c) + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	while (j < ft_size(s, c) && s_cpy)
	{
		while (*s_cpy == c)
			s_cpy++;
		dest[j] = malloc((ft_len(s_cpy, c) + 1) * sizeof(char));
		if (!dest[j])
			return (ft_my_free_split(dest));
		ft_strlcpy(dest[j], s_cpy, ft_len(s_cpy, c) + 1);
		s_cpy += ft_len(s_cpy, c) + 1;
		j++;
	}
	dest[j] = NULL;
	return (dest);
}
