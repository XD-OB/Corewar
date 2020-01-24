/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dt_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 09:30:58 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/18 09:35:52 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			dt_lstinsert(t_dlist **alst, t_dlist *place, t_dlist *node)
{
	t_dlist		*curr;

	if (!*alst)
		*alst = node;
	else
	{
		curr = *alst;
		while (curr && curr != place)
			curr = curr->next;
		if (!curr)
			return ;
		node->prev = curr;
		node->next = curr->next;
		if (curr->next)
			curr->next->prev = node;
		curr->next = node;
	}
}
