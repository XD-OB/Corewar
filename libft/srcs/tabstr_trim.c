/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabstr_trim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <obelouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 09:14:16 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/29 01:44:59 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			tabstr_trim(char **tab)
{
	char		*tmp;
	int			i;

	i = 0;
	while (tab[i])
	{
		if (ft_strlen(tab[i]) > 0)
		{
			tmp = tab[i];
			tab[i] = ft_strtrim(tab[i]);
			free(tmp);
		}
		i++;
	}
}
