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

	input = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		str = ft_strtrim(line);
		chr_addnode(&input, str, ft_strlen(str));
		free(line);
		free(str);
	}
	free(line);
	if (ret == 0)
		return (input);
	if (input)
		chr_free(&input);
	return (NULL);
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
	sfile->sf = file_save_chr(fd);
}

void		ft_str_n_combin(char **str1, char *str2)
{
	char	*tmp;

	tmp = ft_strjoin(*str1, "\n");
	free(*str1);
	*str1 = tmp;
	ft_strcombin(str1, str2);
}

char		*complete_line(t_chr **curr, char *str)
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
		return (NULL);
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

char		*get_q_text_q(t_chr **curr, char *str)
{
	char	*complete;
	char	*text;
	int		start;
	int		end;
	int		i;

	i = 0;
	text = NULL;
	complete = complete_line(curr, str);
	if (complete)
	{
		find_start_end_q(complete, &start, &end);
		i = end + 2;
		while (ft_isblank(complete[i]))
			i++;
		if (complete[i] == '\0' || complete[i] == COMMENT_CHAR)
			text = ft_strsub(complete, start, end - start + 1);
		free(complete);
	}
	if (text)					//////////
		ft_putendl(text);		/////////
	return (text);
}

void		free_sfile(t_sfile *sfile)
{
	if (sfile->name)
		free(sfile->name);
	if (sfile->comment)
		free(sfile->comment);
	if (sfile->sf)
		chr_free(&(sfile->sf));
	//if (sfile->insts)
	//	free_insts(sfile->insts);
}



int		get_name_comment(t_sfile *sfile, t_chr **curr, char *str)
{
	if (str[0] == COMMENT_CHAR || str[0] == '\0')
		return (1);
	if (!ft_strncmp(str, NAME_CMD_STRING,
				ft_strlen(NAME_CMD_STRING)) && !sfile->name)
	{
		sfile->name = get_q_text_q(curr, str);
		if (!sfile->name)
			return (0);
	}
	else if (!ft_strncmp(str, COMMENT_CMD_STRING,
				ft_strlen(COMMENT_CMD_STRING)) && !sfile->comment)
	{
		sfile->comment = get_q_text_q(curr, str);
		if (!sfile->comment)
			return (0);
	}
	else
		return (0);
	return (1);
}

t_inst		*inst_create()
{
	t_inst		*instruct;

	instruct = (t_inst*)malloc(sizeof(t_inst));
	instruct->labels = NULL;
	return (instruct);
}

int			is_alonelabel(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] == LABEL_CHAR)
		return (1);
	return (0);
}

int			get_instructions(t_sfile *sfile, t_chr *node)
{
	t_inst		*instruct;
	t_chr		*list_label;
	t_dlist		*cell;
	t_chr		*curr;
	char		*label;

	curr = node;
	list_label = NULL;
	instruct = NULL;
	while (curr)
	{
		if (is_alonelabel(curr->str))
		{
			label = ft_strsub(curr->str, 0, ft_strlen(curr->str) - 1);
			chr_addnode(&list_label, label, ft_strlen(label));
			free(label);
		}
		/*else if (is_instlabel(curr->str))
		{
			label = label_instlabel(curr->str);
			chr_addnode(&list_label, label, ft_strlen(label));
			free(label);
			instlabel_aloneinst(&(curr->str));
			instruct = fill_inst(list_label, curr->str);
			cell = dt_createnode(instruct);
			dt_addnode(&(sfile->insts), cell);
			list_label = NULL;
			cell = NULL;
		}*/
		//else if (is_aloneinst)
		//{
		//}
		//else
		//	return (0);
		curr = curr->next;
	}
	//chr_free(&list_label);
	return (1);
}

void		print_syntax_error(t_chr *sf, t_chr *curr)
{
	int		l;

	if (!curr)
	{
		ft_printf("%{red}Syntax Error!%{eoc}\n");
		return ;
	}
	l = 1;
	while (sf)
	{
		if (!ft_strcmp(sf->str, curr->str))
			break ;
		sf = sf->next;
		l++;
	}
	ft_printf("%{red}Syntax Error!%{eoc} ");
	ft_printf("in line %{green}%d%{eoc}\n", l);
}

char		*encode_asm(t_sfile *sfile)
{
	t_chr		*curr;
	char		*code;

	code = NULL;
	curr = sfile->sf;
	while (curr)
	{
		if (!get_name_comment(sfile, &curr, curr->str))
			break ;
		curr = curr->next;
	}
	if (sfile->name && sfile->comment)
	{
		if (get_instructions(sfile, curr))
			code = ft_strdup("Encode time!\n");
		//else
		//	print_inst_error();
	}
	else
		print_syntax_error(sfile->sf, curr);
	return (code);
}

char		*decode_asm(t_sfile *sfile)
{
	char	*code;

	code = ft_strdup("Decode time!\n");
	return (code);
}

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
	ft_putendl("------------------");
	chr_print(sfile.sf);
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
