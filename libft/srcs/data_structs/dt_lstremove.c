/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dt_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 09:20:42 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/18 09:20:58 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		lstremove_p2(t_dlist **alst)
{
	t_dlist		*tmp;

	tmp = *alst;
	if (!(*alst)->next)
	{
		*alst = (*alst)->prev;
		(*alst)->next = NULL;
		tmp->prev = NULL;
		free(tmp);
		tmp = NULL;
	}
	else
	{
		(*alst)->prev->next = (*alst)->next;
		(*alst)->next->prev = (*alst)->prev;
		*alst = (*alst)->prev;
		tmp->prev = NULL;
		tmp->next = NULL;
		free(tmp);
		tmp = NULL;
	}
}

void			dt_lstremove(t_dlist **alst, t_dlist *place,
								void (*del)(void*, size_t))
{
	t_dlist		*curr;

	if (!alst || !*alst || !del)
		return ;
	curr = *alst;
	while (curr && curr != place)
		curr = curr->next;
	if (!curr)
		return ;
	del(curr->content, curr->content_size);
	if (!curr->prev && !curr->next)
	{
		free(curr);
		curr = NULL;
	}
	else if (!curr->prev)
	{
		curr = curr->next;
		curr->prev->next = NULL;
		free(curr->prev);
		curr->prev = NULL;
		*alst = curr;
	}
	else
		lstremove_p2(&curr);
}
