#include "libft.h"

t_chr			*gnl_save_chr(int fd)
{
	t_chr		*input;
	char		*line;
	int			ret;

	input = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		chr_addnode(&input, line, ft_strlen(line));
		free(line);
	}
	free(line);
	if (ret == 0)
		return (input);
	if (input)
		chr_free(&input);
	return (NULL);
}
