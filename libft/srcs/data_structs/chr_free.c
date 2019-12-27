#include "libft.h"

void		chr_free(t_chr **chr)
{
	t_chr	*curr;
	t_chr	*next;

	curr = *chr;
	while (curr)
	{
		next = curr->next;
		if (curr->str)
			free(curr->str);
		free(curr);
		curr = next;
	}
	*chr = NULL;
}
