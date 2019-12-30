#include "asm.h"

static void		fill_op_tab_5(t_op *op_case)
{
	op_case->name = ft_strdup("sub");
	op_case->nbr = 5;
	op_case->args_nbr = 3;
	op_case->args_type[0] = T_REG;
	op_case->args_type[1] = T_REG;
	op_case->args_type[2] = T_REG;
	op_case->atc = 1;
	op_case->tdir_size = REG_SIZE;
}

static void		fill_op_tab_6(t_op *op_case)
{
	op_case->name = ft_strdup("and");
	op_case->nbr = 6;
	op_case->args_nbr = 3;
	op_case->args_type[0] = T_REG | T_DIR | T_IND;
	op_case->args_type[1] = T_REG | T_DIR | T_IND;
	op_case->args_type[2] = T_REG;
	op_case->atc = 1;
	op_case->tdir_size = REG_SIZE;
}

static void		fill_op_tab_7(t_op *op_case)
{
	op_case->name = ft_strdup("or");
	op_case->nbr = 7;
	op_case->args_nbr = 3;
	op_case->args_type[0] = T_REG | T_DIR | T_IND;
	op_case->args_type[1] = T_REG | T_DIR | T_IND;
	op_case->args_type[2] = T_REG;
	op_case->atc = 1;
	op_case->tdir_size = REG_SIZE;
}

static void		fill_op_tab_8(t_op *op_case)
{
	op_case->name = ft_strdup("xor");
	op_case->nbr = 8;
	op_case->args_nbr = 3;
	op_case->args_type[0] = T_REG | T_DIR | T_IND;
	op_case->args_type[1] = T_REG | T_DIR | T_IND;
	op_case->args_type[2] = T_REG;
	op_case->atc = 1;
	op_case->tdir_size = REG_SIZE;
}

void			fill_optab_p2(t_op *op_tab)
{
	fill_op_tab_5(&op_tab[4]);
	fill_op_tab_6(&op_tab[5]);
	fill_op_tab_7(&op_tab[6]);
	fill_op_tab_8(&op_tab[7]);
}
