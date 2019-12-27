#include "libft.h"

void	chr_print(t_chr *list)
{
	while (list)
	{
		ft_putendl(list->str);
		list = list->next;
	}
}
