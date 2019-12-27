#include "libft.h"

void	ic_free(t_icase **icase)
{
	t_icase	*tmp;
	t_icase *curr;

	tmp = *icase;
	while (tmp)
	{
		curr = tmp;
		tmp = tmp->next;
		free(curr);
	}
	icase = NULL;
}
