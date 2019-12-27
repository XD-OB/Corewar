/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_ee_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 06:48:35 by obelouch          #+#    #+#             */
/*   Updated: 2019/04/17 11:34:29 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	new[2]:		new[0]: new_entier	new[1]: new_fract
** 	len[3]:	len[0]: len_e	len[1]: len_f	len[2]: pos   len[3]: len
*/

char		*eprefix(t_format *fmt, long *len)
{
	char	*prefix;
	char	*sc_e;
	char	*num_e;

	if (len[2] >= 0 && len[2] < 10)
		sc_e = ft_strdup("e+0");
	else if (len[2] > 9)
		sc_e = ft_strdup("e+");
	else if (len[2] < -9)
		sc_e = ft_strdup("e-");
	else
		sc_e = ft_strdup("e-0");
	if (fmt->convers == 'E')
		ft_strupcase(sc_e);
	num_e = ft_utoa(ABS(len[2]));
	prefix = ft_strjoin(sc_e, num_e);
	len[3] = ft_strlen(prefix);
	free(num_e);
	free(sc_e);
	return (prefix);
}

char		*ejoin(t_format *fmt, char *entier, char *fract, long *len)
{
	char	*prefix;
	char	*tmp;
	char	*str;

	prefix = eprefix(fmt, len);
	len[3] += len[0];
	if (ft_strcmp(fract, "\0") || ft_strchr(fmt->flag, '#'))
	{
		str = ft_strjoin(entier, ".");
		len[3]++;
	}
	else
		str = ft_strdup(entier);
	if (ft_strcmp(fract, "\0"))
	{
		tmp = ft_strjoin(str, fract);
		len[3] += len[1];
		free(str);
	}
	else
		tmp = str;
	str = ft_strjoin(tmp, prefix);
	free(prefix);
	free(tmp);
	return (str);
}

static void	fix_esize(char **str, long len_s, long size)
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

static char	*eprecis_zero(char *str, long *carry)
{
	char	*s;

	if (str[0] > '4')
		*carry = 1;
	s = ft_strnew(0);
	return (s);
}

void		eprecis(char **str, long precis, long *carry, long *len_s)
{
	char	*fract;
	char	*tmp;

	if (precis == 0)
		fract = eprecis_zero(*str, carry);
	else
	{
		if (precis > *len_s)
			fix_esize(str, *len_s, precis + 2);
		fract = ft_strndup(*str, precis);
		*len_s = precis;
		if ((*str)[precis] > '4')
		{
			sumstr(&fract, "1", 10);
			if ((int)ft_strlen(fract) > precis)
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
