#include "./includes/asm.h"

static void		fill_op_tab_13(t_op *op_case)
{
	op_case->name = ft_strdup("lld");
	op_case->nbr = 13;
	op_case->args_nbr = 2;
	op_case->args_type[0] = T_DIR | T_IND;
	op_case->args_type[1] = T_REG;
	op_case->args_type[2] = 0;
	op_case->atc = 1;
	op_case->tdir_size = REG_SIZE;
}

static void		fill_op_tab_14(t_op *op_case)
{
	op_case->name = ft_strdup("lldi");
	op_case->nbr = 14;
	op_case->args_nbr = 3;
	op_case->args_type[0] = T_REG | T_DIR | T_IND;
	op_case->args_type[1] = T_REG | T_DIR;
	op_case->args_type[2] = T_REG;
	op_case->atc = 1;
	op_case->tdir_size = IND_SIZE;
}

static void		fill_op_tab_15(t_op *op_case)
{
	op_case->name = ft_strdup("lfork");
	op_case->nbr = 15;
	op_case->args_nbr = 1;
	op_case->args_type[0] = T_DIR;
	op_case->args_type[1] = 0;
	op_case->args_type[2] = 0;
	op_case->atc = 0;
	op_case->tdir_size = IND_SIZE;
}

static void		fill_op_tab_16(t_op *op_case)
{
	op_case->name = ft_strdup("aff");
	op_case->nbr = 16;
	op_case->args_nbr = 1;
	op_case->args_type[0] = T_REG;
	op_case->args_type[1] = 0;
	op_case->args_type[2] = 0;
	op_case->atc = 1;
	op_case->tdir_size = REG_SIZE;
}

void			fill_op_tab(t_op *op_tab)
{
	fill_optab_p1(op_tab);
	fill_optab_p2(op_tab);
	fill_optab_p3(op_tab);
	fill_op_tab_13(&op_tab[12]);
	fill_op_tab_14(&op_tab[13]);
	fill_op_tab_15(&op_tab[14]);
	fill_op_tab_16(&op_tab[15]);
}
