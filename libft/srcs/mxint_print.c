#include "libft.h"

void	mxint_print(int **matrix, int size_y, int size_x)
{
	int	i;
	int	j;

	i = 0;
	while (i < size_y)
	{
		j = 0;
		while (j < size_x - 1)
			ft_printf("%d\t", matrix[i][j++]);
		ft_printf("%d\n", matrix[i++][j]);
	}
}
