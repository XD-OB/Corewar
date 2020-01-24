/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_search_item.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 15:15:32 by obelouch          #+#    #+#             */
/*   Updated: 2019/04/27 15:15:33 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bt	*bt_search_item(t_bt *root, void *dataref, int (*cmpf)(void *, void *))
{
	if (!root || !cmpf(dataref, root->item))
		return (root);
	if (cmpf(dataref, root->item) < 0)
		return (bt_search_item(root->left, dataref, cmpf));
	return (bt_search_item(root->right, dataref, cmpf));
}
