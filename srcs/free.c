/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:02:26 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/19 05:27:09 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			free_inst(t_inst *inst)
{
	int			i;

	if (inst->labels)
		chr_free(&(inst->labels));
	i = -1;
	while (++i < 3)
		if (inst->args[i].str)
			free(inst->args[i].str);
	free(inst);
}

static void		free_op_tab(t_op **op_tab)
{
	int			i;

	i = 0;
	while (i < 16)
		free((*op_tab)[i++].name);
	free(*op_tab);
}

static void		free_insts(t_list **list_insts)
{
	t_list		*curr;

	curr = *list_insts;
	while (curr)
	{
		free_inst((t_inst*)curr->content);
		*list_insts = curr;
		curr = curr->next;
		free(*list_insts);
	}
}

void			free_sfile(t_sfile *sfile)
{
	if (sfile->name)
		free(sfile->name);
	if (sfile->comment)
		free(sfile->comment);
	if (sfile->sf)
		chr_free(&(sfile->sf));
	if (sfile->op_tab)
		free_op_tab(&(sfile->op_tab));
	if (sfile->insts)
		free_insts(&(sfile->insts));
	if (sfile->file_name)
		free(sfile->file_name);
}

void			free_bfile(t_bfile *bfile)
{
	if (bfile->exec_code)
		free(bfile->exec_code);
	if (bfile->op_tab)
		free_op_tab(&(bfile->op_tab));
	if (bfile->insts)
		free_insts(&(bfile->insts));
	if (bfile->file_name)
		free(bfile->file_name);
}
