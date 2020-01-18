/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabstr_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 09:14:44 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/18 09:15:47 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		tabstr_print(char **tab)
{
	int		len_tab;
	int		i;

	i = -1;
	len_tab = tabstr_len(tab);
	ft_printf("-------------------\n");
	while (++i < len_tab)
		ft_printf("%s\n", tab[i]);
	ft_printf("-------------------\n");
}
