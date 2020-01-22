/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_gstate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <aaguert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 00:40:09 by aaguert           #+#    #+#             */
/*   Updated: 2020/01/21 22:28:24 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "vm_visu.h"

void	render_gstate(void)
{
	int bl;

	bl = BASE_LINE + 35;
	render_top_infos();
	render_important_info();
	render_indicated_data();
	wattron(g_vis.siders.gstate, A_BOLD);
	mvwprintw(g_vis.siders.gstate, bl, WORDS_COL,
	"total processes number : %-10d", g_arena.pnum);
	mvwprintw(g_vis.siders.gstate, bl + 2, WORDS_COL,
	"total lives declared : %-10d", g_arena.lives_performed);
	mvwprintw(g_vis.siders.gstate, bl + 4, WORDS_COL,
	"total checks performed : %-10d", g_arena.check.total_checks);
	wattron(g_vis.siders.gstate, A_BOLD);
}
