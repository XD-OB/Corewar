/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 09:02:45 by obelouch          #+#    #+#             */
/*   Updated: 2019/04/18 09:13:45 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			put_spstr(char *str)
{
	int		l;

	l = 0;
	while (*str)
	{
		if (*str != '%')
		{
			ft_putchar(*str);
			l++;
		}
		str++;
	}
	return (l);
}

int			put_spstrn(char *str, size_t n)
{
	size_t	i;
	int		l;

	i = 0;
	l = 0;
	while (*str && i < n)
	{
		if (*str != '%')
		{
			ft_putchar(*str);
			l++;
			i++;
		}
		str++;
	}
	return (l);
}

char		*cut_str(char *str, int p1, int p2)
{
	char	*ret;
	int		i;

	i = p1 - 1;
	ret = ft_strnew(p2 - p1 + 1);
	while (++i <= p2)
		ret[i - p1] = str[i];
	return (ret);
}
