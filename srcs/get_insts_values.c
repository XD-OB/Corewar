/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_insts_values.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:41:25 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/18 20:41:38 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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

static int		calcul_arithm(char *str)
{
	int			n1;
	int			n2;
	int			i;

	n1 = ft_atoi(&str[1]);
	i = 1;
	if (str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == ' ')
		i++;
	n2 = ft_atoi(&str[i + 1]);
	if (str[i] == '+')
		return (n1 + n2);
	if (str[i] == '-')
		return (n1 - n2);
	if (str[i] == '*')
		return (n1 * n2);
	return (n1 / n2);
}

void			fill_inst_values(t_sfile *sfile, t_inst *inst)
{
	char		*label;
	t_inst		*label_pos;
	int			i;

	i = 0;
	while (i < sfile->op_tab[inst->op_nbr - 1].args_nbr)
	{
		if (inst->args[i].str[0] != LABEL_CHAR)
		{
			if (inst->args[i].str[0] == '(')
				inst->args[i].value = calcul_arithm(inst->args[i].str);
			else
				inst->args[i].value = ft_atoi(inst->args[i].str);
		}
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
		if (inst->op_nbr)
			fill_inst_values(sfile, inst);
		curr = curr->next;
	}
}
