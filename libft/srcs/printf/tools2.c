/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 04:07:35 by obelouch          #+#    #+#             */
/*   Updated: 2019/04/17 09:06:32 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			is_format(char c)
{
	char	*ref;
	int		i;

	i = 0;
	ref = "cspdiouUxXfegrkb}%";
	while (ref[i])
		if (c == ref[i++])
			return (1);
	return (0);
}

int			is_postflag(char c)
{
	char	*ref;
	int		i;

	i = 0;
	ref = "lLh+-rjz";
	while (ref[i])
		if (c == ref[i++])
			return (1);
	return (0);
}

int			is_preflag(char c)
{
	char	*ref;
	int		i;

	i = 0;
	ref = " 0+-#'*$r";
	while (ref[i])
		if (c == ref[i++])
			return (1);
	return (0);
}
