/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corr_arithm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 04:58:57 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/25 00:38:51 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			fill_opts(char **opts, char *arg)
{
	size_t		i;
	size_t		j;

	i = 1;
	while (ft_isdigit(arg[i]))
		i++;
	opts[0] = ft_strsub(arg, 1, i - 1);
	while (ft_isblank(arg[i]))
		i++;
	opts[1] = ft_strnew(1);
	opts[1][0] = arg[i++];
	while (ft_isblank(arg[i]))
		i++;
	j = i;
	while (ft_isdigit(arg[j]))
		j++;
	opts[2] = ft_strsub(arg, i, j - 1);
}

static int		free_opts(char **opts, int ret)
{
	free(opts[0]);
	free(opts[1]);
	free(opts[2]);
	return (ret);
}

int				corr_arithm(int type, char *arg, t_op op_ref)
{
	size_t		len;
	char		*opts[3];
	long long	n;

	fill_opts(opts, arg);
	if (type == T_DIR && op_ref.tdir_size == 4)
	{
		len = (arg[0] == '-') ? 11 : 10;
		if ((ft_strlen(opts[0]) > len) || (ft_strlen(opts[2]) > len))
			return (free_opts(opts, 0));
		n = ft_strcalcul(opts);
		if (n < INT_MIN || n > 4294967295)
			return (free_opts(opts, 0));
		return (free_opts(opts, 1));
	}
	len = (arg[0] == '-') ? 6 : 5;
	if ((ft_strlen(opts[0]) > len) || (ft_strlen(opts[2]) > len))
		return (free_opts(opts, 0));
	n = ft_strcalcul(opts);
	if (n < SHRT_MIN || n > 65535)
		return (free_opts(opts, 0));
	return (free_opts(opts, 1));
}
