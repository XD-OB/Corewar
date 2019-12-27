#include "libft.h"

void		mxint_free(int ***tab, int size)
{
	int		i;

	i = 0;
	while (i < size)
		free((*tab)[i++]);
	free(*tab);
}
