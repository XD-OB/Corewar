/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_f_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 13:36:30 by obelouch          #+#    #+#             */
/*   Updated: 2019/04/17 16:32:55 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fix_fsize(char **str, long len_s, long size)
{
	char	*res;
	long	i;

	res = (char*)malloc(sizeof(char) * (size + 1));
	res[size] = '\0';
	i = 0;
	while (i < len_s)
	{
		res[i] = (*str)[i];
		i++;
	}
	while (i < size)
		res[i++] = '0';
	free(*str);
	*str = res;
}

static char	*fprecis_zero(char *str, long *carry, long precis)
{
	char	*s;

	if (precis == 0)
	{
		if (str[0] > '4')
			*carry = 1;
		s = ft_strnew(0);
		return (s);
	}
	return (NULL);
}

void		fprecis(char **str, long precis, long *carry, long base)
{
	char	*fract;
	char	*tmp;
	long	len_s;

	fract = fprecis_zero(*str, carry, precis);
	if (!fract)
	{
		len_s = ft_strlen(*str);
		if (precis > len_s)
			fix_fsize(str, len_s, precis + 2);
		fract = ft_strndup(*str, precis);
		if ((*str)[precis] > '4')
		{
			sumstr(&fract, "1", base);
			if ((long)ft_strlen(fract) > precis)
			{
				tmp = fract;
				fract = ft_strsub(tmp, 1, precis);
				free(tmp);
				*carry = 1;
			}
		}
	}
	free(*str);
	*str = fract;
}

void		add_sign_f(t_format *fmt, char **str, long *len, int sign)
{
	char	*res;
	long	i;

	if (ft_strpbrk(fmt->flag, "+ ") || sign)
	{
		(*len)++;
		res = (char*)malloc(sizeof(char) * (*len + 1));
		res[*len] = '\0';
		if (sign)
			res[0] = '-';
		else
			res[0] = (ft_strchr(fmt->flag, '+')) ? '+' : ' ';
		i = 0;
		while (++i < *len)
			res[i] = (*str)[i - 1];
		free(*str);
		*str = res;
	}
}
