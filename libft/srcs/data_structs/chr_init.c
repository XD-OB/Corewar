#include "libft.h"

void		chr_init(t_chr **chr)
{
	(*chr)->str = NULL;
	(*chr)->len = 0;
	(*chr)->next = NULL;
}
