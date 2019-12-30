#include "asm.h"

static void		write_inst_lables(t_inst *inst, int bytes)
{
	t_chr		*label;

	if (inst->labels)
	{
		ft_printf("\n");
		label = inst->labels;
		while (label)
		{
			ft_printf("%-5d", bytes);
			ft_printf("      :   %s:\n", label->str);
			if (label->next)
				ft_printf("\n");
			label = label->next;
		}
	}
}

static void		write_inst_oparg(t_op op_infos, t_inst *inst, int bytes)
{
	char		*str;
	int			i;

	ft_printf("%-5d", bytes);
	ft_printf("(%3d) :      ", inst->nbr_bytes);
	ft_printf("%-5s", inst->op_name);
	i = 0;
	while (i < op_infos.args_nbr)
	{
		if (inst->args[i].type == T_REG)
			str = ft_strjoin("r", inst->args[i].str);
		if (inst->args[i].type == T_DIR)
			str = ft_strjoin("%", inst->args[i].str);
		ft_printf("%21s", str);
		free(str);
		i++;
	}
	ft_printf("\n");
}

static int			int_atc(t_inst *inst)
{
	unsigned char	arg[3];
	int				res;
	int				i;

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
	return (res);
}

static void		write_inst_basinfos(t_op op_infos, t_inst *inst)
{
	int			i;

	ft_printf("                  ");
	ft_printf("%-5d", inst->op_nbr);
	if (op_infos.atc)
		ft_printf("%5d", int_atc(inst));
	else
		ft_printf("     ");
	i = 0;
	ft_printf("%16d", inst->args[i].value);
	while (++i < op_infos.args_nbr)
		ft_printf("%21d", inst->args[i].value);
	ft_printf("\n");
}

static void		write_4_bit(int n)
{
	unsigned char	c[4];
	char			*str;
	int				i;

	if (n < 0)
	{
		n = ~(n * -1);
		n += 1;
	}
	c[0] = (n >> 24) & 0xff;
	c[1] = (n >> 16) & 0xff;
	c[2] = (n >> 8) & 0xff;
	c[3] = n & 0xff;
	i = 0;
	while (i < 4)
	{
		str = ft_itoa_base(c[i], 16);
		ft_printf("|%02s", str);
		free(str);
		i++;
	}
}

static void		write_2_bit(int n)
{
	unsigned char	c[2];
	char			*str;

	if (n < 0)
	{
		n = ~(n * -1);
		n += 1;
	}
	c[0] = (n >> 8) & 0xff;
	c[1] = n & 0xff;
	ft_printf("      ");
	str = ft_itoa_base(c[0], 16);
	ft_printf("|%02s", str);
	free(str);
	str = ft_itoa_base(c[1], 16);
	ft_printf("|%02s", str);
	free(str);
}

static void		write_advargs(t_op op_infos, t_inst *inst)
{
	char		*str;
	int			i;

	i = 0;
	ft_printf(" ");
	while (i < op_infos.args_nbr)
	{
		if (i > 0)
			ft_printf("         ");
		if (inst->args[i].type == T_REG)
		{
			str = ft_itoa_base(inst->args[i].value, 16);
			ft_printf("         ");
			ft_printf("|%02s", str);
			free(str);
		}
		else if (inst->args[i].type == T_DIR
				&& op_infos.tdir_size == 4)
			write_4_bit(inst->args[i].value);
		else
			write_2_bit(inst->args[i].value);
		i++;
	}
}

static void		write_inst_advinfos(t_op op_infos, t_inst *inst)
{
	char		*str;

	ft_printf("                  ");
	str = ft_itoa_base(inst->op_nbr, 16);
	ft_printf("%02s   ", str);
	free(str);
	if (op_infos.atc)
	{
		str = ft_itoa_base(int_atc(inst), 2);
		ft_printf("%08s", str);
		free(str);
	}
	else
		ft_printf("        ");
	write_advargs(op_infos, inst);
	ft_printf("\n");
}

void			write_stdout_inst(t_op op_infos, t_inst *inst, int bytes)
{
	write_inst_lables(inst, bytes);
	if (inst->op_nbr)
	{
		write_inst_oparg(op_infos, inst, bytes);
		write_inst_basinfos(op_infos, inst);
		write_inst_advinfos(op_infos, inst);
	}
}

void			write_stdout(t_sfile sfile)
{
	t_list		*curr;
	t_inst		*inst;
	int			bytes;

	bytes = 0;
	ft_putendl("       Annotated program:");
	ft_printf("%{green}==========================================");
	ft_printf("===========================================%{eoc}\n");
	ft_printf("Name    : %{CYAN}%s%{eoc}\n", sfile.name);
	ft_printf("Comment : %{CYAN}%s%{eoc}\n", sfile.comment);
	ft_printf("Program size : %{CYAN}%d%{eoc}\n\n", sfile.exec_size);
	curr = sfile.insts;
	while (curr)
	{
		inst = (t_inst*)curr->content;
		write_stdout_inst(sfile.op_tab[inst->op_nbr - 1], inst, bytes);
		bytes += inst->nbr_bytes;
		curr = curr->next;
	}
	ft_printf("%{green}==========================================");
	ft_printf("===========================================%{eoc}\n");
}

void			encode_asm(t_asm *asmbl, char *file_name)
{
	t_sfile		sfile;
	t_chr		*curr;

	if (!init_sfile(&sfile, asmbl->fd))
		exit_serror(&sfile, ERROR_ALLOC);
	curr = sfile.sf;
	while (curr)
	{
		if (get_name_cmt(&sfile, &curr, curr->str))
			break ;
		curr = curr->next;
	}
	if (sfile.name && sfile.comment)
		get_instructs(&sfile, curr);
	else
		exit_error(&sfile, curr, ERROR_NC_NAME_CMT);
	if (asmbl->a)
		write_stdout(sfile);
	else
		write_cor(sfile, file_name);
	free_sfile(&sfile);
}

void	exit_ferror(char *file, int type)
{
	if (type == ERROR_FILE_NF)
		ft_printf("%{red}%s%{eoc}: File not found!\n", file);
	else if (type == ERROR_FILE_BE)
		ft_printf("%{red}%s%{eoc}: File with Bad extension!\n", file);
	exit(EXIT_FAILURE);
}

void	treate_file(char *file, t_asm *asmbl)
{
	char	*file_name;

	asmbl->fd = open(file, O_RDONLY);
	if (asmbl->fd < 0)
		exit_ferror(file, ERROR_FILE_NF);
	if (asmbl->r)
	{
		if (ft_strcmp(&file[ft_strlen(file) - 4], ".cor"))
			exit_ferror(file, ERROR_FILE_BE);
		file_name = ft_strndup(file, ft_strlen(file) - 4);
		//decode_asm(asmbl, file_name);
		free(file_name);
	}
	else
	{
		if (ft_strcmp(&file[ft_strlen(file) - 2], ".s"))
			exit_ferror(file, ERROR_FILE_BE);
		file_name = ft_strndup(file, ft_strlen(file) - 2);
		encode_asm(asmbl, file_name);
		free(file_name);
	}
	close(asmbl->fd);
}

void	init_asmbl(t_asm *asmbl)
{
	asmbl->fd = -1;
	asmbl->r = 0;
	asmbl->a = 0;
}

int		main(int ac, char **av)
{
	t_asm	asmbl;
	int		i;

	if (ac == 1)
		exit_usage(av[0]);
	init_asmbl(&asmbl);
	i = save_options(&asmbl, ac, av);
	while (i < ac)
		treate_file(av[i++], &asmbl);			//!!!!!!
	return (EXIT_SUCCESS);
}
