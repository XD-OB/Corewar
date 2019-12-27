#include "libft.h"

int		hash_findid(char **tab_hash, int size, char *str)
{
	int		ind;
	int		i;

	ind = hash_str(str) % size;
	i = ind;
	while (i < size)
	{
		if (tab_hash[i] && !ft_strcmp(tab_hash[i], str))
			return (i);
		i++;
	}
	i = 0;
	while (i < ind)
	{
		if (tab_hash[i] && !ft_strcmp(tab_hash[i], str))
			return (i);
		i++;
	}
	return (-1);
}
