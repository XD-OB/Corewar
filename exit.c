#include "./includes/asm.h"

void	exit_serror(t_sfile *sfile)
{
	free_sfile(sfile);
	ft_printf("Error Will Allocating Memory\n");
	exit(1);
}

void	exit_usage(char *exe)
{
	ft_printf("%{red}Usage:%{eoc} %s", exe);
	ft_printf(" [-r | --reverse] <sourcefile.s> ...\n");
	ft_printf("       -r : deassembler mode\n");
	exit(EXIT_FAILURE);
}

void	exit_error(t_sfile *sfile, t_chr *def, int type)
{
	ft_printf("line %{red}%d%{eoc}:", def->len);
	if (type == ERROR_NAME_LENGTH)
	{
		ft_printf(" Champion name is too long ");
		ft_printf("(Max length %d)\n", PROG_NAME_LENGTH);
	}
	else if (type == ERROR_COMMENT_LENGTH)
	{
		ft_printf(" Champion comment is too long ");
		ft_printf("(Max length %d)\n", COMMENT_LENGTH);
	}
	else if (type == ERROR_LESS_QUOTES)
		ft_printf(" Closing quote not found!\n");
	else if (type == ERROR_LEXICAL)
		ft_printf(" Lexical Error!\n");
	else if (type == ERROR_NC_NAME_CMT)
	{
		ft_printf(" Syntax Error! Wrong line ");
		ft_printf("or Executable Code before name and comment!\n");
	}
	else if (type == ERROR_BAD_INSTRUCT)
	{
		ft_printf(" Syntax Error! Bad Instruction! ");
		ft_printf("%{green}[%{eoc}%s%{green}]%{eoc}\n", def->str);
	}
	free_sfile(sfile);
	exit(EXIT_FAILURE);
}

void		exit_error_label(t_sfile *sfile, t_inst *inst, char *label)
{
	int		line;

	ft_printf("line %{red}%d%{eoc}:", inst->line);
	ft_printf("Invalid Label [%s] As Argument!\n", label);
	free_sfile(sfile);
	exit(EXIT_FAILURE);
}

int			check_tabargs(char **tab_arg, t_op op_ref)
{
	int		i;

	if (tabstr_len(tab_arg) != op_ref.args_nbr)
	{
		ft_printf("Wrong Number of Arguments! ");
		ft_printf("%s need %d arguments\n", op_ref.name, op_ref.args_nbr);
		return (0);
	}
	i = 0;
	while (i < op_ref.args_nbr)
	{
		if (!(type_arg(tab_arg[i]) & op_ref.args_type[i]))
		{
			ft_printf("Invalid Argument %s ", tab_arg[i]);
			ft_printf("for the operation: %s/n", op_ref.name);
			return (0);
		}
		i++;
	}
	return (1);
}

void		check_aloneinst(t_op *op_tab, char *str)
{
	char	**tab_arg;
	char	*op;
	int		op_nbr;
	int		i;

	i = 0;
	while (str[i] && !ft_isblank(str[i]))
		i++;
	if (str[i] == '\0')
	{
		ft_printf("Syntax Error!\n");
		return ;
	}
	op = ft_strsub(str, 0, i++);
	op_nbr = is_op(op_tab, op);
	if (!op_nbr)
	{
		ft_printf("Invalid Operation: %s\n", op);
		free(op);
		return ;
	}
	free(op);
	tab_arg = ft_strsplit(&str[i], SEPARATOR_CHAR);
	tabstr_trim(tab_arg);
	if (!check_tabargs(tab_arg, op_tab[op_nbr - 1]))
	{
		tabstr_free(&tab_arg);
		return ;
	}
	tabstr_free(&tab_arg);
}

int			there_islabel(t_op *op_tab, char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != LABEL_CHAR &&
			ft_strchr(LABEL_CHARS, str[i]))
		i++;
	if (str[i] != LABEL_CHAR)
		return (0);
	return (1);
}

void		check_instlabel(t_op *op_tab, char *str)
{
	char	*instruct;
	int		ret;
	int		i;

	i = 0;
	while (str[i] && str[i] != LABEL_CHAR &&
			ft_strchr(LABEL_CHARS, str[i]))
		i++;
	i++;
	while (ft_isblank(str[i]))
		i++;
	if (str[i] == '\0')
		return ;
	instruct = ft_strtrim(&str[i]);
	check_aloneinst(op_tab, instruct);
	free(instruct);
}

void	exit_instruct_error(t_sfile *sfile, t_chr *curr)
{
	ft_printf("line %{red}%d%{eoc}: ", curr->len);
	if (there_islabel(sfile->op_tab, curr->str))
		check_instlabel(sfile->op_tab, curr->str);
	else
		check_aloneinst(sfile->op_tab, curr->str);
	free_sfile(sfile);
	exit(EXIT_FAILURE);
}
