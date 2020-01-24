/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   introduce_players.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <aaguert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 19:45:10 by aaguert           #+#    #+#             */
/*   Updated: 2020/01/21 19:46:21 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	introduce_player(t_player player, int ind)
{
	ft_putstr("* Player ");
	ft_putnbr(ind + 1);
	ft_putstr(", weighing ");
	ft_putnbr(player.header.prog_size);
	ft_putstr(" bytes, \"");
	ft_putstr(player.header.prog_name);
	ft_putstr("\" (\"");
	ft_putstr(player.header.comment);
	ft_putendl("\") !");
}

void	introduce_players(void)
{
	int i;

	ft_putstr("Introducing contestants...\n");
	i = 0;
	while (i < MAX_PLAYERS)
	{
		if (g_players[i].present)
			introduce_player(g_players[i], i);
		i++;
	}
}
