/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_u_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 07:01:09 by ishaimou          #+#    #+#             */
/*   Updated: 2019/04/09 07:07:57 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*all_zero_u(char *nbr, int precis)
{
	char			*res;
	int				i;
	int				j;
	int				len_nbr;

	len_nbr = ft_strlen(nbr);
	if (precis > len_nbr)
	{
		res = ft_strnew(len_nbr);
		i = 0;
		j = 0;
		while (i < precis - len_nbr)
			res[i++] = '0';
		while (i < precis)
			res[i++] = nbr[j++];
		return (res);
	}
	return (ft_strdup(nbr));
}

static int			precis_u_annex(t_format *fmt, int nbr_len, char **str)
{
	char			*new;
	int				i;
	int				j;

	new = ft_strcnew(fmt->precis, '0');
	if (ft_strchr(fmt->flag, '-'))
	{
		i = -1;
		while (++i < fmt->precis - nbr_len)
			new[i] = '0';
		j = 0;
		while (i < fmt->precis)
			new[i++] = (*str)[j++];
	}
	else
	{
		j = 0;
		i = fmt->precis - nbr_len;
		while (i < fmt->precis)
			new[i++] = (*str)[j++];
	}
	free(*str);
	*str = new;
	return (ft_strlen(new));
}

void				precis_u(char **str, t_format *fmt, int nbr_len)
{
	int				i;
	int				j;
	int				len;
	char			*res;

	i = -1;
	len = (fmt->precis > nbr_len) ? precis_u_annex(fmt, nbr_len, str) : nbr_len;
	res = ft_strnew(fmt->width);
	if (ft_strchr(fmt->flag, '-'))
	{
		while (++i < len)
			res[i] = (*str)[i];
		while (i < fmt->width)
			res[i++] = ' ';
	}
	else
	{
		j = 0;
		while (++i < fmt->width - len)
			res[i] = ' ';
		while (i < fmt->width)
			res[i++] = (*str)[j++];
	}
	free(*str);
	*str = res;
}
