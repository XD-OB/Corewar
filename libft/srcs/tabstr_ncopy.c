/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabstr_ncopy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 00:01:35 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/16 07:45:39 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**tabstr_ncopy(char **tab, int start, int end)
{
	char	**new;
	int	len_tab;
	int	len;
	int		i;
	int		j;

	new = NULL;
	len_tab = tabstr_len(tab);
	if (start < 0 || start >= len_tab)
		return new;
	if (end >= len_tab || end < start)
		end = len_tab - 1;
	len = end - start + 1;
	if (!(new = (char**)malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	new[len] = NULL;
	i = start;
	j = 0;
	while (i <= len)
		new[j++] = ft_strdup(tab[i++]);
	return (new);
}
