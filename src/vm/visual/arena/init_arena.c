/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <aaguert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 00:07:57 by aaguert           #+#    #+#             */
/*   Updated: 2020/01/22 21:01:58 by aaguert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm_visu.h"

void	vinit_arena(void)
{
	g_vis.arena = newwin(ARENA_HEIGHT, ARENA_WIDTH, ARENA_ROW, ARENA_COL);
	load_arena();
	paint_players();
}
