#include "libft.h"

int			ic_size(t_icase *icase)
{
	int		len;

	len = 0;
	while (icase)
	{
		icase = icase->next;
		len++;
	}
	return (len);
}
