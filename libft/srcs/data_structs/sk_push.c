/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sk_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 16:51:53 by obelouch          #+#    #+#             */
/*   Updated: 2019/06/14 16:51:54 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	sk_push(t_list **top, void *content, size_t size)
{
	t_list	*node;

	node = ft_lstnew(content, size);
	node->next = *top;
	*top = node;
}
