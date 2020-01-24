/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_dump.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <aaguert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 23:02:07 by aaguert           #+#    #+#             */
/*   Updated: 2020/01/21 05:54:40 by aaguert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	dump_memory(int bytes_per_line)
{
	int i;
	int j;
	int w;
	int h;

	w = bytes_per_line;
	h = MEM_SIZE / w;
	i = -1;
	while (++i < h)
	{
		ft_printf("0x%04x : ", i * w);
		j = -1;
		while (++j < w)
			ft_printf("%02x ", g_arena.memory[(w * i) + j]);
		ft_printf("\n");
	}
	ft_printf("\n");
}
