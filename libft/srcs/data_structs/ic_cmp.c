/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ic_cmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 09:19:02 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/18 09:19:13 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ic_cmp(t_icase *list1, t_icase *list2)
{
	t_icase		*ptr1;
	t_icase		*ptr2;

	ptr1 = list1;
	ptr2 = list2;
	while (ptr1 && ptr2)
	{
		if (ptr1->n != ptr2->n)
			return (ptr1->n - ptr2->n);
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	if (!ptr1 && !ptr2)
		return (0);
	if (ptr1)
		return (ptr1->n);
	return (0 - ptr2->n);
}
