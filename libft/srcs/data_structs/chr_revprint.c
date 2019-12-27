#include "libft.h"

void	chr_revprint(t_chr *list)
{
	if (!list->next)
		return ;
	list = list->next;
	chr_revprint(list);
	ft_putstr(list->str);
	write(1, "\n", 1);
}
