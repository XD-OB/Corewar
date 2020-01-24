/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccombin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 09:16:43 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/18 09:16:45 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_strccombin(char **str, char c)
{
	char	*tmp;

	if (*str)
	{
		tmp = *str;
		*str = ft_strcjoin(*str, c);
		free(tmp);
	}
	else
		*str = ft_strcnew(1, c);
}
