/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 15:15:18 by obelouch          #+#    #+#             */
/*   Updated: 2019/04/27 15:15:20 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	bt_free(t_bt **root, void (*freef)(void **))
{
	t_bt *tmp;

	tmp = *root;
	if (!*root)
		return ;
	if (tmp->left)
		bt_free(&tmp->left, freef);
	if (tmp->right)
		bt_free(&tmp->right, freef);
	freef(&tmp->item);
	free(tmp);
	*root = NULL;
}
