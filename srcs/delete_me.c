#include "asm.h"

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
	ft_printf("atc:%d\t", op.atc);
	ft_printf("tdir:%d\n", op.tdir_size);
}

void			print_op_tab(t_op *op_tab)
{
	int			i;

	i = 0;
	while (i < 16)
		print_op_case(op_tab[i++]);
}

void			print_insts(t_list *insts)
{
	t_list		*curr;
	t_chr		*tmp;
	t_inst		*inst;
	int			i;

	curr = insts;
	while (curr)
	{
		inst = curr->content;
		ft_printf("===============\n");
		ft_printf("op = [%s][%d]\n", inst->op_name, inst->op_nbr);
		tmp = inst->labels;
		ft_printf(" label: ");
		while (tmp)
		{
		   	ft_printf("	[%s]", tmp->str);
			tmp = tmp->next;
		}
		ft_printf("\n");
		i = -1;
		while (++i < 3)
		{
			ft_printf("arg%d   = [%s] ", i, inst->args[i].str);
			if (inst->args[i].type == T_REG)
				ft_printf("[T_REG] ");
			else if (inst->args[i].type == T_DIR)
				ft_printf("[T_DIR] ");
			else if (inst->args[i].type == T_IND)
				ft_printf("[T_IND] ");
			else
				ft_printf("[ --- ] ");
			ft_printf("[%d]\n", inst->args[i].value);
		}
		ft_printf("nbr bytes = [%d]\n", inst->nbr_bytes);
		ft_printf("===============\n");
		curr = curr->next;
	}
}
