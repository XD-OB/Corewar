/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_stdout.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:00:06 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/18 20:00:08 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		write_inst_lables(t_inst *inst, int bytes)
{
	t_chr		*label;

	if (inst->labels)
	{
		ft_printf("\n");
		label = inst->labels;
		while (label)
		{
			ft_printf("%-5d", bytes);
			ft_printf("      :   %s:\n", label->str);
			if (label->next)
				ft_printf("\n");
			label = label->next;
		}
	}
}

static void		write_inst_oparg(t_op op_infos, t_inst *inst, int bytes)
{
	char		*str;
	int			i;

	ft_printf("%-5d", bytes);
	ft_printf("(%3d) :      ", inst->nbr_bytes);
	ft_printf("%-5s", op_infos.name);
	i = 0;
	while (i < op_infos.args_nbr)
	{
		if (inst->args[i].type == T_REG)
			str = ft_strjoin("r", inst->args[i].str);
		else if (inst->args[i].type == T_DIR)
			str = ft_strjoin("%", inst->args[i].str);
		else
			str = ft_strdup(inst->args[i].str);
		ft_printf("%21s", str);
		free(str);
		i++;
	}
	ft_printf("\n");
}

static void		write_inst_basinfos(t_op op_infos, t_inst *inst)
{
	int			i;

	ft_printf("                  ");
	ft_printf("%-5d", inst->op_nbr);
	if (op_infos.atc)
		ft_printf("%5d", int_atc(inst));
	else
		ft_printf("     ");
	i = 0;
	ft_printf("%16d", inst->args[i].value);
	while (++i < op_infos.args_nbr)
		ft_printf("%21d", inst->args[i].value);
	ft_printf("\n");
}

static void		write_stdout_inst(t_op op_infos, t_inst *inst, int bytes)
{
	write_inst_lables(inst, bytes);
	if (inst->op_nbr)
	{
		write_inst_oparg(op_infos, inst, bytes);
		write_inst_basinfos(op_infos, inst);
		write_inst_advinfos(op_infos, inst);
	}
	ft_putchar('\n');
}

void			write_stdout(t_sfile sfile)
{
	t_list		*curr;
	t_inst		*inst;
	int			bytes;

	bytes = 0;
	ft_putendl("       Annotated program:");
	ft_printf("%{green}==========================================");
	ft_printf("===========================================%{eoc}\n");
	ft_printf("Name    : \"%{CYAN}%s%{eoc}\"\n", sfile.name);
	ft_printf("Comment : \"%{CYAN}%s%{eoc}\"\n", sfile.comment);
	ft_printf("Program size : %{CYAN}%d%{eoc} byte(s)\n\n", sfile.exec_size);
	curr = sfile.insts;
	while (curr)
	{
		inst = (t_inst*)curr->content;
		write_stdout_inst(sfile.op_tab[inst->op_nbr - 1], inst, bytes);
		bytes += inst->nbr_bytes;
		curr = curr->next;
	}
	ft_printf("%{green}==========================================");
	ft_printf("===========================================%{eoc}\n");
}
