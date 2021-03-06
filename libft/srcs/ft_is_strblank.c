/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_strblank.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 06:52:04 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/20 06:53:38 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_is_strblank(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isblank(str[i]))
			return (0);
		i++;
	}
	return (1);
}
