/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:02:52 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/26 00:04:59 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			exit_error_label(t_sfile *sfile, t_inst *inst, char *label)
{
	ft_dprintf(2, "line %{red}%d%{eoc}:", inst->line);
	ft_dprintf(2, "Invalid Label [%s] As Argument!\n", label);
	close(sfile->param_asm.fd);
	free_sfile(sfile);
	exit(EXIT_FAILURE);
}

void			exit_dis_error(t_bfile *bfile, t_inst *inst, int type)
{
	ft_dprintf(2, "Byte %{red}%d%{eoc}: ", bfile->index);
	if (type == ERROR_WRONG_OP)
		ft_dprintf(2, "Invalid Id Operation! [ %d ]\n", inst->op_nbr);
	if (type == ERROR_WRONG_ATC)
		ft_dprintf(2, "Invalid Argument Type Code for %{green}%s%{eoc}!\n",
				bfile->op_tab[inst->op_nbr - 1].name);
	if (type == ERROR_INCOMPLET_OP)
		ft_dprintf(2, "Less Bytes to treate The Operations! %{green}%s%{eoc}\n",
				bfile->op_tab[inst->op_nbr - 1].name);
	close(bfile->param_asm.fd);
	free_bfile(bfile);
	free_inst(inst);
	exit(EXIT_FAILURE);
}

static void		error_name_cmt(t_chr *def)
{
	char		**tab;
	char		*str;

	str = NULL;
	tab = ft_strsplit(def->str, ' ');
	if (tabstr_len(tab) > 0)
	{
		str = ft_strtrim(tab[0]);
		if (str[0] == '.')
		{
			if (ft_strequ(str, ".name") || ft_strequ(str, ".comment"))
				ft_dprintf(2, " Duplicate command! [ %{red}%s%{eoc} ]", str);
			else
				ft_dprintf(2, " Wrong command! [ %{red}%s%{eoc} ]", str);
		}
		else
		{
			ft_dprintf(2, " Syntax Error! Wrong line ");
			ft_dprintf(2, "before name and comment!");
		}
	}
	tabstr_free(&tab);
	if (str)
		free(str);
}

void			exit_ass_error(t_sfile *sfile, t_chr *def, int type)
{
	if (def)
		ft_dprintf(2, "line %{red}%d%{eoc}: ", def->len);
	if (type == ERROR_NAME_LENGTH)
		ft_dprintf(2, "Champion name is too long (Max length %d)",
					PROG_NAME_LENGTH);
	else if (type == ERROR_COMMENT_LENGTH)
		ft_dprintf(2, "Champion comment is too long (Max length %d)",
					COMMENT_LENGTH);
	else if (type == ERROR_LEXICAL)
		ft_dprintf(2, "Lexical Error!");
	else if (type == ERROR_QUOTES)
		ft_dprintf(2, "Command Quotes Error!");
	else if (type == ERROR_NC_NAMECMT)
		error_name_cmt(def);
	else if (type == ERROR_BAD_INSTRUCT)
	{
		ft_dprintf(2, "Syntax Error! Bad Instruction! ");
		if (def)
			ft_dprintf(2, "%{green}[%{eoc}%s%{green}]%{eoc}", def->str);
	}
	ft_putchar_fd('\n', 2);
	close(sfile->param_asm.fd);
	free_sfile(sfile);
	exit(EXIT_FAILURE);
}
