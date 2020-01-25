/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_advinfos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:00:23 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/25 02:47:34 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void			write_4_bit(int n)
{
	unsigned char	c[4];
	char			*str;
	int				i;

	if (n < 0)
	{
		n = ~(n * -1);
		n += 1;
	}
	c[0] = (n >> 24) & 0xff;
	c[1] = (n >> 16) & 0xff;
	c[2] = (n >> 8) & 0xff;
	c[3] = n & 0xff;
	i = 0;
	while (i < 4)
	{
		str = ft_itoa_base(c[i], 16);
		ft_printf("|%02s", str);
		free(str);
		i++;
	}
}

static void			write_2_bit(int n)
{
	unsigned char	c[2];
	char			*str;

	if (n < 0)
	{
		n = ~(n * -1);
		n += 1;
	}
	c[0] = (n >> 8) & 0xff;
	c[1] = n & 0xff;
	ft_printf("      ");
	str = ft_itoa_base(c[0], 16);
	ft_printf("|%02s", str);
	free(str);
	str = ft_itoa_base(c[1], 16);
	ft_printf("|%02s", str);
	free(str);
}

static void			write_advargs(t_op op_infos, t_inst *inst)
{
	char			*str;
	int				i;

	i = 0;
	ft_printf(" ");
	while (i < op_infos.args_nbr)
	{
		if (i > 0)
			ft_printf("         ");
		if (inst->args[i].type == T_REG)
		{
			str = ft_itoa_base(inst->args[i].value, 16);
			ft_printf("         ");
			ft_printf("|%02s", str);
			free(str);
		}
		else if (inst->args[i].type == T_DIR
				&& op_infos.tdir_size == 4)
			write_4_bit(inst->args[i].value);
		else
			write_2_bit(inst->args[i].value);
		i++;
	}
}

void				write_inst_advinfos(t_op op_infos, t_inst *inst)
{
	char			*str;

	ft_printf("                  ");
	str = ft_itoa_base(inst->op_nbr, 16);
	ft_printf("%02s   ", str);
	free(str);
	if (op_infos.atc)
	{
		str = ft_itoa_base(int_atc(inst), 2);
		ft_printf("%08s", str);
		free(str);
	}
	else
		ft_printf("        ");
	write_advargs(op_infos, inst);
	ft_printf("\n");
}
