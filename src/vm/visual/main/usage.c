/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <aaguert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 06:59:20 by aaguert           #+#    #+#             */
/*   Updated: 2020/01/20 07:38:47 by aaguert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_visu.h"

void	init_usage(void)
{
	g_vis.usage = newwin(USAGE_HEIGHT, USAGE_WIDTH, USAGE_ROW, USAGE_COL);
	wattron(g_vis.usage, A_BOLD);
	mvwprintw(g_vis.usage, 1, 2, "q : quit");
	mvwprintw(g_vis.usage, 4, 2, "space : pause/run");
	mvwprintw(g_vis.usage, 1, 30, "right arrow : speed up");
	mvwprintw(g_vis.usage, 4, 30, "left arrow : speed down");
	mvwprintw(g_vis.usage, 1, 70, "n : next cycle (on pause mode)");
	wattroff(g_vis.usage, A_BOLD);
}
