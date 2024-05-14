/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_av_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <lofiorin@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:48:21 by lofiorin          #+#    #+#             */
/*   Updated: 2024/04/24 11:49:52 by lofiorin         ###   ########.fr       */
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

static char	**free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i] && split)
		free(split[i]);
	free(split);
	return (NULL);
}

static char	*first_assign(char *s)
{
	s = ft_calloc(1, sizeof(char));
	if (!s)
		return (NULL);
	return (s);
}

char	**ft_av_split(char const *s, char c)
{
	int		j;
	char	*s_cpy;
	char	**dest;

	j = 1;
	s_cpy = (char *)s;
	if (s == NULL)
		return (NULL);
	dest = malloc((ft_size(s, c) + 2) * sizeof(char *));
	dest[0] = first_assign(dest[0]);
	if (!dest || !dest[0])
		return (free_split(dest));
	while (j - 1 < ft_size(s, c) && s_cpy)
	{
		while (*s_cpy == c)
			s_cpy++;
		dest[j] = malloc((ft_len(s_cpy, c) + 1) * sizeof(char));
		if (!dest[j])
			return (free_split(dest));
		ft_strlcpy(dest[j], s_cpy, ft_len(s_cpy, c) + 1);
		s_cpy += ft_len(s_cpy, c) + 1;
		j++;
	}
	dest[j] = NULL;
	return (dest);
}
