#include "./includes/asm.h"

void	exit_usage(char *exe)
{
	ft_printf("%{red}Usage:%{eoc} %s", exe);
	ft_printf(" [-r | --reverse] <sourcefile.s> ...\n");
	ft_printf("       -r : deassembler mode\n");
	exit(EXIT_FAILURE);
}

t_chr			*file_save_chr(int fd)
{
	t_chr		*input;
	char		*line;
	char		*str;
	int			ret;
	int			i;

	i = 1;
	input = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		str = ft_strtrim(line);
		chr_addnode(&input, str, i);
		free(line);
		free(str);
		i++;
	}
	free(line);
	if (ret == 0)
		return (input);
	if (input)
		chr_free(&input);
	return (NULL);
}

static void		free_op_tab(t_op **op_tab)
{
	int			i;

	i = 0;
	while (i < 16)
		free((*op_tab)[i++].name);
	free(*op_tab);
}

void			free_sfile(t_sfile *sfile)
{
	if (sfile->name)
		free(sfile->name);
	if (sfile->comment)
		free(sfile->comment);
	if (sfile->sf)
		chr_free(&(sfile->sf));
	free_op_tab(&(sfile->op_tab));
	//if (sfile->insts)
	//	free_insts(sfile->insts);
}

int		is_allblank(char *str)
{
	int		i;

	i = 0;
	while(str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

void		init_sfile(t_sfile *sfile, int fd)
{
	sfile->name = NULL;
	sfile->comment = NULL;
	sfile->insts = NULL;
	sfile->cmds = NULL;
	sfile->sf = file_save_chr(fd);
	sfile->op_tab = (t_op*)malloc(sizeof(t_op) * 16);
	fill_op_tab(sfile->op_tab);
}

void		ft_str_n_combin(char **str1, char *str2)
{
	char	*tmp;

	tmp = ft_strjoin(*str1, "\n");
	free(*str1);
	*str1 = tmp;
	ft_strcombin(str1, str2);
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
		ft_printf(" Syntax Error Wrong line or Executable Code before name and comment!\n");
	else if (type == ERROR_BAD_INSTRUCT)
		ft_printf(" Syntax Error! Bad Instruction! %s\n", def->str);
	free_sfile(sfile);
	exit(1);
}

char		*complete_line(t_sfile *sfile, t_chr **curr, char *str)
{
	char	*complete;
	int		q;
	int		i;

	q = 0;
	i = -1;
	complete = ft_strdup(str);
	while (str[++i])
		if (str[i] == '"')
			q++;
	if (q < 2)
	{
		if (q > 0)
		{
			*curr = (*curr)->next;
			while (*curr)
			{
				ft_strcombin(&complete, "\n");
				ft_strcombin(&complete, (*curr)->str);
				if (ft_strchr((*curr)->str, '"'))
					return (complete);
				(*curr) = (*curr)->next;
			}
		}
		free(complete);
		exit_error(sfile, *curr, ERROR_LESS_QUOTES);
	}
	return (complete);
}

void		find_start_end_q(char *str, int *start, int *end)
{
	int		i;
	int		j;

	i = 0;
	while (str[i] != '"')
		i++;
	i++;
	j = i;
	while (str[j] != '"')
		j++;
	j--;
	*start = i;
	*end = j;
}

char		*get_q_text_q(t_sfile *sfile, t_chr **curr, char *str)
{
	char	*complete;
	char	*text;
	int		start;
	int		end;
	int		i;

	i = 0;
	text = NULL;
	complete = complete_line(sfile, curr, str);
	find_start_end_q(complete, &start, &end);
	i = end + 2;
	while (ft_isblank(complete[i]))
		i++;
	if (complete[i] == '\0' || complete[i] == COMMENT_CHAR)
		text = ft_strsub(complete, start, end - start + 1);
	free(complete);
	if (!text)
		exit_error(sfile, *curr, ERROR_LEXICAL);
	ft_putendl(text);		/////////
	return (text);
}

int		get_name_comment(t_sfile *sfile, t_chr **curr, char *str)
{
	if (str[0] == COMMENT_CHAR || str[0] == '\0')
		return (0);
	if (!ft_strncmp(str, NAME_CMD_STRING,
				ft_strlen(NAME_CMD_STRING)) && !sfile->name)
	{
		sfile->name = get_q_text_q(sfile, curr, str);
		if (ft_strlen(sfile->name) > PROG_NAME_LENGTH)
			exit_error(sfile, *curr, ERROR_NAME_LENGTH);
	}
	else if (!ft_strncmp(str, COMMENT_CMD_STRING,
				ft_strlen(COMMENT_CMD_STRING)) && !sfile->comment)
	{
		sfile->comment = get_q_text_q(sfile, curr, str);
		if (ft_strlen(sfile->comment) > COMMENT_LENGTH)
			exit_error(sfile, *curr, ERROR_COMMENT_LENGTH);
	}
	else
		return (1);
	return (0);
}

int			is_alonelabel(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != LABEL_CHAR)
	{
		if (!ft_strchr(LABEL_CHARS, str[i]))
			return (0);
		i++;
	}
	if (str[i] == LABEL_CHAR && !str[i + 1])
		return (1);
	return (0);
}

int			is_op(t_op *op_tab, char *str)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		if (!ft_strcmp(str, op_tab[i].name))
			return (i + 1);
		i++;
	}
	return (0);
}

void		tabstr_trim(char **tab)
{
	char	*tmp;
	int		i;

	i = 0;
	while (tab[i])
	{
		tmp = tab[i];
		tab[i] = ft_strtrim(tab[i]);
		free(tmp);
		i++;
	}
}

static int	is_reg(char *str)
{
	int		n;
	int		i;

	if (str[0] != 'r')
		return (0);
	if (ft_strlen(str) == 2)
	{
		if (!ft_isdigit(str[1]))
			return (0);
		n = str[1] - 48;
		if (n == 0 || n > REG_NUMBER)
			return (0);
		return (1);
	}
	else if (ft_strlen(str) == 3)
	{
		if (!ft_isdigit(str[i]) || !ft_isdigit(str[i]))
			return (0);
		n = ft_atoi(&str[1]);
		if (n == 0 || n > REG_NUMBER)
			return (0);
		return (1);
	}
	return (0);
}

static int	is_dir(char *str)
{
	int		i;

	if (str[0] != DIRECT_CHAR)
		return (0);
	if (str[1] == LABEL_CHAR)
	{
		i = 1;
		while (str[++i])
			if (!ft_strchr(LABEL_CHARS, str[i]))
				return (0);
		return (1);
	}
	i = 0;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}

static int	is_ind(char *str)
{
	int		i;

	if (str[0] == LABEL_CHAR)
	{
		i = 0;
		while (str[++i])
			if (!ft_strchr(LABEL_CHARS, str[i]))
				return (0);
		return (1);
	}
	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}

int			type_arg(char *str)
{
	if (is_reg(str))
		return (T_REG);
	else if (is_dir(str))
		return (T_DIR);
	else if (is_ind(str))
		return (T_IND);
	else
		return (0);
}

int			corr_tabargs(char **tab_arg, t_op op_ref)
{
	int		i;

	if (tabstr_len(tab_arg) != op_ref.args_nbr)
		return (0);
	i = 0;
	while (i < op_ref.args_nbr)
	{
		if (!(type_arg(tab_arg[i]) & op_ref.args_type[i]))
			return (0);
		i++;
	}
	return (1);
}

int			is_aloneinst(t_op *op_tab, char *str)
{
	char	**tab_arg;
	char	*op;
	int		op_nbr;
	int		i;

	i = 0;
	while (str[i] && !ft_isblank(str[i]))
		i++;
	if (str[i] == '\0')
		return (0);
	op = ft_strsub(str, 0, i++);
	op_nbr = is_op(op_tab, op);
	free(op);
	if (str[i] == '\0' || !op_nbr)
		return (0);
	tab_arg = ft_strsplit(&str[i], SEPARATOR_CHAR);
	tabstr_trim(tab_arg);
	tabstr_print(tab_arg);			////////////
	if (!corr_tabargs(tab_arg, op_tab[op_nbr - 1]))
	{
		tabstr_free(&tab_arg);
		return(0);
	}
	tabstr_free(&tab_arg);
	return (1);
}

int			is_instlabel(t_op *op_tab, char *str)
{
	char	*instruct;
	int		ret;
	int		i;

	i = 0;
	while (str[i] && str[i] != LABEL_CHAR &&
			ft_strchr(LABEL_CHARS, str[i]))
		i++;
	if (str[i] != LABEL_CHAR)
		return (0);
	i++;
	while (str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (0);
	instruct = ft_strtrim(&str[i]);
	ret = is_aloneinst(op_tab, instruct);
	free(instruct);
	return (ret);
}

void			get_instructions(t_sfile *sfile, t_chr *node)
{
	t_inst		*instruct;
	t_chr		*list_label;
	t_list		*cell;
	t_chr		*curr;
	char		*label;

	curr = node;
	list_label = NULL;
	instruct = NULL;
	while (curr)
	{
		if (is_alonelabel(curr->str))
		{
			ft_printf("|%s| label only\n", curr->str);			////////////////
			label = ft_strsub(curr->str, 0, ft_strlen(curr->str) - 1);
			chr_addnode(&list_label, label, ft_strlen(label));
			free(label);
		}
		else if (is_instlabel(sfile->op_tab, curr->str))
		{
			ft_printf("|%s| instruction with label\n", curr->str);   /////////////
			/*label = label_instlabel(curr->str);
			chr_addnode(&list_label, label, ft_strlen(label));
			free(label);
			instlabel_aloneinst(&(curr->str));
			instruct = fill_inst(list_label, curr->str);
			cell = dt_createnode(instruct);
			dt_addnode(&(sfile->insts), cell);
			list_label = NULL;
			cell = NULL;*/
		}
		else if (is_aloneinst(sfile->op_tab, curr->str))
		{
			ft_printf("|%s| instruction alone\n", curr->str);   /////////////
		}
		else
		{
			chr_free(&list_label);
			exit_error(sfile, curr, BAD_INSTRUCT);
		}
		curr = curr->next;
	}
	chr_free(&list_label);
}

void		print_inst_error()
{
	ft_printf("Error in a instruction!");
}

char		*encode_asm(t_sfile *sfile)
{
	t_chr		*curr;
	char		*code;
	int			error;

	code = NULL;
	curr = sfile->sf;
	while (curr)
	{
		if (get_name_comment(sfile, &curr, curr->str))
			break ;
		curr = curr->next;
	}
	if (sfile->name && sfile->comment)
	{
		if (get_instructions(sfile, curr))
			code = ft_strdup("Encode time!\n");
		else
			print_inst_error();
	}
	else
		exit_error(sfile, curr, ERROR_NC_NAME_CMT);
	return (code);
}

char		*decode_asm(t_sfile *sfile)
{
	char	*code;

	code = ft_strdup("Decode time!\n");
	return (code);
}
/*
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
*/
static void		treate_correct_asm(char *file_name, int fd, int mode)
{
	t_sfile		sfile;
	char		*cor_file;
	char		*code;
	int			cor_fd;

	init_sfile(&sfile, fd);
	code = (mode) ? encode_asm(&sfile) : decode_asm(&sfile);
	if (code)
	{
		cor_file = ft_strjoin(file_name, ".cor");
		cor_fd = open(cor_file, O_CREAT | O_WRONLY);
		ft_putstr_fd(code, cor_fd);
		free(cor_file);
		close(cor_fd);
		free(code);
	}
	ft_putendl("------------------");    ////////////////
	chr_print(sfile.sf);
	ft_putendl("------------------");
	//print_op_tab(sfile.op_tab);*/
	free_sfile(&sfile);
}

void	treate_asm(char *file, int mode)
{
	char	*file_name;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_putendl("File not found!");
	else
	{
		if (ft_strcmp(&file[ft_strlen(file) - 2], ".s"))
			ft_putendl("File with bad extension!");
		else
		{
			file_name = ft_strndup(file, ft_strlen(file) - 2);
			treate_correct_asm(file_name, fd, mode);
			free(file_name);
		}
		close(fd);
	}
}

int		main(int ac, char **av)
{
	int		i;
	int		mode;

	if (ac == 1)
		exit_usage(av[0]);
	i = 1;
	mode = 1;
	if (!ft_strcmp(av[1], "-r") ||
			!ft_strcmp(av[1], "--reverse"))
	{
		mode = 0;
		i++;
	}
	if (i == ac)
		exit_usage(av[0]);
	while (i < ac)
		treate_asm(av[i++], mode);
	return (EXIT_SUCCESS);
}
