/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ct_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 09:37:20 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/18 09:37:21 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ct_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list		*curr;

	curr = *alst;
	while (curr && curr->next != *alst)
		curr = curr->next;
	curr->next = NULL;
	ft_lstdel(alst, del);
}
