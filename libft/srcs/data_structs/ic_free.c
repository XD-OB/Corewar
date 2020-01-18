/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ic_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 09:28:31 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/18 09:28:38 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ic_free(t_icase **icase)
{
	t_icase	*tmp;
	t_icase *curr;

	tmp = *icase;
	while (tmp)
	{
		curr = tmp;
		tmp = tmp->next;
		free(curr);
	}
	icase = NULL;
}
