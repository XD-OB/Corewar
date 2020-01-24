/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 09:20:13 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/18 09:29:13 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstinsert(t_list **alst, t_list *place, t_list *node)
{
	t_list	*curr;

	if (!*alst)
		*alst = node;
	else
	{
		curr = *alst;
		while (curr && curr != place)
			curr = curr->next;
		if (!curr)
			return ;
		node->next = curr->next;
		curr->next = node;
	}
}
