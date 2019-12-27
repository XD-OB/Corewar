# include "libft.h"

void		tabstr_print(char **tab)
{
	int	len_t;
	char	*str;
	int	i;

	i = -1;
	len_t = len_tab(tab);
	ft_printf("-------------------\n");
	while (++i < len_t)
		ft_printf("%s\n", tab[i]);
	ft_printf("-------------------\n");
}
