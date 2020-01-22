/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instructs_bin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:42:42 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/22 01:06:46 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		fill_args_no_atc(t_bfile *bfile, unsigned char *binary,
		t_inst *inst)
{
	int			tdir_size;

	tdir_size = bfile->op_tab[inst->op_nbr - 1].tdir_size;
	inst->nbr_bytes = 1 + tdir_size;
	if (bfile->index + inst->nbr_bytes > bfile->exec_size)
		exit_dis_error(bfile, inst, ERROR_INCOMPLET_OP);
	inst->args[0].type = T_DIR;
	if (tdir_size == 4)
		inst->args[0].value = int_4_bytes(&binary[1]);
	else
		inst->args[0].value = int_2_bytes(&binary[1]);
}

static char		*ft_strrcjoin(char c, char *str)
{
	char		*new;
	char		*car;

	car = ft_strcnew(1, c);
	new = ft_strjoin(car, str);
	free(car);
	return (new);
}

static void		fill_args_str(t_inst *inst)
{
	char		*val_str;
	int			i;

	i = 0;
	while (i < 3)
	{
		if (inst->args[i].type)
		{
			val_str = ft_itoa(inst->args[i].value);
			if (inst->args[i].type == T_REG)
				inst->args[i].str = ft_strjoin("r", val_str);
			else if (inst->args[i].type == T_DIR)
				inst->args[i].str = ft_strrcjoin(DIRECT_CHAR, val_str);
			else
				inst->args[i].str = ft_strdup(val_str);
			free(val_str);
		}
		i++;
	}
}

static t_inst	*fill_inst_bin(t_bfile *bfile, unsigned char *binary)
{
	t_inst		*inst;

	if (!(inst = create_inst()))
		exit_berror(bfile, ERROR_ALLOC);
	inst->op_nbr = (int)binary[0];
	if (inst->op_nbr == 0 || inst->op_nbr > 16)
		exit_dis_error(bfile, inst, ERROR_WRONG_OP);
	if (bfile->op_tab[inst->op_nbr - 1].atc)
		fill_args_atc(bfile, binary, inst);
	else
		fill_args_no_atc(bfile, binary, inst);
	fill_args_str(inst);
	return (inst);
}

void			get_instructs_bin(t_bfile *bfile)
{
	t_inst		*inst;
	t_list		*node;

	while (bfile->index < bfile->exec_size)
	{
		inst = fill_inst_bin(bfile, &bfile->exec_code[bfile->index]);
		node = ft_lstnew_sm(inst, sizeof(inst));
		ft_lstadd_last(&bfile->insts, node);
		bfile->index += inst->nbr_bytes;
	}
}
