/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_level_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 15:15:39 by obelouch          #+#    #+#             */
/*   Updated: 2019/04/27 15:15:40 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		bt_level_count(t_bt *root)
{
	int		ldepth;
	int		rdepth;

	if (!root)
		return (0);
	else
	{
		ldepth = bt_level_count(root->left);
		rdepth = bt_level_count(root->right);
		if (ldepth > rdepth)
			return (1 + ldepth);
		else
			return (1 + rdepth);
	}
}
