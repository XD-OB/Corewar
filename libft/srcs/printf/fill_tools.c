/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 06:50:36 by obelouch          #+#    #+#             */
/*   Updated: 2019/04/18 06:55:28 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strcolor(char *str)
{
	char	*res;
	int		len;
	int		i;

	len = 0;
	while (str[len] && str[len] != '}' && str[len] != '%')
		len++;
	res = ft_strnew(len);
	i = -1;
	while (++i < len)
		res[i] = str[i];
	return (res);
}

int			adv_freeflag(char **str)
{
	free(*str);
	return (-1);
}
