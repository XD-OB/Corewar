#include "libft.h"

static int	test_hash(char ***tab_hash, char *str, int *ind, int i)
{
	if (!(*tab_hash)[i])
	{
		(*tab_hash)[i] = ft_strdup(str);
		*ind = i;
		return (0);
	}
	if (!ft_strcmp(str, (*tab_hash)[i]))
	{
		tabstr_free(tab_hash);
		return (0);
	}
	return (1);
}

void		hash_putintab(char **tab_hash, int size, char *str, int *ind)
{
	int		i;

	i = *ind;
	while (i < size)
	{
		if (!test_hash(&tab_hash, str, ind, i))
			return ;
		i++;
	}
	i = 0;
	while (i < *ind)
	{
		if (!test_hash(&tab_hash, str, ind, i))
			return ;
		i++;
	}
}
