/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_apply_prefix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 15:14:34 by obelouch          #+#    #+#             */
/*   Updated: 2019/04/27 15:14:35 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	bt_apply_prefix(t_bt *root, void (*applyf)(void *))
{
	if (root)
	{
		applyf(root->item);
		bt_apply_prefix(root->left, applyf);
		bt_apply_prefix(root->right, applyf);
	}
}
