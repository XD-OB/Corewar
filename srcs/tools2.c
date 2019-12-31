#include "asm.h"

char			*itobin_w8(int n)
{
	char		*str;
	char		*tmp;
	int			len;
	int			i;
	int			j;

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

char			*itohex_w2(int n)
{
	char		*str;
	char		*tmp;

	tmp = ft_itoa_base(n, 16);
	if (ft_strlen(tmp) >= 2)
		return (tmp);
	str = ft_strjoin("0", tmp);
	free(tmp);
	return (str);
}
