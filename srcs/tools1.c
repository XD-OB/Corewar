#include "asm.h"

static void		delete_comment(char **str)
{
	char		*new;
	int			i;

	if ((*str)[0] == COMMENT_CHAR)
		return ;
	i = 0;
	while ((*str)[i] && (*str)[i] != COMMENT_CHAR)
		i++;
	if (!(*str)[i])
		return ;
	new = ft_strsub(*str, 0, i);
	free(*str);
	*str = new;
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
	line = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		delete_comment(&line);
		str = ft_strtrim(line);
		chr_addnode(&input, str, i);
		free(line);
		free(str);
		i++;
	}
	if (line)
		free(line);
	if (ret == 0)
		return (input);
	if (input)
		chr_free(&input);
	return (NULL);
}

t_inst			*create_inst(void)
{
	t_inst		*inst;
	int			i;

	if (!(inst = (t_inst*)malloc(sizeof(t_inst))))
		return (NULL);
	inst->labels = NULL;
	inst->op_nbr = 0;
	inst->nbr_bytes = 0;
	i = 0;
	while (i < 3)
	{
		inst->args[i].str = NULL;
		inst->args[i].type = 0;
		inst->args[i].value = 0;
		i++;
	}
	return (inst);
}
