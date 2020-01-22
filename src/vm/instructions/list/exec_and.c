/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_and.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <aaguert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 21:30:02 by ishaimou          #+#    #+#             */
/*   Updated: 2020/01/21 20:30:08 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	exec_and(t_process *p)
{
	int		args[2];
	int		offset;
	int		t_dir_type;
	char	r_dst;

	t_dir_type = g_op_tab[AND_I].t_dir_size_type;
	if (check_operation(p, t_dir_type, &offset))
		return ;
	get_op_args(p, args, &offset, R_DST);
	r_dst = g_arena.memory[M(p->pc + offset)];
	offset++;
	write_into_reg(p, r_dst, args[0] & args[1], 1);
	p->pc += offset;
}
