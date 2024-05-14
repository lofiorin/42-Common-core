/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <lofiorin@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 21:13:25 by lofiorin          #+#    #+#             */
/*   Updated: 2024/04/23 21:19:48 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_mat_dup(char **mat)
{
	char	**mat_cpy;
	int		i;

	i = 0;
	mat_cpy = ft_calloc(ft_mat_len(mat) + 1, sizeof(char *));
	if (!mat_cpy)
		return (NULL);
	while (mat[i])
	{
		mat_cpy[i] = ft_strdup(mat[i]);
		if (!mat_cpy[i])
			return (ft_free_mat(mat_cpy), NULL);
		i++;
	}
	return (mat_cpy);
}
