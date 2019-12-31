#include "asm.h"

static int		count_dquotes(t_sfile *sfile, t_chr *curr, char *str)
{
	int			q;
	int			i;

	i = 0;
	if (str[0] == '\0')
		exit_qerror(sfile, curr, ERROR_NO_STR);
	if (str[0] != '"')
		exit_qerror(sfile, curr, ERROR_CHAR_QUOTES);
	q = 1;
	while (str[i])
	{
		if (str[i] == '"')
			q++;
		i++;
	}
	return (q);
}

static char		*complete_line(t_sfile *sfile, t_chr **curr, char *str)
{
	char		*complete;
	int			q;

	q = count_dquotes(sfile, *curr, str);
	complete = ft_strdup(str);
	if (q < 2)
	{
		if (q != 0)
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
			free(complete);
			exit_qerror(sfile, *curr, ERROR_LESS_QUOTES);
		}
		free(complete);
		exit_qerror(sfile, *curr, ERROR_NO_QUOTES);
	}
	return (complete);
}

static void		find_start_end_q(char *str, int *start, int *end)
{
	int			i;
	int			j;

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

static char		*get_q_text_q(t_sfile *sfile, t_chr **curr, char *str)
{
	char		*complete;
	char		*text;
	int			start;
	int			end;
	int			i;

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
		exit_ass_error(sfile, *curr, ERROR_LEXICAL);
	return (text);
}

int				get_name_cmt(t_sfile *sfile, t_chr **curr, char *str)
{
	char		*s;

	if (str[0] == COMMENT_CHAR || str[0] == '\0')
		return (0);
	if (!ft_strncmp(str, NAME_CMD_STRING,
				ft_strlen(NAME_CMD_STRING)) && !sfile->name)
	{
		s = ft_strtrim(&str[ft_strlen(NAME_CMD_STRING)]);
		sfile->name = get_q_text_q(sfile, curr, s);
		free(s);
		if (ft_strlen(sfile->name) > PROG_NAME_LENGTH)
			exit_ass_error(sfile, *curr, ERROR_NAME_LENGTH);
	}
	else if (!ft_strncmp(str, COMMENT_CMD_STRING,
				ft_strlen(COMMENT_CMD_STRING)) && !sfile->comment)
	{
		s = ft_strtrim(&str[ft_strlen(COMMENT_CMD_STRING)]);
		sfile->comment = get_q_text_q(sfile, curr, s);
		free(s);
		if (ft_strlen(sfile->comment) > COMMENT_LENGTH)
			exit_ass_error(sfile, *curr, ERROR_COMMENT_LENGTH);
	}
	else
		return (1);
	return (0);
}
