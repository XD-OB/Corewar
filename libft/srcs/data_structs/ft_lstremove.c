/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 09:24:44 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/18 09:24:57 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_lstremove_p2(t_list **alst, t_list *prev, t_list *next)
{
	t_list		*tmp;

	if (!prev && !next)
	{
		free(*alst);
		*alst = NULL;
	}
	else if (!prev)
	{
		tmp = *alst;
		*alst = (*alst)->next;
		free(tmp);
	}
	else if (!next)
	{
		free(prev->next);
		prev->next = NULL;
	}
}

void			ft_lstremove(t_list **alst, t_list *place,
								void (*del)(void*, size_t))
{
	t_list		*next;
	t_list		*prev;

	if (!alst || !*alst || !del)
		return ;
	prev = NULL;
	if (place != *alst)
	{
		prev = *alst;
		while (prev && prev->next != place)
			prev = prev->next;
		if (!prev)
			return ;
	}
	next = place->next;
	del(place->content, place->content_size);
	if (prev && next)
	{
		free(place);
		prev->next = next;
	}
	else
		ft_lstremove_p2(alst, prev, next);
}
