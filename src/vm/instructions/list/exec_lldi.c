/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_lldi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 00:27:38 by ishaimou          #+#    #+#             */
/*   Updated: 2020/01/27 23:54:43 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	exec_lldi(t_process *p)
{
	int		t_dir_type;
	int		offset;
	int		args[2];
	t_dir	dir_val;
	char	r_dst;

	t_dir_type = g_op_tab[LLDI_I].t_dir_size_type;
	if (check_operation(p, t_dir_type, &offset))
		return ;
	get_op_args(p, args, &offset, R_DST);
	dir_val = read_dir_val(p->pc + M(args[0] + args[1]), NORMAL_TDIR);
	r_dst = g_arena.memory[M(p->pc + offset)];
	offset++;
	write_into_reg(p, r_dst, dir_val.n, SET_CARRY);
	p->pc += offset;
}
