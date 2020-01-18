/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dt_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 09:34:13 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/18 09:34:16 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	dt_lstdelone(t_dlist **alst, void (*del)(void*, size_t))
{
	if (alst)
	{
		if (*alst && del)
		{
			del((*alst)->content, (*alst)->content_size);
			(*alst)->prev = NULL;
			(*alst)->next = NULL;
			free(*alst);
			*alst = NULL;
		}
	}
}
