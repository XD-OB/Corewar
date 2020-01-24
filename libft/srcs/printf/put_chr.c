/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_chr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:38:59 by obelouch          #+#    #+#             */
/*   Updated: 2019/04/18 06:55:07 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			put_chr(t_lst *lst, t_chr *chr)
{
	int		len;

	len = 0;
	while (chr)
	{
		if (lst->format->convers == '}')
			ft_putstr(chr->str);
		else
			write(1, chr->str, chr->len);
		len += chr->len;
		chr = chr->next;
	}
	return (len);
}

int			put_chr_fd(int fd, t_lst *lst, t_chr *chr)
{
	int		len;

	len = 0;
	while (chr)
	{
		if (lst->format->convers == '}')
			ft_putstr_fd(chr->str, fd);
		else
			write(fd, chr->str, chr->len);
		len += chr->len;
		chr = chr->next;
	}
	return (len);
}

int			put_chr_nfd(int fd, size_t n, t_chr *chr)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (chr && len < n)
	{
		i = 0;
		while ((chr->str)[i] && len < n)
		{
			ft_putchar_fd(chr->str[i], fd);
			len++;
			i++;
		}
		chr = chr->next;
	}
	return (len);
}
