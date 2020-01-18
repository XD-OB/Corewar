/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dt_lstadd_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 09:28:10 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/18 09:37:43 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			dt_lstadd_last(t_dlist **alst, t_dlist *new)
{
	t_dlist		*current;

	if (!new)
		return ;
	if (*alst)
	{
		current = *alst;
		while (current->next)
			current = current->next;
		current->next = new;
		new->prev = current;
	}
	else
		*alst = new;
}
