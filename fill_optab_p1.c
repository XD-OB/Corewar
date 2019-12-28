#include "./includes/asm.h"

static void		fill_op_tab_1(t_op *op_case)
{
	op_case->name = ft_strdup("live");
	op_case->nbr = 1;
	op_case->args_nbr = 1;
	op_case->args_type[0] = T_DIR;
	op_case->args_type[1] = 0;
	op_case->args_type[2] = 0;
	op_case->args_type_code = 0;
	op_case->tdir_size = REG_SIZE;
}

static void		fill_op_tab_2(t_op *op_case)
{
	op_case->name = ft_strdup("ld");
	op_case->nbr = 2;
	op_case->args_nbr = 2;
	op_case->args_type[0] = T_DIR | T_IND;
	op_case->args_type[1] = T_REG;
	op_case->args_type[2] = 0;
	op_case->args_type_code = 1;
	op_case->tdir_size = REG_SIZE;
}

static void		fill_op_tab_3(t_op *op_case)
{
	op_case->name = ft_strdup("st");
	op_case->nbr = 3;
	op_case->args_nbr = 2;
	op_case->args_type[0] = T_REG;
	op_case->args_type[1] = T_REG | T_IND;
	op_case->args_type[2] = 0;
	op_case->args_type_code = 1;
	op_case->tdir_size = REG_SIZE;
}

static void		fill_op_tab_4(t_op *op_case)
{
	op_case->name = ft_strdup("add");
	op_case->nbr = 4;
	op_case->args_nbr = 3;
	op_case->args_type[0] = T_REG;
	op_case->args_type[1] = T_REG;
	op_case->args_type[2] = T_REG;
	op_case->args_type_code = 1;
	op_case->tdir_size = REG_SIZE;
}

void			fill_optab_p1(t_op *op_tab)
{
	fill_op_tab_1(&op_tab[0]);
	fill_op_tab_2(&op_tab[1]);
	fill_op_tab_3(&op_tab[2]);
	fill_op_tab_4(&op_tab[3]);
}
