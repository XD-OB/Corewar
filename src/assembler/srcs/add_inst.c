/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_inst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <aaguert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:39:30 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/25 07:28:39 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		calcul_nbr_bytes(t_op op_infos, t_inst *inst)
{
	int			i;

	inst->nbr_bytes = 1;
	if (op_infos.atc)
		inst->nbr_bytes++;
	i = 0;
	while (i < op_infos.args_nbr)
	{
		if (inst->args[i].type == T_REG)
			inst->nbr_bytes += 1;
		else if (inst->args[i].type == T_DIR)
			inst->nbr_bytes += op_infos.tdir_size;
		else if (inst->args[i].type == T_IND)
			inst->nbr_bytes += 2;
		i++;
	}
}

static void		fill_inst_args(t_inst *inst, char *str)
{
	char		**tab_args;
	int			i;

	tab_args = ft_strsplit_char(str, SEPARATOR_CHAR);
	tabstr_trim(tab_args);
	i = 0;
	while (i < tabstr_len(tab_args))
	{
		inst->args[i].type = type_arg(tab_args[i]);
		if (inst->args[i].type == T_IND)
			inst->args[i].str = ft_strdup(tab_args[i]);
		else
			inst->args[i].str = ft_strdup(&tab_args[i][1]);
		i++;
	}
	tabstr_free(&tab_args);
}

void			add_aloneinst(t_sfile *sfile, t_chr **list_label,
								char *str, int len)
{
	t_list		*node;
	t_inst		*inst;
	char		*op_name;
	int			i;

	i = 0;
	if (!(inst = create_inst()))
	{
		chr_free(list_label);
		exit_serror(sfile, ERROR_ALLOC);
	}
	inst->labels = *list_label;
	while (str[i] && !ft_isblank(str[i]) && str[i] != DIRECT_CHAR)
		i++;
	op_name = ft_strsub(str, 0, i);
	inst->op_nbr = is_op(sfile->op_tab, op_name);
	free(op_name);
	inst->line = len;
	while (ft_isblank(str[i]))
		i++;
	fill_inst_args(inst, &str[i]);
	calcul_nbr_bytes(sfile->op_tab[inst->op_nbr - 1], inst);
	node = ft_lstnew_sm(inst, sizeof(inst));
	ft_lstadd_last(&sfile->insts, node);
	*list_label = NULL;
}
