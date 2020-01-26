/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treate_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:41:48 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/26 05:14:01 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		print_ferror(char *file, int type)
{
	if (type == ERROR_FILE_NF)
		ft_dprintf(2, "%{red}%s%{eoc}: File not found!\n", file);
	else if (type == ERROR_FILE_BE)
		ft_dprintf(2, "%{red}%s%{eoc}: File with Bad extension!\n", file);
}

static void		get_instructions(t_sfile *sfile, t_chr *curr)
{
	if (!curr)
	{
		if (sfile->name && sfile->comment)
			exit_serror(sfile, ERROR_NO_INSTS);
		else
			exit_serror(sfile, ERROR_NC_NAMECMT_END);
	}
	if (sfile->name && sfile->comment)
		get_instructs(sfile, curr);
	else
		exit_ass_error(sfile, curr, ERROR_NC_NAMECMT);
	if (sfile->nl == 2)		    /////////////
		exit_serror(sfile, ERROR_NO_NL);
}

static void		encode_asm(t_asm *asmbl, char *file)
{
	t_sfile		sfile;
	t_chr		*curr;
	int			error;

	sfile.param_asm = *asmbl;
	error = init_sfile(&sfile, asmbl->fd);
	if (error == 0)
		exit_serror(&sfile, ERROR_ALLOC);
	if (error == -1)
		exit_serror(&sfile, ERROR_FEMPTY);
	sfile.file_name = ft_strndup(file, ft_strlen(file) - 2);
	curr = sfile.sf;
	while (curr)
	{
		if (get_name_cmt(&sfile, curr, curr->str))
			break ;
		curr = curr->next;
	}
	get_instructions(&sfile, curr);
	//print_sfile(&sfile);				/////////////////////
	(asmbl->a) ? write_stdout(sfile) : write_cor(sfile);
	free_sfile(&sfile);
}

static void		decode_asm(t_asm *asmbl, char *file)
{
	t_bfile		bfile;

	bfile.param_asm = *asmbl;
	bfile.file_name = ft_strndup(file, ft_strlen(file) - 4);
	if (!init_bfile(&bfile))
		exit_berror(&bfile, ERROR_ALLOC);
	fill_bin(&bfile, asmbl->fd);
	get_instructs_bin(&bfile);
	if (asmbl->a)
		write_stdout_bin(bfile);
	else
		write_s(bfile);
	free_bfile(&bfile);
}

void			treate_file(char *file, t_asm *asmbl)
{
	asmbl->fd = open(file, O_RDONLY);
	if (asmbl->fd < 0)
		print_ferror(file, ERROR_FILE_NF);
	else
	{
		if (asmbl->r)
		{
			if (ft_ends_with(file, ".cor"))
				decode_asm(asmbl, file);
			else
				print_ferror(file, ERROR_FILE_BE);
		}
		else
		{
			if (ft_ends_with(file, ".s"))
				encode_asm(asmbl, file);
			else
				print_ferror(file, ERROR_FILE_BE);
		}
		close(asmbl->fd);
	}
}
