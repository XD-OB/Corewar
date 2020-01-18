/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 09:21:40 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/18 09:31:40 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd_last(t_list **lst, t_list *node)
{
	t_list	*current;

	if (!node)
		return ;
	if (*lst)
	{
		current = *lst;
		while (current->next)
			current = current->next;
		current->next = node;
	}
	else
		*lst = node;
}
