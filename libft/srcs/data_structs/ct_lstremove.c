/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ct_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 09:33:37 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/18 09:33:51 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ct_lstremove(t_list **alst, t_list *place,
							void (*del)(void*, size_t))
{
	t_list	*next;
	t_list	*prev;

	if (!alst || !*alst || !del)
		return ;
	prev = *alst;
	if (place != *alst)
	{
		while (prev && prev->next != place)
			prev = prev->next;
		if (!prev)
			return ;
	}
	next = place->next;
	del(place->content, place->content_size);
	free(place);
	prev->next = next;
}
