/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chatbox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <aaguert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:40:25 by aaguert           #+#    #+#             */
/*   Updated: 2020/01/24 04:14:27 by aaguert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_visu.h"
#include "vm.h"

void	init_chat_box(void)
{
	int i;

	g_vis.siders.chatbox = newwin(BOX_HEIGHT, BOX_WIDTH, BOX_ROW, BOX_COL);
	i = 0;
	while (i < MAX_PLAYERS && g_players[i].present)
	{
		g_vis.game.comments[i].comment = ft_strdup(g_players[i].header.comment);
		g_vis.game.comments[i].plid = i + 1;
		i++;
	}
}

void	render_comments(void)
{
	int		i;
	char	*plname;

	i = -1;
	wattron(g_vis.siders.chatbox, A_BOLD);
	while (++i < MAX_COMMENTS && g_vis.game.comments[i].plid)
	{
		plname = g_players[g_vis.game.comments[i].plid - 1].header.prog_name;
		wmove(g_vis.siders.chatbox, FIRST_COM_ROW - 3 * i, COMS_COL);
		wattron(g_vis.siders.chatbox, COLOR_PAIR(g_vis.game.comments[i].plid));
		wprintw(g_vis.siders.chatbox, "%s", plname);
		wattroff(g_vis.siders.chatbox, COLOR_PAIR(g_vis.game.comments[i].plid));
		wprintw(g_vis.siders.chatbox, " : %-*s",
		BOX_WIDTH * 3 - ft_strlen(plname) - 3, g_vis.game.comments[i].comment);
	}
	wattroff(g_vis.siders.chatbox, A_BOLD);
}

void	add_comment(int plid, char *cmt)
{
	int i;

	i = MAX_COMMENTS - 1;
	while (i > 0)
	{
		g_vis.game.comments[i] = g_vis.game.comments[i - 1];
		i--;
	}
	g_vis.game.comments[0].plid = plid;
	g_vis.game.comments[0].comment = cmt;
}
