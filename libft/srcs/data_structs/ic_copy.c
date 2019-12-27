#include "libft.h"

t_icase		*ic_copy(t_icase *icase)
{
	t_icase	*copy;

	copy = NULL;
	while (icase)
	{
		ic_addnode(&copy, icase->n);
		icase = icase->next;
	}
	return (copy);
}
