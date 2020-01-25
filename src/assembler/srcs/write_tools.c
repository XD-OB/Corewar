/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 02:48:18 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/25 02:48:56 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			write_short(short n, int fd)
{
	char		c[2];

	if (n < 0)
	{
		n = ~(n * -1);
		n += 0x1;
	}
	c[0] = (n >> 8) & 0xff;
	c[1] = n & 0xff;
	ft_putchar_fd(c[0], fd);
	ft_putchar_fd(c[1], fd);
}

void			write_int(int n, int fd)
{
	char		c[4];

	if (n < 0)
	{
		n = ~(n * -1);
		n += 1;
	}
	c[0] = (n >> 24) & 0xff;
	c[1] = (n >> 16) & 0xff;
	c[2] = (n >> 8) & 0xff;
	c[3] = n & 0xff;
	ft_putchar_fd(c[0], fd);
	ft_putchar_fd(c[1], fd);
	ft_putchar_fd(c[2], fd);
	ft_putchar_fd(c[3], fd);
}
