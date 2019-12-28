#include "./includes/asm.h"

int			is_reg(char *str)
{
	int		n;
	int		i;

	if (str[0] != 'r')
		return (0);
	if (ft_strlen(str) == 2)
	{
		if (!ft_isdigit(str[1]))
			return (0);
		n = str[1] - 48;
		if (n == 0 || n > REG_NUMBER)
			return (0);
		return (1);
	}
	else if (ft_strlen(str) == 3)
	{
		if (!ft_isdigit(str[i]) || !ft_isdigit(str[i]))
			return (0);
		n = ft_atoi(&str[1]);
		if (n == 0 || n > REG_NUMBER)
			return (0);
		return (1);
	}
	return (0);
}

int			is_dir(char *str)
{
	int		i;

	if (str[0] != DIRECT_CHAR)
		return (0);
	if (str[1] == LABEL_CHAR)
	{
		i = 1;
		while (str[++i])
			if (!ft_strchr(LABEL_CHARS, str[i]))
				return (0);
		return (1);
	}
	i = 0;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}

int			is_ind(char *str)
{
	int		i;

	if (str[0] == LABEL_CHAR)
	{
		i = 0;
		while (str[++i])
			if (!ft_strchr(LABEL_CHARS, str[i]))
				return (0);
		return (1);
	}
	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}

int			type_arg(char *str)
{
	if (is_reg(str))
		return (T_REG);
	else if (is_dir(str))
		return (T_DIR);
	else if (is_ind(str))
		return (T_IND);
	else
		return (0);
}

int			is_op(t_op *op_tab, char *str)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		if (!ft_strcmp(str, op_tab[i].name))
			return (i + 1);
		i++;
	}
	return (0);
}
