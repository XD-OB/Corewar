#include "asm.h"

static void		print_insts(t_list *list_insts)
{
	t_list		*curr;
	t_inst		*inst;

	curr = list_insts;
	while (curr)
	{
		ft_printf("***************************\n");
		inst = (t_inst*)curr->content;
		ft_printf("op_nbr = %d\n", inst->op_nbr);
		ft_printf("++++++++++++\nlabels:\n");
		chr_print(inst->labels);
		ft_printf("++++++++++++\n");
		ft_printf("arg1 = %s\n", inst->args[0].str);
		ft_printf("arg2 = %s\n", inst->args[1].str);
		ft_printf("arg3 = %s\n", inst->args[2].str);
		ft_printf("nbr_bytes = %d\n", inst->nbr_bytes);
		ft_printf("line = %d\n", inst->line);
		curr = curr->next;
		ft_printf("***************************\n");
	}
}

void			print_sfile(t_sfile *sfile)
{
	ft_printf("------------------------------\n");
	chr_print(sfile->sf);
	ft_printf("------------------------------\n");
	ft_printf("file_name   : %s\n", sfile->file_name);
	ft_printf("file name   : %s\n", sfile->name);
	ft_printf("file comment: %s\n", sfile->comment);
	print_insts(sfile->insts);
	ft_printf("exec size   : %d\n", sfile->exec_size);
	ft_printf("nl : %d\n", sfile->nl);
}
