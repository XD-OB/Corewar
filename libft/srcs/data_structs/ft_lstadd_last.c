#include "libft.h"

void    ft_lstadd_last(t_list **lst, t_list* node)
{
        t_list  *current;

        if (!node)
                return ;
        if (*lst)
        {
                current = *lst;
                while (current->next)
                        current = current->next;
                current->next = node;
        }
        else
                *lst = node;
}
