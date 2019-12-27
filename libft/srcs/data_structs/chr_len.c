#include "libft.h"

int		chr_len(t_chr *chr)
{
	int		len;

	len = 0;
	while (chr)
	{
		len++;
		chr = chr->next;
	}
	return (len);
}
