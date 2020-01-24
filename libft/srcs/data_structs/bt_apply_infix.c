/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_apply_infix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 15:13:35 by obelouch          #+#    #+#             */
/*   Updated: 2019/04/27 15:14:22 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	bt_apply_infix(t_bt *root, void (*applyf)(void *))
{
	if (root)
	{
		bt_apply_infix(root->left, applyf);
		applyf(root->item);
		bt_apply_infix(root->right, applyf);
	}
}
