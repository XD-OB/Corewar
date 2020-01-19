/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:02:52 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/19 01:24:41 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	exit_usage(char *exe)
{
	ft_dprintf(2, "%{red}Usage:%{eoc} %s", exe);
	ft_dprintf(2, " [-ra] <sourcefile.s> ...\n");
	ft_dprintf(2, "  --reverse   -r : deassembler mode\n");
	ft_dprintf(2, "  --annotated -a : annotated mode\n");
	exit(EXIT_FAILURE);
}

void	exit_error_label(t_sfile *sfile, t_inst *inst, char *label)
{
	ft_dprintf(2, "line %{red}%d%{eoc}:", inst->line);
	ft_dprintf(2, "Invalid Label [%s] As Argument!\n", label);
	free_sfile(sfile);
	exit(EXIT_FAILURE);
}

void	exit_dis_error(t_bfile *bfile, t_inst *inst, int type)
{
	ft_dprintf(2, "Byte %{red}%d%{eoc}: ", bfile->index);
	if (type == ERROR_WRONG_OP)
		ft_dprintf(2, "Invalid Id Operation! [ %d ]\n", inst->op_nbr);
	if (type == ERROR_WRONG_ATC)
		ft_dprintf(2, "Invalid Argument Type Code for %{green}%s%{eoc}!\n",
				bfile->op_tab[inst->op_nbr - 1].name);
	if (type == ERROR_INCOMPLET_OP)
		ft_dprintf(2, "Less Bytes to treate The Operations! %{green}%s%{green}\n",
				bfile->op_tab[inst->op_nbr - 1].name);
	free_bfile(bfile);
	free_inst(inst);
	exit(EXIT_FAILURE);
}

void	exit_ass_error(t_sfile *sfile, t_chr *def, int type)
{
	ft_dprintf(2, "line %{red}%d%{eoc}:", def->len);
	if (type == ERROR_NAME_LENGTH)
	{
		ft_dprintf(2, " Champion name is too long ");
		ft_dprintf(2, "(Max length %d)\n", PROG_NAME_LENGTH);
	}
	else if (type == ERROR_COMMENT_LENGTH)
	{
		ft_dprintf(2, " Champion comment is too long ");
		ft_dprintf(2, "(Max length %d)\n", COMMENT_LENGTH);
	}
	else if (type == ERROR_LEXICAL)
		ft_dprintf(2, " Lexical Error!\n");
	else if (type == ERROR_NC_NAME_CMT)
	{
		ft_dprintf(2, " Syntax Error! Wrong line ");
		ft_dprintf(2, "or Executable Code before name and comment!\n");
	}
	else if (type == ERROR_BAD_INSTRUCT)
	{
		ft_dprintf(2, " Syntax Error! Bad Instruction! ");
		ft_dprintf(2, "%{green}[%{eoc}%s%{green}]%{eoc}\n", def->str);
	}
	free_sfile(sfile);
	exit(EXIT_FAILURE);
}
