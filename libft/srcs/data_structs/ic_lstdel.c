/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ic_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 09:18:46 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/18 09:18:53 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ic_lstdel(t_list **alst)
{
	t_list	*current_node;

	while (*alst != NULL)
	{
		current_node = *alst;
		ic_free((t_icase**)(&(*alst)->content));
		*alst = (*alst)->next;
		free(current_node);
	}
}
