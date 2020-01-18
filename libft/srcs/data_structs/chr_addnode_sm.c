/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chr_addnode_sm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 09:31:56 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/18 09:32:08 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		chr_addnode_sm(t_chr **list, char *str, int len)
{
	t_chr	*curr;
	t_chr	*node;

	if (!(node = (t_chr*)malloc(sizeof(t_chr))))
		return ;
	node->str = str;
	node->len = len;
	node->next = NULL;
	if (!*list)
	{
		*list = node;
		return ;
	}
	curr = *list;
	while (curr->next)
		curr = curr->next;
	curr->next = node;
}
