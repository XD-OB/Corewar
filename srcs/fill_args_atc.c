#include "asm.h"

int				int_4_bytes(unsigned char *binary)
{
	int			res;

	res = 0;
	res = (binary[0] << 24) | (binary[1] << 16) |
		(binary[2] << 8) | binary[3];
	return (res);
}

int				int_2_bytes(unsigned char *binary)
{
	short		res;

	res = 0;
	res = (binary[0] << 8) | binary[1];
	return (res);
}

static void		check_atc(t_bfile *bfile, unsigned char *binary, t_inst *inst)
{
	unsigned char	c[4];
	int				i;

	if (bfile->index + 1 > bfile->exec_size)
		exit_dis_error(bfile, inst, ERROR_INCOMPLET_OP);
	c[0] = (binary[1] >> 6) & 0x3;
	c[1] = (binary[1] >> 4) & 0x3;
	c[2] = (binary[1] >> 2) & 0x3;
	c[3] = binary[1] & 0x3;
	if (c[3] != 0)
		exit_dis_error(bfile, inst, ERROR_WRONG_ATC);
	i = -1;
	while (++i < 3)
	{
		if (c[i] & 0x1)
			inst->args[i].type = T_REG;
		else if (c[i] == 0x2)
			inst->args[i].type = T_DIR;
		else if (c[i] == 0x3)
			inst->args[i].type = T_IND;
	}
	i = -1;
	while (++i < bfile->op_tab[inst->op_nbr - 1].args_nbr)
		if (!(inst->args[i].type & bfile->op_tab[inst->op_nbr - 1].args_type[i]))
			exit_dis_error(bfile, inst, ERROR_WRONG_ATC);
}

static int		calcul_args_bytes(t_op *op_tab, t_inst *inst)
{
	int			bytes;
	int			i;

	i = 0;
	bytes = 0;
	while (i < 3)
	{
		if (inst->args[i].type == T_REG)
			bytes += 1;
		if (inst->args[i].type == T_DIR)
			bytes += op_tab[inst->op_nbr - 1].tdir_size;
		if (inst->args[i].type == T_IND)
			bytes += 2;
		i++;
	}
	return (bytes);
}

void			fill_args_atc(t_bfile *bfile, unsigned char *binary, t_inst *inst)
{
	int			i;
	int			j;

	check_atc(bfile, binary, inst);
	inst->nbr_bytes =  2 + calcul_args_bytes(bfile->op_tab, inst);
	if (bfile->index + inst->nbr_bytes > bfile->exec_size)
		exit_dis_error(bfile, inst, ERROR_INCOMPLET_OP);
	i = -1;
	j = 2;
	while (++i < bfile->op_tab[inst->op_nbr - 1].args_nbr)
	{
		if (inst->args[i].type == T_REG)
			inst->args[i].value = (int)binary[j++];
		else if (inst->args[i].type == T_DIR &&
				bfile->op_tab[inst->op_nbr - 1].tdir_size == 4)
		{
			inst->args[i].value = int_4_bytes(&binary[j]);
			j += 4;
		}
		else
		{
			inst->args[i].value = int_2_bytes(&binary[j]);
			j += 2;
		}
	}
}
