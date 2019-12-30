#include "asm.h"

int			init_sfile(t_sfile *sfile, int fd)
{
	sfile->name = NULL;
	sfile->comment = NULL;
	sfile->insts = NULL;
	if (!(sfile->op_tab = (t_op*)malloc(sizeof(t_op) * 16)))
		return (0);
	fill_op_tab(sfile->op_tab);
	if (!(sfile->sf = file_save_chr(fd)))
		return (0);
	return (1);
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
	t_inst		*inst;
	int			i;

	curr = *list_insts;
	while (curr)
	{
		inst = (t_inst*)curr->content;
		if (inst->op_name)
			free(inst->op_name);
		if (inst->labels)
			chr_free(&(inst->labels));
		i = -1;
		while (++i < 3)
			if (inst->args[i].str)
				free(inst->args[i].str);
		free(inst);
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
}
