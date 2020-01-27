/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabstr_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <obelouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 09:14:44 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/27 05:16:56 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		tabstr_print(char **tab)
{
	int		len_tab;
	int		i;

	i = -1;
	len_tab = tabstr_len(tab);
	ft_printf("--------- %d ------\n", len_tab);
	while (++i < len_tab)
		ft_printf("%s\n", tab[i]);
	ft_printf("-------------------\n");
}
