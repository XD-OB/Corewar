#include "libft.h"

void	ic_print(t_icase *icase)
{
	while (icase)
	{
		ft_printf("[%d] - ", icase->n);
		icase = icase->next;
	}
	ft_putchar('\n');
}
