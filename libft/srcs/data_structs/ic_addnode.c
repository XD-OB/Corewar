/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ic_addnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 16:51:06 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/09 13:51:45 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ic_addnode(t_icase **icase, int value)
{
	t_icase		*node;
	t_icase		*tmp;

	if (!(node = (t_icase*)malloc(sizeof(t_icase))))
		return ;
	node->n = value;
	node->next = NULL;
	if (!*icase)
	{
		*icase = node;
		return ;
	}
	tmp = *icase;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}
