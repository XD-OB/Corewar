#include "asm.h"

static void		add_to_listlabel(t_chr **list_label, char *str)
{
	char		*label;

	//ft_printf("|%s| label only\n", str);			////////////////
	label = ft_strsub(str, 0, ft_strlen(str) - 1);
	chr_addnode_sm(list_label, label, 0);
}

static void		add_lonely_labels(t_sfile *sfile, t_chr **list_label)
{
	t_inst		*inst;
	t_list		*node;

	if (!(inst = create_inst()))
	{
		chr_free(list_label);
		exit_serror(sfile, ERROR_ALLOC);
	}
	inst->labels = *list_label;
	node = ft_lstnew_sm(inst, sizeof(inst));
	ft_lstadd_last(&sfile->insts, node);
}

static void		get_insts_basic(t_sfile *sfile, t_chr *begin)
{
	t_chr		*list_label;
	t_chr		*curr;

	curr = begin;
	list_label = NULL;
	while (curr)
	{
		if (curr->str[0] != COMMENT_CHAR && curr->str[0] != '\0')
		{
			if (is_alonelabel(curr->str))
				add_to_listlabel(&list_label, curr->str);
			else if (is_instlabel(sfile->op_tab, curr->str))
				add_instlabel(sfile, &list_label, curr->str, curr->len);
			else if (is_aloneinst(sfile->op_tab, curr->str))
				add_aloneinst(sfile, &list_label, curr->str, curr->len);
			else
			{
				chr_free(&list_label);
				exit_inst_error(sfile, curr);
			}
		}
		curr = curr->next;
	}
	if (list_label)
		add_lonely_labels(sfile, &list_label);
}

static void		check_exec_size(t_sfile *sfile)
{
	t_list		*curr;
	t_inst		*inst;
	int			bytes;

	bytes = 0;
	curr = sfile->insts;
	while (curr)
	{
		inst = (t_inst*)curr->content;
		bytes += inst->nbr_bytes;
		curr = curr->next;
	}
	if (bytes > CHAMP_MAX_SIZE)
		exit_serror(sfile, ERROR_EXEC_SIZE);
	sfile->exec_size = bytes;
}

void			get_instructs(t_sfile *sfile, t_chr *begin)
{
	get_insts_basic(sfile, begin);
	get_insts_values(sfile);
	check_exec_size(sfile);
}
