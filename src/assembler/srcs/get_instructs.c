/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instructs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:01:51 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/25 19:49:50 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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
	char		**tab;
	int			i;

	i = -1;
	tab = split_labels(str);
	while (++i < tabstr_len(tab) - 1)
	{
		if (!is_label(tab[i]))
			return (ret_tabstr_free(&tab, 0));
		chr_addnode(list_label, tab[i], 0);
	}
	if (str[ft_strlen(str) - 1] == LABEL_CHAR)
	{
		if (!is_label(tab[i]))
			return (ret_tabstr_free(&tab, 0));
		chr_addnode(list_label, tab[i], 0);
		return (ret_tabstr_free(&tab, 1));
	}
	if (!is_aloneinst(sfile->op_tab, tab[i]))
		return (ret_tabstr_free(&tab, 0));
	add_aloneinst(sfile, list_label, tab[i], len);
	return (ret_tabstr_free(&tab, 1));
}

static void		get_insts_basic(t_sfile *sfile, t_chr *begin)
{
	t_chr		*list_label;
	t_chr		*curr;

	curr = begin;
	list_label = NULL;
	while (curr)
	{
		if (curr->str[0] != '\0')
			if (!get_inst(sfile, &list_label, curr->str, curr->len))
			{
				chr_free(&list_label);
				exit_inst_error(sfile, curr);
			}
		curr = curr->next;
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
