#include "asm.h"

static void		check_tabargs(char **tab_arg, t_op op_ref)
{
	int			i;

	if (tabstr_len(tab_arg) != op_ref.args_nbr)
	{
		ft_printf("Wrong Number of Arguments! %{green}%s%{eoc}", op_ref.name);
		ft_printf(" need %{green}%d%{eoc} argument(s)\n", op_ref.args_nbr);
		return ;
	}
	i = 0;
	while (i < op_ref.args_nbr)
	{
		if (!(type_arg(tab_arg[i]) & op_ref.args_type[i]))
		{
			ft_printf("Invalid Type of Argument %{red}%s%{eoc} ", tab_arg[i]);
			ft_printf("for the operation %{green}%s%{eoc}\n", op_ref.name);
			return ;
		}
		i++;
	}
	return ;
}

static void		check_aloneinst(t_op *op_tab, char *str)
{
	char		**tab_arg;
	char		*op;
	int			op_nbr;
	int			i;

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
	check_tabargs(tab_arg, op_tab[op_nbr - 1]);
	tabstr_free(&tab_arg);
}

static int		there_islabel(char *str)
{
	int			i;

	i = 0;
	while (str[i] && str[i] != LABEL_CHAR &&
			ft_strchr(LABEL_CHARS, str[i]))
		i++;
	if (str[i] != LABEL_CHAR)
		return (0);
	return (1);
}

static void		check_instlabel(t_op *op_tab, char *str)
{
	char		*instruct;
	int			i;

	i = 0;
	while (str[i] && str[i] != LABEL_CHAR &&
			ft_strchr(LABEL_CHARS, str[i]))
		i++;
	i++;
	while (ft_isblank(str[i]))
		i++;
	if (str[i] == '\0')
	{
		ft_printf("Cant take it as label without [%c]\n", LABEL_CHAR);
		return ;
	}
	instruct = ft_strtrim(&str[i]);
	check_aloneinst(op_tab, instruct);
	free(instruct);
}

void			exit_inst_error(t_sfile *sfile, t_chr *curr)
{
	ft_printf("line %{red}%d%{eoc}: ", curr->len);
	if (there_islabel(curr->str))
		check_instlabel(sfile->op_tab, curr->str);
	else
		check_aloneinst(sfile->op_tab, curr->str);
	free_sfile(sfile);
	exit(EXIT_FAILURE);
}
