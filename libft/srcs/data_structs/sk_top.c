/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sk_top.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 16:52:00 by obelouch          #+#    #+#             */
/*   Updated: 2019/06/14 16:52:02 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*sk_top(t_list *top)
{
	void	*item;

	if (!top)
		return (NULL);
	item = (void*)ft_memalloc(top->content_size);
	ft_memcpy(item, top->content, top->content_size);
	return (item);
}
