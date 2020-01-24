/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dt_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 09:19:26 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/18 09:19:37 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist			*dt_lstmap(t_dlist *lst, t_dlist *(*f)(t_dlist *elem))
{
	t_dlist		*new_lst;
	t_dlist		*ind[2];

	if (!lst || !f)
		return (NULL);
	new_lst = (t_dlist*)malloc(sizeof(t_dlist));
	ind[0] = new_lst;
	if (!new_lst)
		return (NULL);
	while (lst->next)
	{
		new_lst->next = (t_dlist*)malloc(sizeof(t_dlist));
		ind[1] = (*f)(lst);
		new_lst->content = malloc(ind[1]->content_size);
		ft_memcpy(new_lst->content, ind[1]->content, ind[1]->content_size);
		new_lst->content_size = ind[1]->content_size;
		new_lst = new_lst->next;
		lst = lst->next;
	}
	new_lst->next = NULL;
	ind[1] = (*f)(lst);
	new_lst->content = malloc(ind[1]->content_size);
	ft_memcpy(new_lst->content, ind[1]->content, ind[1]->content_size);
	new_lst->content_size = ind[1]->content_size;
	return (ind[0]);
}
