/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dct_lstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 09:37:58 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/18 09:38:00 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			dct_lstdel(t_dlist **alst, void (*del)(void*, size_t))
{
	t_dlist		*curr;

	curr = *alst;
	while (curr && curr->next != *alst)
		curr = curr->next;
	curr->next = NULL;
	(*alst)->prev = NULL;
	dt_lstdel(alst, del);
}
