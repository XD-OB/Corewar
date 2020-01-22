/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sider.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 22:29:16 by ishaimou          #+#    #+#             */
/*   Updated: 2020/01/21 22:29:19 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_visu.h"
#include "vm.h"

void	init_players(void)
{
	int i;

	i = 0;
	while (g_players[i].present)
	{
		g_vis.siders.player[i] = newwin(
			PB_HEIGHT, PB_WIDTH,
			PB_RESF_ROW + i * PB_HEIGHT + PB_L_HIGHT,
			PB_RESF_COL);
		wattron(g_vis.siders.player[i], COLOR_PAIR(i + 1));
		box(g_vis.siders.player[i], 0, 0);
		wattroff(g_vis.siders.player[i], COLOR_PAIR(i + 1));
		i++;
	}
}

void	init_siders(void)
{
	g_vis.siders.gstate = newwin(
		GSTATE_HEIGHT, GSTATE_WIDTH, GSTATE_ROW, GSTATE_COL);
	init_players();
	init_chat_box();
}
