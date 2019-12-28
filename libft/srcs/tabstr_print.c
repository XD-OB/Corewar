# include "libft.h"

void		tabstr_print(char **tab)
{
	int	len_tab;
	int	i;

	i = -1;
	len_tab = tabstr_len(tab);
	ft_printf("-------------------\n");
	while (++i < len_tab)
		ft_printf("%s\n", tab[i]);
	ft_printf("-------------------\n");
}
