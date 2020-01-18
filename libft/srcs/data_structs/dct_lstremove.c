/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dct_lstremove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 09:26:45 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/18 09:38:18 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			dct_lstremove(t_dlist **alst, t_dlist *place,
								void (*del)(void*, size_t))
{
	t_dlist		*tmp;

	if (!alst || !*alst || !del || !place)
		return ;
	if (place == *alst && place == place->next)
	{
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = NULL;
	}
	else
	{
		tmp = *alst;
		while (*alst != place)
			*alst = (*alst)->next;
		(*alst)->prev->next = (*alst)->next;
		(*alst)->next->prev = (*alst)->prev;
		del((*alst)->content, (*alst)->content_size);
		if (*alst == tmp)
			tmp = tmp->next;
		free(*alst);
		*alst = NULL;
		*alst = tmp;
	}
}
