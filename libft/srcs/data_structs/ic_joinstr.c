/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ic_joinstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 16:51:20 by obelouch          #+#    #+#             */
/*   Updated: 2019/06/14 16:51:21 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ic_joinstr(t_icase **icase, int size)
{
	char		*res;
	t_icase		*tmp;
	int			i;

	if (!(res = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	res[size] = '\0';
	i = size;
	while (*icase && --i >= 0)
	{
		tmp = *icase;
		res[i] = (*icase)->n + 48;
		*icase = (*icase)->next;
		free(tmp);
	}
	return (res);
}
