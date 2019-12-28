#include "./includes/asm.h"

static void		print_op_case(t_op op)
{
	ft_printf("%d  ", op.nbr);
	ft_printf("%s\t", op.name);
	ft_printf("%d  ", op.args_nbr);
	if (op.args_type[0] & T_REG)
		ft_printf("T_REG|");
	if (op.args_type[0] & T_DIR)
		ft_printf("T_DIR|");
	if (op.args_type[0] & T_IND)
		ft_printf("T_IND|");
	ft_printf("\t");
	if (op.args_type[1] & T_REG)
		ft_printf("T_REG|");
	if (op.args_type[1] & T_DIR)
		ft_printf("T_DIR|");
	if (op.args_type[1] & T_IND)
		ft_printf("T_IND|");
	ft_printf("\t");
	if (op.args_type[2] & T_REG)
		ft_printf("T_REG|");
	if (op.args_type[2] & T_DIR)
		ft_printf("T_DIR|");
	if (op.args_type[2] & T_IND)
		ft_printf("T_IND|");
	ft_printf("\t");
	ft_printf("atc:%d\t", op.args_type_code);
	ft_printf("tdir:%d\n", op.tdir_size);
}

void			print_op_tab(t_op *op_tab)
{
	int			i;

	i = 0;
	while (i < 16)
		print_op_case(op_tab[i++]);
}

void			print_cmds(t_list *cmds)
{
	t_list		*curr;
	t_chr		*tmp;
	t_cmd		*cmd;

	curr = cmds;
	while (curr)
	{
		cmd = curr->content;
		ft_printf("===============\n");
		ft_printf("op     = [%s]\n", cmd->op);
		tmp = cmd->labels;
		while (tmp)
		{
			ft_printf(" label = [%s]\n", tmp->str);
			tmp = tmp->next;
		}
		ft_printf("arg1   = [%s]\n", cmd->args[0]);
		ft_printf("arg2   = [%s]\n", cmd->args[1]);
		ft_printf("arg3   = [%s]\n", cmd->args[2]);
		ft_printf("===============\n");
		curr = curr->next;
	}
}

void			print_insts(t_sfile sfile, t_list *insts)
{
	t_list		*curr;
	t_inst		*inst;
	int			i;

	curr = insts;
	while (curr)
	{
		inst = (t_inst*)(curr->content);
		ft_printf("===============\n");
		ft_printf("op        = [%d][%s]\n", inst->op, sfile.op_tab[inst->op - 1].name);
		ft_printf("nbr bytes = [%d]\n", inst->nbr_bytes);
		i = -1;
		while (++i < 3)
		{
			if (inst->args[i].type == T_REG)
				ft_printf("arg%d type = [T_REG]\n", i);
			if (inst->args[i].type == T_DIR)
				ft_printf("arg%d type = [T_DIR]\n", i);
			if (inst->args[i].type == T_IND)
				ft_printf("arg%d type = [T_IND]\n", i);
			else
				ft_printf("     - - - - -     \n", i);
			//ft_printf("arg%d value = [%d]\n", i, inst->args[i].value);
		}
		ft_printf("===============\n");
		curr = curr->next;
	}
}
