/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_insert_item.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 15:16:04 by obelouch          #+#    #+#             */
/*   Updated: 2019/04/27 15:16:06 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	bt_insert_item(t_bt **root, void *item, int (*cmpf)(void *, void *))
{
	t_bt	*node;

	node = *root;
	if (!node)
		node = bt_create_node(item);
	else if (cmpf(item, node->item) < 0)
		bt_insert_item(&node->left, item, cmpf);
	else
		bt_insert_item(&node->right, item, cmpf);
	*root = node;
}
