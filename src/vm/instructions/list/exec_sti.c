/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_sti.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <aaguert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 00:28:12 by ishaimou          #+#    #+#             */
/*   Updated: 2020/01/15 23:53:29 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	exec_sti(t_process *p)
{
	int		t_dir_type;
	int		offset;
	int		args[2];
	char	r_src;
	t_ind	addr;

	t_dir_type = g_op_tab[STI_I].t_dir_size_type;
	if (check_operation(p, t_dir_type, &offset))
		return ;
	r_src = g_arena.memory[M(p->pc + offset)];
	offset++;
	get_op_args(p, args, &offset, R_SRC);
	addr = M((args[0] + args[1]) % IDX_MOD);
	write_mem(p, &(p->reg[r_src - 1]), p->pc + addr, REG_SIZE);
	p->pc += offset;
}
