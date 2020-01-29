/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 05:29:00 by aaguert           #+#    #+#             */
/*   Updated: 2020/01/29 02:07:00 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	normal_dump(int bpl)
{
	if (g_arena.cycles_nb == g_flags[FLAG_DUMP_I].data.num)
		dump_memory(bpl);
	if (g_arena.cycles_nb == g_flags[FLAG_SM_D_I].data.num)
		dump_memory(bpl);
	exit(EXIT_SUCCESS);
}

void	manage_dump(void)
{
	if (g_flags[FLAG_DUMP_I].present)
	{
		if (g_arena.cycles_nb == g_flags[FLAG_DUMP_I].data.num)
			normal_dump(32);
	}
	else if (g_flags[FLAG_SM_D_I].present)
	{
		if (g_arena.cycles_nb == g_flags[FLAG_SM_D_I].data.num)
			normal_dump(64);
	}
	else if (g_flags[FLAG_D_I].present)
		dump_memory(64);
	else if (g_flags[FLAG_S_I].present)
	{
		if (g_arena.cycles_nb &&
		g_arena.cycles_nb % g_flags[FLAG_S_I].data.num == 0)
		{
			dump_memory(64);
			getchar();
		}
	}
}
