#include "libft.h"

void	ic_lstdel(t_list **alst)
{
	t_list	*current_node;

	while (*alst != NULL)
	{
		current_node = *alst;
		ic_free((t_icase**)(&(*alst)->content));
		*alst = (*alst)->next;
		free(current_node);
	}
}
