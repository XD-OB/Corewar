/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 06:34:32 by obelouch          #+#    #+#             */
/*   Updated: 2019/04/17 17:16:44 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long int		cast_xxoub(va_list ap, t_format *fmt)
{
	unsigned long long int	n;

	if (fmt->convers == 'U')
		n = (unsigned long int)va_arg(ap, unsigned long int);
	else if (ft_strstr(fmt->flag, "hh"))
		n = (unsigned char)va_arg(ap, unsigned int);
	else if (ft_strstr(fmt->flag, "h"))
		n = (unsigned short int)va_arg(ap, unsigned int);
	else if (ft_strstr(fmt->flag, "ll"))
		n = (unsigned long long int)va_arg(ap, unsigned long long int);
	else if (ft_strstr(fmt->flag, "l"))
		n = (unsigned long int)va_arg(ap, unsigned long int);
	else if (ft_strstr(fmt->flag, "z"))
		n = (size_t)va_arg(ap, size_t);
	else if (ft_strstr(fmt->flag, "j"))
		n = (size_t)va_arg(ap, uintmax_t);
	else
		n = (unsigned int)va_arg(ap, unsigned int);
	return (n);
}

long long int				cast_di(va_list ap, char *flag)
{
	long long int			d;

	if (ft_strstr(flag, "hh"))
		d = (char)va_arg(ap, int);
	else if (ft_strstr(flag, "h"))
		d = (short int)va_arg(ap, int);
	else if (ft_strstr(flag, "ll"))
		d = va_arg(ap, long long int);
	else if (ft_strstr(flag, "l"))
		d = va_arg(ap, long int);
	else if (ft_strstr(flag, "j"))
		d = va_arg(ap, intmax_t);
	else
		d = (int)va_arg(ap, int);
	return (d);
}
