/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qt_dequeue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 16:52:26 by obelouch          #+#    #+#             */
/*   Updated: 2019/06/30 03:03:01 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			qt_dequeue(t_queue *queue)
{
	t_list	*tmp;

	if (qt_isempty(*queue))
		return (1);
	tmp = queue->front;
	if (queue->front == queue->rear)
	{
		queue->front = NULL;
		queue->rear = NULL;
	}
	else
		queue->front = queue->front->next;
	free(tmp->content);
	free(tmp);
	return (0);
}
