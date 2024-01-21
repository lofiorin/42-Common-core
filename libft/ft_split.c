/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:44:02 by lofiorin          #+#    #+#             */
/*   Updated: 2023/10/20 14:44:04 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*split_free(char **split, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(split[i]);
		i++;
	}
	free (split);
	return (NULL);
}

static int	is_c(char check, char c)
{
	if (check == c || check == '\0')
		return (1);
	return (0);
}

static int	count_words(const char *str, char c)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (!is_c(*str, c) && is_c(*(str + 1), c))
			i++;
		str++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		start;
	char	**split;

	split = ft_calloc((count_words(s, c) + 1), sizeof(char *));
	if (!s || !split)
		return (NULL);
	i = 0;
	j = 0;
	start = 0;
	while (i <= ft_strlen(s))
	{
		if ((is_c(s[i], c) && !is_c(s[i + 1], c)))
			start = i + 1;
		else if (!is_c(s[i], c) && is_c(s[i + 1], c))
		{
			split[j++] = ft_substr(s, start, i + 1 - start);
			if (!split[j - 1])
				return (split_free(split, count_words(s, c)));
		}
		i++;
	}
	split[j] = NULL;
	return (split);
}
