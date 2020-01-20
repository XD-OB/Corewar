/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instructs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:01:51 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/20 07:05:53 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		add_to_listlabel(t_chr **list_label, char *str)
{
	char		*label;

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

static int		get_inst(t_sfile *sfile, t_chr **list_label,
							char *str, int len)
{
	if (is_alonelabel(str))
		add_to_listlabel(list_label, str);
	else if (is_instlabel(sfile->op_tab, str))
		add_instlabel(sfile, list_label, str, len);
	else if (is_aloneinst(sfile->op_tab, str))
		add_aloneinst(sfile, list_label, str, len);
	else
		return (0);
	return (1);
}

static void		get_insts_basic(t_sfile *sfile, t_chr *begin)
{
	t_chr		*list_label;
	t_chr		*curr;
	char		*str;

	curr = begin;
	list_label = NULL;
	while (curr)
	{
		str = ft_strtrim(curr->str);
		if (str[0] != '\0')
			if (!get_inst(sfile, &list_label, str, curr->len))
			{
				free(str);
				chr_free(&list_label);
				exit_inst_error(sfile, curr);
			}
		curr = curr->next;
		free(str);
	}
	if (list_label)
		add_lonely_labels(sfile, &list_label);
}

void			get_instructs(t_sfile *sfile, t_chr *begin)
{
	t_list		*curr;
	t_inst		*inst;
	int			bytes;

	get_insts_basic(sfile, begin);
	get_insts_values(sfile);
	bytes = 0;
	curr = sfile->insts;
	while (curr)
	{
		inst = (t_inst*)curr->content;
		bytes += inst->nbr_bytes;
		curr = curr->next;
	}
	sfile->exec_size = bytes;
}
