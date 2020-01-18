/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dt_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 09:35:25 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/18 09:35:30 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		dt_lstdel(t_dlist **alst, void (*del)(void*, size_t))
{
	t_dlist	*current_node;

	if (alst)
	{
		while (*alst != NULL)
		{
			current_node = *alst;
			if (del)
				del((*alst)->content, (*alst)->content_size);
			(*alst)->prev = NULL;
			*alst = (*alst)->next;
			free(current_node);
			current_node = NULL;
		}
	}
}
