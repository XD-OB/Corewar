/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qt_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 16:53:02 by obelouch          #+#    #+#             */
/*   Updated: 2019/06/30 03:03:00 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			qt_free(t_queue *queue)
{
	while (!qt_isempty(*queue))
		qt_dequeue(queue);
	free(queue);
	queue = NULL;
}
