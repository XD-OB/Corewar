/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vfree.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <aaguert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 22:06:35 by aaguert           #+#    #+#             */
/*   Updated: 2020/01/22 22:25:56 by aaguert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_visu.h"

void	vfree_comments(void)
{
	int i;

	i = -1;
	while (++i < MAX_COMMENTS && g_vis.game.comments[i].plid)
		free(g_vis.game.comments[i].comment);
}
