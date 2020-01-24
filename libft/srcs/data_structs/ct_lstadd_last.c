/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ct_lstadd_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 09:23:49 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/18 09:38:51 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ct_lstadd_last(t_list **alst, t_list *new)
{
	t_list	*current;

	if (!new)
		return ;
	if (*alst)
	{
		current = *alst;
		while (current->next != *alst)
			current = current->next;
		current->next = new;
		new->next = *alst;
	}
	else
		*alst = new;
}
