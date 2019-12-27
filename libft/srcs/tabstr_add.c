/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabstr_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 23:47:04 by obelouch          #+#    #+#             */
/*   Updated: 2019/05/20 07:25:51 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		tabstr_add(char ***tab, char *elem)
{
	char	**new;
	int		len;
	int		i;

	len = tabstr_len(*tab);
	if (!(new = (char**)malloc(sizeof(char*) * (len + 2))))
		return ;
	new[len + 1] = NULL;
	i = -1;
	while (++i < len)
		new[i] = ft_strdup((*tab)[i]);
	new[len] = ft_strdup(elem);
	tabstr_free(tab);
	*tab = new;
}
