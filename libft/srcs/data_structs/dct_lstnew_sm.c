/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dct_lstnew_sm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 09:32:37 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/18 09:32:39 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist			*dct_lstnew_sm(void *content, size_t content_size)
{
	t_dlist		*node;

	node = (t_dlist*)malloc(sizeof(t_dlist));
	if (node == NULL)
		return (NULL);
	node->prev = node;
	node->next = node;
	if (content == NULL)
	{
		node->content = NULL;
		node->content_size = 0;
	}
	else
	{
		node->content = content;
		node->content_size = content_size;
	}
	return (node);
}
