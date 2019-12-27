/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   date.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 02:48:52 by obelouch          #+#    #+#             */
/*   Updated: 2019/04/18 08:28:32 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void				date_conv(long int s, long int *y, unsigned int *date)
{
	int					era;
	long int			nbr_days;
	unsigned int		ey[4];

	nbr_days = s / 86400 + 719468;
	if (nbr_days < 0)
		era = (nbr_days - 146096) / 146097;
	era = (int)(nbr_days / 146097);
	ey[0] = (unsigned int)(nbr_days - era * 146097);
	ey[2] = (ey[0] - ey[0] / 1460 + ey[0] / 36524 - ey[0] / 146096) / 365;
	*y = (int)ey[2] + era * 400;
	ey[1] = ey[0] - (365 * ey[2] + ey[2] / 4 - ey[2] / 100);
	ey[3] = (5 * ey[1] + 2) / 153;
	date[1] = ey[1] - (153 * ey[3] + 2) / 5 + 1;
	if (ey[3] < 10)
		date[0] = ey[3] + 3;
	else
		date[0] = ey[3] - 9;
	*y += (date[0] <= 2);
}

static unsigned int		fill_times(long int y, char **times, int size,
											unsigned int *date)
{
	char				*tmp;
	int					i;
	unsigned int		len;

	i = 0;
	len = 0;
	times[0] = ft_utoa(y);
	times[1] = ft_utoa(date[0]);
	times[2] = ft_utoa(date[1]);
	if (date[0] <= 9)
	{
		tmp = times[1];
		times[1] = ft_strjoin("0", times[1]);
		free(tmp);
	}
	if (date[1] <= 9)
	{
		tmp = times[2];
		times[2] = ft_strjoin("0", times[2]);
		free(tmp);
	}
	while (i < size)
		len += ft_strlen(times[i++]);
	return (len);
}

static char				*c_date(char **times, int len)
{
	char				*res;

	len += 2;
	res = ft_strnew(len);
	ft_strcat(res, times[0]);
	ft_strcat(res, "-");
	ft_strcat(res, times[1]);
	ft_strcat(res, "-");
	ft_strcat(res, times[2]);
	return (res);
}

/*
**	var:		var[0] : s		var[1] : y		var[2] : i
*/

void					conv_k(t_chr **mychr, va_list ap)
{
	long int			var[3];
	unsigned int		date[3];
	char				*times[3];
	char				*res;
	unsigned int		len;

	var[0] = (long int)va_arg(ap, long int);
	date_conv(var[0], &var[1], date);
	len = fill_times(var[1], times, 3, date);
	res = c_date(times, len);
	(*mychr)->str = res;
	(*mychr)->len = ft_strlen(res);
	var[2] = -1;
	while (++var[2] < 3)
		free(times[var[2]]);
}
