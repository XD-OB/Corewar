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
