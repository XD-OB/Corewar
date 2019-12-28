#include "./includes/asm.h"

int			init_sfile(t_sfile *sfile, int fd)
{
	sfile->name = NULL;
	sfile->comment = NULL;
	sfile->insts = NULL;
	sfile->cmds = NULL;
	if (!(sfile->sf = file_save_chr(fd)))
		return (0);
	if (!(sfile->op_tab = (t_op*)malloc(sizeof(t_op) * 16)))
		return (0);
	fill_op_tab(sfile->op_tab);
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

static void		free_cmds(t_list **list_cmds)
{
	t_list		*curr;
	t_cmd		*cmd;

	curr = *list_cmds;
	while (curr)
	{
		cmd = (t_cmd*)curr->content;
		if (cmd->op)
			free(cmd->op);
		if (cmd->labels)
			chr_free(&(cmd->labels));
		if (cmd->args[0])
			free(cmd->args[0]);
		if (cmd->args[1])
			free(cmd->args[1]);
		if (cmd->args[2])
			free(cmd->args[2]);
		free(cmd);
		*list_cmds = curr;	
		curr = curr->next;
		free(*list_cmds);
	}
}

static void		free_insts(t_list **list_insts)
{
	t_list		*curr;
	t_inst		*inst;

	curr = *list_insts;
	while (curr)
	{
		free(curr->content);
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
	free_op_tab(&(sfile->op_tab));
	if (sfile->cmds)
		free_cmds(&(sfile->cmds));
	if (sfile->insts)
		free_insts(&(sfile->insts));
}
