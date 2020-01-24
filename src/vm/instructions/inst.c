/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <aaguert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 20:17:18 by aaguert           #+#    #+#             */
/*   Updated: 2020/01/15 03:58:26 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "vm_visu.h"

void	pexec_inst(t_process *p)
{
	t_op	op;

	op = g_op_tab[p->op_buff.op - 1];
	op.exec_func(p);
	p->op_buff.op = 0;
}
