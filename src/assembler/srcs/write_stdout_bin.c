/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_stdout_bin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:59:57 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/19 07:11:03 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		write_inst_med_dir(t_bfile bfile, t_inst *inst, int *bytes)
{
	if (bfile.op_tab[inst->op_nbr - 1].tdir_size == 4)
	{
		ft_printf("  %c%02d", DIRECT_CHAR, bfile.exec_code[(*bytes)++]);
		ft_printf("%02d", bfile.exec_code[(*bytes)++]);
		ft_printf("%02d", bfile.exec_code[(*bytes)++]);
		ft_printf("%02d", bfile.exec_code[(*bytes)++]);
	}
	else
	{
		ft_printf("      %c%02d", DIRECT_CHAR, bfile.exec_code[(*bytes)++]);
		ft_printf("%02d", bfile.exec_code[(*bytes)++]);
	}
}

static void		write_inst_med(t_bfile bfile, t_inst *inst, int bytes)
{
	int			i;

	ft_printf("%-4d  ", inst->op_nbr);
	bytes++;
	if (bfile.op_tab[inst->op_nbr - 1].atc)
		ft_printf("%8d", bfile.exec_code[bytes++]);
	else
		ft_putstr("        ");
	i = -1;
	while (++i < bfile.op_tab[inst->op_nbr - 1].args_nbr)
	{
		if (inst->args[i].type == T_REG)
			ft_printf("        r%02d", bfile.exec_code[bytes++]);
		else if (inst->args[i].type == T_IND)
		{
			ft_printf("       %02d", bfile.exec_code[bytes++]);
			ft_printf("%02d", bfile.exec_code[bytes++]);
		}
		else
			write_inst_med_dir(bfile, inst, &bytes);
	}
	ft_putchar('\n');
}

static void		write_inst_high(t_bfile bfile, t_inst *inst, int bytes)
{
	int			i;

	ft_printf("%-6s", bfile.op_tab[inst->op_nbr - 1].name);
	bytes++;
	ft_putstr("        ");
	i = -1;
	while (++i < bfile.op_tab[inst->op_nbr - 1].args_nbr)
		ft_printf("%11s", inst->args[i].str);
	ft_putchar('\n');
}

static void		write_stdout_bin_inst(t_bfile bfile, t_inst *inst, int bytes)
{
	ft_printf("%-5d (%3d):\n", bytes, inst->nbr_bytes);
	write_inst_low(bfile, inst, bytes);
	write_inst_med(bfile, inst, bytes);
	write_inst_high(bfile, inst, bytes);
	ft_putchar('\n');
}

void			write_stdout_bin(t_bfile bfile)
{
	t_list		*curr;
	t_inst		*inst;
	int			bytes;

	ft_putendl("       Annotated program:");
	ft_printf("%{green}==========================================");
	ft_printf("===========================================%{eoc}\n");
	ft_printf("Name    : \"%{CYAN}%s%{eoc}\"\n", bfile.name);
	ft_printf("Comment : \"%{CYAN}%s%{eoc}\"\n", bfile.comment);
	ft_printf("Program size : %{CYAN}%u%{eoc} byte(s)\n\n", bfile.exec_size);
	bytes = 0;
	curr = bfile.insts;
	while (curr)
	{
		inst = (t_inst*)curr->content;
		write_stdout_bin_inst(bfile, inst, bytes);
		bytes += inst->nbr_bytes;
		curr = curr->next;
	}
	ft_printf("%{green}==========================================");
	ft_printf("===========================================%{eoc}\n");
}
