#include "libft.h"

t_chr			*gnl_nsave_chr(int fd, int nbr_lines)
{
	t_chr		*input;
	char		*line;
	int			ret;
	int			i;

	i = 0;
	ret = 0;
	input = NULL;
	while ((nbr_lines == -1 || i < nbr_lines) &&
			((ret = get_next_line(fd, &line)) > 0))
	{
		chr_addnode(&input, line, ft_strlen(line));
		free(line);
		i++;
	}
	free(line);
	if (ret == 0 || i == nbr_lines)
		return (input);
	if (input)
		chr_free(&input);
	return (NULL);	
}
