#include "libft.h"

void	chr_pushfront(t_chr **list, char *str, int len)
{
	t_chr	*node;

	if(!(node = (t_chr*)malloc(sizeof(t_chr))))
		return ;
	node->str = ft_strdup(str);
	node->len = len;
	node->next = NULL;
	if (!*list)
	{
		*list = node;
		return ;
	}
	node->next = *list;
	*list = node;
}
