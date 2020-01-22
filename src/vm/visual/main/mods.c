/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mods.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 02:53:18 by aaguert           #+#    #+#             */
/*   Updated: 2020/01/21 22:11:52 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_visu.h"

int		get_speed(void)
{
	int			i;
	int			pow;
	unsigned	val;

	val = 1;
	pow = (MAX_SPEED - g_vis.game.speed);
	if (pow < 0)
		return (0);
	i = -1;
	while (++i < pow)
		val *= SPEED_SCALE;
	return (val);
}

void	catch_speed_keys(int c)
{
	if (c == SPEED_DOWN_KEY && g_vis.game.speed > MIN_SPEED)
		g_vis.game.speed--;
	else if (c == SPEED_UP_KEY && g_vis.game.speed <= MAX_SPEED)
		g_vis.game.speed++;
}

int		handle_keys(int c)
{
	if (c == PAUSE_KEY)
	{
		g_vis.game.paused = FALSE;
		return (1);
	}
	else if (c == NEXT_KEY || c == NEXT_KEY2)
		return (1);
	else if (c == SPEED_DOWN_KEY || c == SPEED_UP_KEY)
		catch_speed_keys(c);
	else if (c == QUIT_KEY)
	{
		free_all();
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	handle_time_flow(void)
{
	int c;

	if (g_vis.game.paused)
	{
		while (TRUE)
		{
			if ((c = getch()) > 0)
			{
				if (handle_keys(c))
					break ;
				render_gstate();
				wrefresh(g_vis.siders.gstate);
			}
		}
	}
	else
		usleep(get_speed());
}
