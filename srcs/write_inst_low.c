#include "asm.h"

static void		write_inst_low_dir(t_bfile bfile, t_inst *inst, int *bytes)
{
	char		*str;

	if (bfile.op_tab[inst->op_nbr - 1].tdir_size == 4)
	{
		str = itohex_w2(bfile.exec_code[(*bytes)++]);
		ft_printf("  %c%s", DIRECT_CHAR, str);
		free(str);
		str = itohex_w2(bfile.exec_code[(*bytes)++]);
		ft_printf("%s", str);
		free(str);
		str = itohex_w2(bfile.exec_code[(*bytes)++]);
		ft_printf("%s", str);
		free(str);
		str = itohex_w2(bfile.exec_code[(*bytes)++]);
		ft_printf("%s", str);
		free(str);
		return ;
	}
	str = itohex_w2(bfile.exec_code[(*bytes)++]);
	ft_printf("      %c%s", DIRECT_CHAR, str);
	free(str);
	str = itohex_w2(bfile.exec_code[(*bytes)++]);
	ft_printf("%s", str);
	free(str);
}

static void		write_inst_low_ind(t_bfile bfile, int *bytes)
{
	char		*str;

	str = itohex_w2(bfile.exec_code[(*bytes)++]);
	ft_printf("       %s", str);
	free(str);
	str = itohex_w2(bfile.exec_code[(*bytes)++]);
	ft_printf("%s", str);
	free(str);
}

static void		write_inst_low_reg(t_bfile bfile, int *bytes)
{
	char		*str;

	ft_putstr("        r");
	str = itohex_w2(bfile.exec_code[(*bytes)++]);
	ft_printf("%s", str);
	free(str);
}

void			write_inst_low(t_bfile bfile, t_inst *inst, int bytes)
{
	char		*str;
	int			i;

	str = itohex_w2(bfile.exec_code[bytes++]);
	ft_printf("0x%s  ", str);
	free(str);
	if (bfile.op_tab[inst->op_nbr - 1].atc)
	{
		str = itobin_w8(bfile.exec_code[bytes++]);
		ft_putstr(str);
		free(str);
	}
	else
		ft_putstr("        ");
	i = -1;
	while (++i < bfile.op_tab[inst->op_nbr - 1].args_nbr)
	{
		if (inst->args[i].type == T_REG)
			write_inst_low_reg(bfile, &bytes);
		else if (inst->args[i].type == T_IND)
			write_inst_low_ind(bfile, &bytes);
		else
			write_inst_low_dir(bfile, inst, &bytes);
	}
	ft_putchar('\n');
}
