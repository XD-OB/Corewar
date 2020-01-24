/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_vm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <aaguert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 15:38:43 by aaguert           #+#    #+#             */
/*   Updated: 2020/01/11 00:41:39 by aaguert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "vm_visu.h"

void	run_vm(void)
{
	init_arena();
	if (VIS)
		init_vis();
	else
		introduce_players();
	mainloop();
}
