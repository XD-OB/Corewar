/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noprint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:19:08 by obelouch          #+#    #+#             */
/*   Updated: 2019/04/03 17:19:51 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*no_print_1(char c)
{
	if (c == 0)
		return (ft_strdup("[NUL]"));
	if (c == 1)
		return (ft_strdup("[SOH]"));
	if (c == 2)
		return (ft_strdup("[STX]"));
	if (c == 3)
		return (ft_strdup("[ETX]"));
	if (c == 4)
		return (ft_strdup("[EOT]"));
	if (c == 5)
		return (ft_strdup("[ENQ]"));
	if (c == 6)
		return (ft_strdup("[ACK]"));
	if (c == 7)
		return (ft_strdup("[BEL]"));
	if (c == 8)
		return (ft_strdup("[BS ]"));
	if (c == 9)
		return (ft_strdup("[HT ]"));
	if (c == 10)
		return (ft_strdup("[LF ]"));
	return (ft_strdup("[VT ]"));
}

static char		*no_print_2(char c)
{
	if (c == 12)
		return (ft_strdup("[FF ]"));
	if (c == 13)
		return (ft_strdup("[CR ]"));
	if (c == 14)
		return (ft_strdup("[SO ]"));
	if (c == 15)
		return (ft_strdup("[SI ]"));
	if (c == 16)
		return (ft_strdup("[DLE]"));
	if (c == 17)
		return (ft_strdup("[DC1]"));
	if (c == 18)
		return (ft_strdup("[DC2]"));
	if (c == 19)
		return (ft_strdup("[DC3]"));
	if (c == 20)
		return (ft_strdup("[DC4]"));
	if (c == 21)
		return (ft_strdup("[NAK]"));
	return (ft_strdup("[SYN]"));
}

static char		*no_print_3(char c)
{
	if (c == 23)
		return (ft_strdup("[ETB]"));
	if (c == 24)
		return (ft_strdup("[CAN]"));
	if (c == 25)
		return (ft_strdup("[EM ]"));
	if (c == 26)
		return (ft_strdup("[SUB]"));
	if (c == 27)
		return (ft_strdup("[ESC]"));
	if (c == 28)
		return (ft_strdup("[FS ]"));
	if (c == 29)
		return (ft_strdup("[GS ]"));
	if (c == 30)
		return (ft_strdup("[RS ]"));
	if (c == 31)
		return (ft_strdup("[US ]"));
	return (ft_strdup("[DEL]"));
}

char			*flag_r(char c)
{
	if (c < 12)
		return (no_print_1(c));
	if (c >= 12 && c < 23)
		return (no_print_2(c));
	if (c == 127 || (c >= 23 && c < 32))
		return (no_print_3(c));
	return (NULL);
}
