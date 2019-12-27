/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qt_enqueue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 16:52:18 by obelouch          #+#    #+#             */
/*   Updated: 2019/06/14 16:52:20 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			qt_enqueue(t_queue *queue, void *content, size_t size)
{
	t_list	*node;

	if (!(node = ft_lstnew(content, size)))
		return (1);
	if (qt_isempty(*queue))
	{
		queue->front = node;
		queue->rear = queue->front;
	}
	else
	{
		queue->rear->next = node;
		queue->rear = node;
	}
	return (0);
}
