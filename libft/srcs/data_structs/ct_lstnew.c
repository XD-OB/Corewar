/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ct_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 09:32:50 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/18 09:32:51 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ct_lstnew(const void *content, size_t content_size)
{
	t_list		*node;
	void		*cont;

	node = (t_list*)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->next = node;
	if (content == NULL)
	{
		node->content = NULL;
		node->content_size = 0;
	}
	else
	{
		cont = (void*)malloc(content_size);
		node->content = ft_memcpy(cont, content, content_size);
		node->content_size = content_size;
	}
	return (node);
}
