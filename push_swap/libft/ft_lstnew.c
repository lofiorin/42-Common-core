/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:39:30 by lofiorin          #+#    #+#             */
/*   Updated: 2023/10/22 20:39:33 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*content_len;

	content_len = (t_list *)malloc(sizeof(t_list) * 1);
	if (!content_len)
		return (NULL);
	content_len -> content = content;
	content_len -> next = NULL;
	return (content_len);
}
