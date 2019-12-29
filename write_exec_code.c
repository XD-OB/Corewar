#include "./includes/asm.h"

static void		write_inst_atc(t_inst *inst, int fd)
{
	char		arg[3];
	char		res;
	int			i;

	res = 0;
	i = 0;
	while (i < 3)
	{
		if (inst->args[i].type == T_REG)
			arg[i] = REG_CODE;
		else if (inst->args[i].type == T_DIR)
			arg[i] = DIR_CODE;
		else if (inst->args[i].type == T_IND)
			arg[i] = IND_CODE;
		i++;
	}
	arg[0] <<= 6;
	arg[1] <<= 4;
	arg[2] <<= 2;
	res = arg[0] | arg[1] | arg[2];
	ft_putchar_fd(res, fd);
}

static void		write_inst_arg(t_op op_infos, t_arg arg, int fd)
{
	if (arg.type == T_REG)
		ft_putchar_fd((char)arg.value, fd);
	else if (arg.type == T_DIR && op_infos.tdir_size == 4)
		write_int(arg.value, fd);
	else
		write_short((short)arg.value, fd);
}

static void		write_instruct(t_op op_infos, t_inst *inst, int fd)
{
	int			i;

	i = 0;
	ft_putchar_fd((char)inst->op_nbr, fd);
	if (op_infos.atc)
		write_inst_atc(inst, fd);
	while (i < op_infos.args_nbr)
		write_inst_arg(op_infos, inst->args[i++], fd);
}

void			write_exec_code(t_sfile sfile, int fd)
{
	t_list		*curr;
	t_inst		*inst;

	curr = sfile.insts;
	while (curr)
	{
		inst = (t_inst*)curr->content;
		if (inst->op_nbr)
			write_instruct(sfile.op_tab[inst->op_nbr - 1], inst, fd);
		curr = curr->next;
	}
}
