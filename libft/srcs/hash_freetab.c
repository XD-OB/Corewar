#include "libft.h"

void		hash_freetab(char ***tab_hash, int size)
{
	int		i;

	i = 0;
	while (i < size)
		free((*tab_hash)[i++]);
	free(*tab_hash);
}
