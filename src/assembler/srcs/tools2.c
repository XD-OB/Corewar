/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:00:40 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/25 02:47:18 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			int_4_bytes(unsigned char *binary)
{
	int		res;

	res = 0;
	res = (binary[0] << 24) | (binary[1] << 16) |
		(binary[2] << 8) | binary[3];
	return (res);
}

int			int_2_bytes(unsigned char *binary)
{
	short	res;

	res = 0;
	res = (binary[0] << 8) | binary[1];
	return (res);
}

int			int_atc(t_inst *inst)
{
	unsigned char	arg[3];
	int				res;
	int				i;

	res = 0;
	i = 0;
	while (i < 3)
	{
		if (inst->args[i].type == T_REG)
			arg[i] = REG_CODE;
		else if (inst->args[i].type == T_DIR)
			arg[i] = DIR_CODE;
		else if (inst->args[i].type == T_IND)
			arg[i] = IND_CODE;
		i++;
	}
	arg[0] <<= 6;
	arg[1] <<= 4;
	arg[2] <<= 2;
	res = arg[0] | arg[1] | arg[2];
	return (res);
}

char		*itobin_w8(int n)
{
	char	*str;
	char	*tmp;
	int		len;
	int		i;
	int		j;

	tmp = ft_itoa_base(n, 2);
	len = ft_strlen(tmp);
	if (len == 8)
		return (tmp);
	str = ft_strcnew(8, '0');
	i = len - 1;
	j = 7;
	while (i >= 0)
		str[j--] = tmp[i--];
	free(tmp);
	return (str);
}

char		*itohex_w2(int n)
{
	char	*str;
	char	*tmp;

	tmp = ft_itoa_base(n, 16);
	if (ft_strlen(tmp) >= 2)
		return (tmp);
	str = ft_strjoin("0", tmp);
	free(tmp);
	return (str);
}
