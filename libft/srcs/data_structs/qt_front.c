/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qt_front.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 16:52:33 by obelouch          #+#    #+#             */
/*   Updated: 2019/06/14 16:52:35 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			qt_front(t_queue queue, void *content)
{
	if (qt_isempty(queue))
		return (1);
	ft_memcpy(content, queue.front->content,
			queue.front->content_size);
	return (0);
}
