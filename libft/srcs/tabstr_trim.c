#include "libft.h"

void			tabstr_trim(char **tab)
{
	char		*tmp;
	int			i;

	i = 0;
	while (tab[i])
	{
		tmp = tab[i];
		tab[i] = ft_strtrim(tab[i]);
		free(tmp);
		i++;
	}
}
