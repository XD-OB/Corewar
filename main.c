#include "./includes/asm.h"

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
	while (ft_isblank(str[i]))
		i++;
	if (str[i] == '\0')
		return (0);
	instruct = ft_strtrim(&str[i]);
	ret = is_aloneinst(op_tab, instruct);
	free(instruct);
	return (ret);
}

void	chr_addnode_sm(t_chr **list, char *str, int len)
{
	t_chr	*curr;
	t_chr	*node;

	if(!(node = (t_chr*)malloc(sizeof(t_chr))))
		return ;
	node->str = str;
	node->len = len;
	node->next = NULL;
	if (!*list)
	{
		*list = node;
		return ;
	}
	curr = *list;
	while (curr->next)
		curr = curr->next;
	curr->next = node;
}

t_cmd		*create_cmd()
{
	t_cmd	*cmd;

	if (!(cmd = (t_cmd*)malloc(sizeof(t_cmd))))
		return NULL;
	cmd->op = NULL;
	cmd->labels = NULL;
	cmd->args[0] = NULL;
	cmd->args[1] = NULL;
	cmd->args[2] = NULL;
	return (cmd);
}

t_cmd		*fill_cmd_aloneinst(t_sfile *sfile, t_chr **list_label, char *str)
{
	char	**tab_args;
	t_cmd	*cmd;
	int		i;
	int		j;

	i = 0;
	if (!(cmd = create_cmd()))
		exit_serror(sfile);
	cmd->labels = *list_label;
	while (str[i] && !ft_isblank(str[i]))
		i++;
	cmd->op = ft_strsub(str, 0, i);
	while (ft_isblank(str[i]))
		i++;
	tab_args = ft_strsplit(&str[i], SEPARATOR_CHAR);
	tabstr_trim(tab_args);
	i = 0;
	while (i < 3 && i < tabstr_len(tab_args))
	{
		cmd->args[i] = ft_strdup(tab_args[i]);
		i++;
	}
	tabstr_free(&tab_args);
	return (cmd);
}

t_cmd		*fill_cmd_instlabel(t_sfile *sfile, t_chr **list_label, char *str)
{
	char	**tab_args;
	char	*label;
	t_cmd	*cmd;
	int		i;
	int		j;

	i = 0;
	if (!(cmd = create_cmd()))
		exit_serror(sfile);
	while (ft_strchr(LABEL_CHARS, str[i]) && str[i] != LABEL_CHAR)
		i++;
	label = ft_strsub(str, 0, i);
	chr_addnode_sm(list_label, label, 0);
	cmd->labels = *list_label;
	i++;
	while (str[i] && ft_isblank(str[i]))
		i++;
	j = i;
	while (str[i] && !ft_isblank(str[i]))
		i++;
	cmd->op = ft_strsub(str, j, i - j);
	while (ft_isblank(str[i]))
		i++;
	tab_args = ft_strsplit(&str[i], SEPARATOR_CHAR);
	tabstr_trim(tab_args);
	i = 0;
	while (i < 3 && i < tabstr_len(tab_args))
	{
		cmd->args[i] = ft_strdup(tab_args[i]);
		i++;
	}
	tabstr_free(&tab_args);
	return (cmd);
}

void			get_cmds(t_sfile *sfile, t_chr *begin)
{
	t_cmd		*cmd;
	t_chr		*list_label;
	t_list		*node;
	t_chr		*curr;
	char		*label;

	curr = begin;
	list_label = NULL;
	while (curr)
	{
		if (curr->str[0] != COMMENT_CHAR && curr->str[0] != '\0')
		{
			if (is_alonelabel(curr->str))
			{
				ft_printf("|%s| label only\n", curr->str);			////////////////
				label = ft_strsub(curr->str, 0, ft_strlen(curr->str) - 1);
				chr_addnode_sm(&list_label, label, 0);
			}
			else if (is_instlabel(sfile->op_tab, curr->str))
			{
				ft_printf("|%s| instruction with label\n", curr->str);   /////////////
				cmd = fill_cmd_instlabel(sfile, &list_label, curr->str);
				node = ft_lstnew_sm(cmd, sizeof(cmd));
				ft_lstadd_last(&sfile->cmds, node);
				list_label = NULL;
			}
			else if (is_aloneinst(sfile->op_tab, curr->str))
			{
				ft_printf("|%s| instruction alone\n", curr->str);   /////////////
				cmd = fill_cmd_aloneinst(sfile, &list_label, curr->str);
				node = ft_lstnew_sm(cmd, sizeof(cmd));
				ft_lstadd_last(&sfile->cmds, node);
				list_label = NULL;
			}
			else
			{
				chr_free(&list_label);
				exit_instruct_error(sfile, curr);
			}
		}
		curr = curr->next;
	}
	if (list_label)
	{
		if (!(cmd = create_cmd()))
			exit_serror(sfile);
		cmd->labels = list_label;
		node = ft_lstnew_sm(cmd, sizeof(cmd));
		ft_lstadd_last(&sfile->cmds, node);
	}
}

t_inst		*create_inst()
{
	t_inst	*inst;
	
	if (!(inst = (t_inst*)malloc(sizeof(t_inst))))
		return NULL;
	inst->op = 0;
	inst->nbr_bytes = 0;
	inst->args[0].type = 0;
	inst->args[0].value = 0;
	inst->args[1].type = 0;
	inst->args[1].value = 0;
	inst->args[2].type = 0;
	inst->args[2].value = 0;
	return (inst);
}

t_inst		*cmd_inst(t_sfile *sfile, t_cmd *cmd)
{
	t_inst	*inst;
	int		i;

	if (!(inst = create_inst()))
		exit_serror(sfile);
	inst->op = is_op(sfile->op_tab, cmd->op);
	inst->nbr_bytes = 1;
	if (sfile->op_tab[inst->op - 1].args_type_code)
		inst->nbr_bytes++;
	i = 0;
	while (i < sfile->op_tab[inst->op - 1].args_nbr)
	{
		if (is_reg(cmd->args[i]))
		{
			inst->args[i].type = T_REG;
			inst->nbr_bytes += 1;
		}
		else if (is_dir(cmd->args[i]))
		{
			inst->args[i].type = T_DIR;
			inst->nbr_bytes += sfile->op_tab[inst->op - 1].tdir_size;
		}
		else if (is_ind(cmd->args[i]))
		{
			inst->args[i].type = T_IND;
			inst->nbr_bytes += 2;
		}
		i++;
	}
	return (inst);
}

void		fill_insts_basic(t_sfile *sfile)
{
	t_list	*curr;
	t_list	*node;
	t_inst	*inst;
	t_cmd	*cmd;

	curr = sfile->cmds;
	while (curr)
	{
		cmd = (t_cmd*)curr->content;
		if (cmd->op)
		{
			inst = cmd_inst(sfile, cmd);
			node = ft_lstnew_sm(inst, sizeof(inst));
			ft_lstadd_last(&(sfile->insts), node);
		}
		curr = curr->next;
	}
}

static t_cmd	*point_in_label()
{
}

static int		find_value(t_sfile *sfile, t_cmd *cmd, char *str)
{
	t_cmd	*point_label;
	int		n;

	if (str[0] == LABEL_CHAR)
	{
		point_label = point_in_label(cmd, &str[1]);
	}
	else
		n = ft_atoi(str);
	return (n);
}

void		inst_values(t_sfile *sfile, t_inst *inst, t_cmd *cmd)
{
	int		i;

	i = 0;
	while (i < sfile->op_tab[inst->op - 1].args_nbr)
	{
		if (inst->args[i].type == T_IND)
			inst->args[i].value = find_value(inst, cmd, &(cmd->args[i][1]));
		else
		{
		}
		i++;
	}
}

void		fill_insts_adv(t_sfile *sfile)
{
	t_list	*curr_inst;
	t_list	*curr_cmd;
	t_inst	*inst;

	curr_inst = sfile->insts;
	curr_cmd = sfile->cmds;
	while (curr_inst && curr_cmd)
	{
		inst = (t_inst*)curr->content;
		cmd = (t_cmd*)curr->content;
		inst_values(sfile, inst, cmd);
		curr_inst = curr_inst->next;
		curr_cmd = curr_cmd->next;
	}
}

void		get_insts(t_sfile *sfile)
{
	fill_insts_basic(sfile);
	fill_insts_adv(sfile);
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
		get_cmds(sfile, curr);
		get_insts(sfile);
		code = ft_strdup("Encode time!\n");
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

static void		treate_correct_asm(char *file_name, int fd, int mode)
{
	t_sfile		sfile;
	char		*cor_file;
	char		*code;
	int			cor_fd;

	if (!init_sfile(&sfile, fd))
		exit_serror(&sfile);
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
	//print_cmds(sfile.cmds); /////////////////////
	//print_op_tab(sfile.op_tab);*/
	print_insts(sfile, sfile.insts);    /////////////////////
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
