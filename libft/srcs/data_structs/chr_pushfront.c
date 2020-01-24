/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chr_pushfront.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 09:22:55 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/18 09:32:23 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		chr_pushfront(t_chr **list, char *str, int len)
{
	t_chr	*node;

	if (!(node = (t_chr*)malloc(sizeof(t_chr))))
		return ;
	node->str = ft_strdup(str);
	node->len = len;
	node->next = NULL;
	if (!*list)
	{
		*list = node;
		return ;
	}
	node->next = *list;
	*list = node;
}
