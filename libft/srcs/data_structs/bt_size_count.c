/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_size_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 15:15:27 by obelouch          #+#    #+#             */
/*   Updated: 2019/04/27 15:15:28 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		bt_size_count(t_bt *root)
{
	if (!root)
		return (0);
	else
		return (1 + bt_size_count(root->left) + bt_size_count(root->right));
}
