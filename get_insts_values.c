#include "./includes/asm.h"

static t_inst	*find_label_pos(t_list *list_insts, char *label)
{
	t_inst		*inst;
	t_list		*curr;
	t_chr		*tmp;

	curr = list_insts;
	while (curr)
	{
		inst = (t_inst*)curr->content;
		tmp = inst->labels;
		while (tmp)
		{
			if (!ft_strcmp(tmp->str, label))
				return (inst);
			tmp = tmp->next;
		}
		curr = curr->next;
	}
	return (NULL);
}

static void		fill_inst_values(t_sfile *sfile, t_inst *inst)
{
	t_list		*curr;
	char		*label;
	t_inst		*label_pos;
	int			i;

	i = 0;
	while (i < sfile->op_tab[inst->op_nbr - 1].args_nbr)
	{
		if ((inst->args[i].str)[0] != LABEL_CHAR)
			inst->args[i].value = ft_atoi(inst->args[i].str);
		else
		{
			label = &((inst->args[i].str)[1]);
			label_pos = find_label_pos(sfile->insts, label);
			if (!label_pos)
				exit_error_label(sfile, inst, label);
			inst->args[i].value = replace_label(sfile->insts, inst, label_pos);
		}
		i++;
	}
}

void			get_insts_values(t_sfile *sfile)
{
	t_list		*curr;
	t_inst		*inst;

	curr = sfile->insts;
	while (curr)
	{
		inst = (t_inst*)curr->content;
		fill_inst_values(sfile, inst);
		curr = curr->next;
	}
}
