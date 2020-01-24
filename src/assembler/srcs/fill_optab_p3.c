/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_optab_p3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:02:18 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/18 20:02:20 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		fill_op_tab_9(t_op *op_case)
{
	op_case->name = ft_strdup("zjmp");
	op_case->nbr = 9;
	op_case->args_nbr = 1;
	op_case->args_type[0] = T_DIR;
	op_case->args_type[1] = 0;
	op_case->args_type[2] = 0;
	op_case->atc = 0;
	op_case->tdir_size = IND_SIZE;
}

static void		fill_op_tab_10(t_op *op_case)
{
	op_case->name = ft_strdup("ldi");
	op_case->nbr = 10;
	op_case->args_nbr = 3;
	op_case->args_type[0] = T_REG | T_DIR | T_IND;
	op_case->args_type[1] = T_REG | T_DIR;
	op_case->args_type[2] = T_REG;
	op_case->atc = 1;
	op_case->tdir_size = IND_SIZE;
}

static void		fill_op_tab_11(t_op *op_case)
{
	op_case->name = ft_strdup("sti");
	op_case->nbr = 11;
	op_case->args_nbr = 3;
	op_case->args_type[0] = T_REG;
	op_case->args_type[1] = T_REG | T_DIR | T_IND;
	op_case->args_type[2] = T_REG | T_DIR;
	op_case->atc = 1;
	op_case->tdir_size = IND_SIZE;
}

static void		fill_op_tab_12(t_op *op_case)
{
	op_case->name = ft_strdup("fork");
	op_case->nbr = 12;
	op_case->args_nbr = 1;
	op_case->args_type[0] = T_DIR;
	op_case->args_type[1] = 0;
	op_case->args_type[2] = 0;
	op_case->atc = 0;
	op_case->tdir_size = IND_SIZE;
}

void			fill_optab_p3(t_op *op_tab)
{
	fill_op_tab_9(&op_tab[8]);
	fill_op_tab_10(&op_tab[9]);
	fill_op_tab_11(&op_tab[10]);
	fill_op_tab_12(&op_tab[11]);
}
