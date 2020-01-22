/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:01:11 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/22 05:07:04 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	init_asmbl(t_asm *asmbl)
{
	asmbl->fd = -1;
	asmbl->r = 0;
	asmbl->a = 0;
	asmbl->multi = 0;
}

int		init_bfile(t_bfile *bfile)
{
	bfile->index = 0;
	bfile->insts = NULL;
	bfile->exec_code = NULL;
	if (!(bfile->op_tab = (t_op*)malloc(sizeof(t_op) * 16)))
		return (0);
	fill_op_tab(bfile->op_tab);
	return (1);
}

int		init_sfile(t_sfile *sfile, int fd)
{
	sfile->name = NULL;
	sfile->comment = NULL;
	sfile->insts = NULL;
	sfile->sf = NULL;
	sfile->file_name = NULL;
	if (!(sfile->op_tab = (t_op*)malloc(sizeof(t_op) * 16)))
		return (0);
	fill_op_tab(sfile->op_tab);
	if (!(sfile->sf = file_save_chr(fd)))
		return (-1);
	return (1);
}
