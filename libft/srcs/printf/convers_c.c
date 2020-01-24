/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 02:20:23 by ishaimou          #+#    #+#             */
/*   Updated: 2019/04/08 06:32:19 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_dollar_cs(t_format *fmt)
{
	char		*tmp;
	char		*str;

	str = (fmt->argn > 0) ? ft_itoa(fmt->argn) : ft_strnew(0);
	tmp = ft_strjoin("$", str);
	free(str);
	str = ft_strjoin(tmp, &(fmt->convers));
	free(tmp);
	return (str);
}

int				ft_countnp(char *s)
{
	int			count_np;
	int			i;

	i = -1;
	count_np = 0;
	while (s[++i])
	{
		if ((s[i] >= 0 && s[i] < 32) || s[i] == 127)
			count_np++;
	}
	return (count_np);
}

static void		conv_c_annex(t_lst *lst, char **str, va_list ap, int len)
{
	int			i;

	if (ft_strchr(lst->format->flag, '-'))
	{
		i = 0;
		(*str)[i] = (char)va_arg(ap, int);
		while (++i < len)
			(*str)[i] = ' ';
	}
	else
	{
		i = -1;
		while (++i < len - 1)
			(*str)[i] = (ft_strchr(lst->format->flag, '0') ? '0' : ' ');
		(*str)[i] = (char)va_arg(ap, unsigned int);
	}
}

void			conv_c(t_lst *lst, t_chr **mychr, va_list ap)
{
	int			len;
	char		*str;

	flag_star(lst->format, ap);
	if (flag_dollar(lst))
	{
		(*mychr)->str = ft_dollar_cs(lst->format);
		(*mychr)->len = ft_strlen((*mychr)->str);
		return ;
	}
	len = (lst->format->width < 2) ? 1 : lst->format->width;
	str = ft_strnew(len);
	conv_c_annex(lst, &str, ap, len);
	(*mychr)->str = str;
	(*mychr)->len = len;
}
