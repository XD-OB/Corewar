/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dt_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 09:27:41 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/18 09:27:47 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		dt_lstiter(t_dlist *lst, void (*f)(t_dlist *elem))
{
	if (f)
	{
		while (lst != NULL)
		{
			f(lst);
			lst = lst->next;
		}
	}
}