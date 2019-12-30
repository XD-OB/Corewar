#include "asm.h"

static int		check_tabargs(char **tab_arg, t_op op_ref)
{
	int			i;

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
	if (!check_tabargs(tab_arg, op_tab[op_nbr - 1]))
	{
		tabstr_free(&tab_arg);
		return ;
	}
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
		return ;
	instruct = ft_strtrim(&str[i]);
	check_aloneinst(op_tab, instruct);
	free(instruct);
}

void			exit_instruct_error(t_sfile *sfile, t_chr *curr)
{
	ft_printf("line %{red}%d%{eoc}: ", curr->len);
	if (there_islabel(curr->str))
		check_instlabel(sfile->op_tab, curr->str);
	else
		check_aloneinst(sfile->op_tab, curr->str);
	free_sfile(sfile);
	exit(EXIT_FAILURE);
}
