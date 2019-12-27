#include "libft.h"

void	tabint_reset(int *tab, int size, int n)
{
	int		i;

	i = 0;
	while (i < size)
	{
		tab[i] = n;
		i++;
	}
}
