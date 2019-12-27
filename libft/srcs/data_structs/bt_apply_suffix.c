/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_apply_suffix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 15:13:56 by obelouch          #+#    #+#             */
/*   Updated: 2019/04/27 15:14:51 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	bt_apply_suffix(t_bt *root, void (*applyf)(void *))
{
	if (root)
	{
		bt_apply_prefix(root->left, applyf);
		bt_apply_prefix(root->right, applyf);
		applyf(root->item);
	}
}
