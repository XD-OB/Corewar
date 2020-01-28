/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 23:45:16 by aaguert           #+#    #+#             */
/*   Updated: 2020/01/28 06:40:49 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "vm_visu.h"

void	mainloop(void)
{
	while (g_arena.game_run)
	{
		if (g_arena.check.remain < 1)
			perform_check();
		if (VIS)
		{
			print_frame();
			g_flow();
		}
		else if (DUMP)
			manage_dump();
		exec_cycle();
	}
	endgame();
}
