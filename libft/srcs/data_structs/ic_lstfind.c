/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ic_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 09:24:21 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/18 09:24:27 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ic_lstfind(t_list *list, t_icase *target)
{
	t_list		*tmp;
	t_icase		*item;

	(void)target;
	tmp = list;
	while (tmp)
	{
		item = (t_icase*)tmp->content;
		if (!ic_cmp(item, target))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
