/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 02:46:33 by ishaimou          #+#    #+#             */
/*   Updated: 2020/01/28 07:22:37 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "vm_visu.h"

static void			modify_carry(t_process *p, char r_num)
{
	if (is_valid_reg(r_num))
		p->carry = p->reg[r_num - 1] ? 0 : 1;
}

void				write_into_reg(t_process *p, int r_num, int val
		, t_bool cflag)
{
	if (is_valid_reg(r_num))
	{
		p->reg[r_num - 1] = val;
		if (cflag)
			modify_carry(p, r_num);
	}
}

static	void		get_dir_arg(t_process *p, int args[2], int *offset, int i)
{
	int				t_dir_type;

	t_dir_type = g_op_tab[p->op_buff.op - 1].t_dir_size_type;
	args[i] = t_dir_type == SHORT_TDIR ?
		read_dir_val(p->pc + *offset, t_dir_type).s
		: read_dir_val(p->pc + *offset, t_dir_type).n;
	*offset += t_dir_type == SHORT_TDIR ? IND_SIZE : DIR_SIZE;
}

void				get_op_args(t_process *p, int args[2], int *offset,
		t_bool reg_type)
{
	int				i;
	int				r_src;
	t_ind			addr;
	int				t_dir_type;

	i = -1;
	t_dir_type = g_op_tab[p->op_buff.op - 1].t_dir_size_type;
	while (++i < 2)
	{
		if (g_type[i + reg_type] == T_REG)
		{
			r_src = g_arena.memory[M(p->pc + *offset)];
			args[i] = p->reg[r_src - 1];
			(*offset)++;
		}
		if (g_type[i + reg_type] == T_DIR)
			get_dir_arg(p, args, offset, i);
		if (g_type[i + reg_type] == T_IND)
		{
			addr = read_ind_val(p, offset, NORM_OP);
			args[i] = read_dir_val(addr, t_dir_type).n;
		}
	}
}

void				write_mem(t_process *p, int *reg, int addr, size_t size)
{
	int				i;
	unsigned char	*r_ptr;

	r_ptr = (unsigned char*)reg;
	i = size;
	while (--i >= 0)
	{
		g_arena.memory[M(addr + i)] = r_ptr[size - i - 1];
		if (VIS)
			render_byte(g_vis.arena, M(addr + i),
				COLOR_PAIR(p->player_id) | A_BOLD);
	}
}
