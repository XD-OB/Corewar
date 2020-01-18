/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:02:52 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/18 20:02:54 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	exit_usage(char *exe)
{
	ft_printf("%{red}Usage:%{eoc} %s", exe);
	ft_printf(" [-ra] <sourcefile.s> ...\n");
	ft_printf("  --reverse   -r : deassembler mode\n");
	ft_printf("  --annotated -a : annotated mode\n");
	exit(EXIT_FAILURE);
}

void	exit_error_label(t_sfile *sfile, t_inst *inst, char *label)
{
	ft_printf("line %{red}%d%{eoc}:", inst->line);
	ft_printf("Invalid Label [%s] As Argument!\n", label);
	free_sfile(sfile);
	exit(EXIT_FAILURE);
}

void	exit_dis_error(t_bfile *bfile, t_inst *inst, int type)
{
	ft_printf("Byte %{red}%d%{eoc}: ", bfile->index);
	if (type == ERROR_WRONG_OP)
		ft_printf("Invalid Id Operation! [ %d ]\n", inst->op_nbr);
	if (type == ERROR_WRONG_ATC)
		ft_printf("Invalid Argument Type Code for %{green}%s%{eoc}!\n",
				bfile->op_tab[inst->op_nbr - 1].name);
	if (type == ERROR_INCOMPLET_OP)
		ft_printf("Less Bytes to treate The Operations! %{green}%s%{green}\n",
				bfile->op_tab[inst->op_nbr - 1].name);
	free_bfile(bfile);
	free_inst(inst);
	exit(EXIT_FAILURE);
}

void	exit_ass_error(t_sfile *sfile, t_chr *def, int type)
{
	ft_printf("line %{red}%d%{eoc}:", def->len);
	if (type == ERROR_NAME_LENGTH)
	{
		ft_printf(" Champion name is too long ");
		ft_printf("(Max length %d)\n", PROG_NAME_LENGTH);
	}
	else if (type == ERROR_COMMENT_LENGTH)
	{
		ft_printf(" Champion comment is too long ");
		ft_printf("(Max length %d)\n", COMMENT_LENGTH);
	}
	else if (type == ERROR_LEXICAL)
		ft_printf(" Lexical Error!\n");
	else if (type == ERROR_NC_NAME_CMT)
	{
		ft_printf(" Syntax Error! Wrong line ");
		ft_printf("or Executable Code before name and comment!\n");
	}
	else if (type == ERROR_BAD_INSTRUCT)
	{
		ft_printf(" Syntax Error! Bad Instruction! ");
		ft_printf("%{green}[%{eoc}%s%{green}]%{eoc}\n", def->str);
	}
	free_sfile(sfile);
	exit(EXIT_FAILURE);
}
