/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:40:38 by obelouch          #+#    #+#             */
/*   Updated: 2019/04/17 18:01:26 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		add_minus(char **str)
{
	char	*new;
	int		len;

	len = ft_strlen(*str) + 1;
	new = (char*)malloc(sizeof(char) * (len + 1));
	new[len] = '\0';
	ft_strcpy(new, *str);
	new[len - 1] = '-';
	free(*str);
	*str = new;
}

void		flag_star(t_format *format, va_list ap)
{
	int		n;

	if (ft_strchr(format->flag, '*'))
	{
		n = va_arg(ap, int);
		if (n < 0)
		{
			n *= -1;
			if (!ft_strchr(format->flag, '-'))
				add_minus(&(format->flag));
		}
		format->width = n;
	}
	if (format->precis == -2)
		format->precis = va_arg(ap, int);
}

int			flag_dollar(t_lst *lst)
{
	int		i;

	if (ft_strchr(lst->format->flag, '$'))
	{
		i = 0;
		while (++i < lst->format->argn)
			va_arg(*(lst->arglist), void*);
		return (1);
	}
	return (0);
}
