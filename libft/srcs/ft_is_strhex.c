/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_strhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 05:21:17 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/21 05:44:41 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_is_strhex(char *str)
{
	int		i;

	if (str[0] != '0')
		return (0);
	if (str[1] != 'x' && str[1] != 'X')
		return (0);
	i = 1;
	while (str[++i])
		if (!ft_isxdigit(str[i]))
			return (0);
	return (1);
}
