#include "libft.h"

int		ic_ncmp(t_icase *list1, t_icase *list2, size_t n)
{
	t_icase	*ptr1;
	t_icase	*ptr2;
	size_t	i;

	i = 0;
	ptr1 = list1;
	ptr2 = list2;
	while (ptr1 && ptr2 && i < n)
	{
		if (ptr1->n != ptr2->n)
			return (ptr1->n - ptr2->n);
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
		i++;
	}
	if (i == n)
		return (0);
	if (ptr1)
		return (ptr1->n);
	return (0 - ptr2->n);
}
