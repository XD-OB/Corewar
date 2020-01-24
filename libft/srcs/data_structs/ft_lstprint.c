/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 16:50:52 by obelouch          #+#    #+#             */
/*   Updated: 2019/06/30 05:06:42 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	type: 		0:number	1:string
**	sep:		0:\n		1:<-
*/

void			ft_lstprint(t_list *head, int type, int sep)
{
	if (!head)
	{
		(sep) ? ft_putstr("Empty Stack!\n") : 0;
		return ;
	}
	while (head)
	{
		if (type)
			ft_putstr((char*)head->content);
		else
			ft_putnbr(*((int*)head->content));
		if (sep)
			(head->next) ? ft_putstr(" | ") : 0;
		else
			ft_putchar('\n');
		head = head->next;
	}
	(sep) ? ft_putstr(" ]") : 0;
	ft_putchar('\n');
}
