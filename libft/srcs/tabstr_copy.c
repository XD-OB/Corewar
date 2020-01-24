/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabstr_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 07:35:34 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/17 07:36:15 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**tabstr_copy(char **tab)
{
	char		**copy;
	int			len;
	int			i;

	i = 0;
	len = tabstr_len(tab);
	copy = (char**)malloc(sizeof(char*) * (len + 1));
	copy[len] = NULL;
	while (tab[i])
	{
		copy[i] = ft_strdup(tab[i]);
		i++;
	}
	return (copy);
}
