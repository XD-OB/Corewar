/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 03:22:13 by ishaimou          #+#    #+#             */
/*   Updated: 2020/01/24 01:07:55 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	set_invalid_offset(t_process *p, int t_dir_type, int *offset)
{
	int		i;

	i = -1;
	while (++i < g_op_tab[p->op_buff.op - 1].argnum)
	{
		if (g_type[i] == T_REG)
			*offset += 1;
		else if (g_type[i] == T_DIR)
			*offset += t_dir_type == SHORT_TDIR ? IND_SIZE : DIR_SIZE;
		else if (g_type[i] == T_IND)
			*offset += IND_SIZE;
	}
}

static void	get_type_code(t_process *p)
{
	char	type_code;
	int		i;

	type_code = g_arena.memory[M(p->pc + 1)];
	g_type[0] = (type_code >> 6) & 0x3;
	g_type[1] = (type_code >> 4) & 0x3;
	g_type[2] = (type_code >> 2) & 0x3;
	i = -1;
	while (++i < MAX_OP_ARGS)
	{
		if (g_type[i] == IND_CODE)
			g_type[i] = T_IND;
	}
}

t_bool		check_type_code(t_process *p, int t_dir_type, int *offset)
{
	int		i;
	char	*arg_type;

	i = -1;
	*offset = 2;
	get_type_code(p);
	arg_type = g_op_tab[p->op_buff.op - 1].arg_type;
	while (++i < g_op_tab[p->op_buff.op - 1].argnum)
	{
		if (!g_type[i] || ((arg_type[i] & g_type[i]) != g_type[i]))
		{
			set_invalid_offset(p, t_dir_type, offset);
			return (1);
		}
	}
	return (0);
}

t_bool		check_reg(t_process *p, int t_dir_type, int *offset)
{
	int		i;
	int		pos;
	char	r_num;

	i = -1;
	pos = *offset;
	while (++i < g_op_tab[p->op_buff.op - 1].argnum)
	{
		if (g_type[i] == T_REG)
		{
			r_num = g_arena.memory[M(p->pc + pos)];
			pos++;
			if (!is_valid_reg(r_num))
			{
				set_invalid_offset(p, t_dir_type, offset);
				return (1);
			}
		}
		if (g_type[i] == T_DIR)
			pos += t_dir_type == SHORT_TDIR ? IND_SIZE : DIR_SIZE;
		if (g_type[i] == T_IND)
			pos += IND_SIZE;
	}
	return (0);
}

t_bool		check_operation(t_process *p, int t_dir_type, int *offset)
{
	if (check_type_code(p, t_dir_type, offset)
			|| check_reg(p, t_dir_type, offset))
	{
		p->pc = M(p->pc + *offset);
		return (1);
	}
	return (0);
}
