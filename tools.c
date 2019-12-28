#include "./includes/asm.h"

void			delete_comment(char **str)
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
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		delete_comment(&line);
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
