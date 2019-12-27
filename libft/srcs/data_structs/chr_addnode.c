#include "libft.h"

void	chr_addnode(t_chr **list, char *str, int len)
{
	t_chr	*curr;
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
	curr = *list;
	while (curr->next)
		curr = curr->next;
	curr->next = node;
}
