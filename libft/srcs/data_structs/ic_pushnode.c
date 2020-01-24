/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ic_pushnode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 16:51:13 by obelouch          #+#    #+#             */
/*   Updated: 2019/07/09 13:51:01 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ic_pushnode(t_icase **icase, int value)
{
	t_icase		*node;

	if (!(node = (t_icase*)malloc(sizeof(t_icase))))
		return ;
	node->n = value;
	node->next = NULL;
	if (!*icase)
		*icase = node;
	else
	{
		node->next = (*icase);
		(*icase) = node;
	}
}
