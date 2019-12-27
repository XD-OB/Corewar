/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sk_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 16:51:33 by obelouch          #+#    #+#             */
/*   Updated: 2019/06/14 16:51:34 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	sk_free(t_list **head)
{
	t_list	*tmp;

	while (*head)
	{
		tmp = *head;
		if ((*head)->content)
			free((*head)->content);
		*head = (*head)->next;
		free(tmp);
	}
}
