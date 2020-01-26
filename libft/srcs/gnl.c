/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 23:49:59 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/26 05:56:40 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  gnl V1.2:
**  return :
** 	   nl = 1 : the line had \n
**	      = 2 : the line had eof
**   or:  -1 : error
**         0 : read complete
*/

static	unsigned int	ft_linelen(char *tab, int *nl)
{
	unsigned int	i;

	i = 0;
	while (tab[i] != '\n' && tab[i] != '\0')
		i++;
	if (tab[i] == '\n')
		*nl = 1;
	return (i);
}

static	unsigned int	ft_linestop(char *tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i] != '\n' && tab[i] != '\0')
		i++;
	return (i);
}

static	char			*ft_line(char *tab)
{
	if (ft_strchr(tab, '\n'))
	{
		ft_strcpy(tab, ft_strchr(tab, '\n') + 1);
		return (tab);
	}
	if (ft_linestop(tab) > 0)
	{
		ft_strcpy(tab, ft_strchr(tab, '\0'));
		return (tab);
	}
	return (NULL);
}

int						gnl(int const fd, char **line)
{
	char			*tmp;
	char			buff[BUFF_SIZE + 1];
	static char		*tab[256];
	int				ret;
	int				nl;

	nl = 2;
	if (fd < 0 || BUFF_SIZE < 1 || !line || read(fd, buff, 0) < 0)
		return (-1);
	if (!(tab[fd]) && (tab[fd] = ft_strnew(0)) == NULL)
		return (-1);
	while (!(ft_strchr(tab[fd], '\n')) && (ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = tab[fd];
		tab[fd] = ft_strnjoin(tmp, buff, ret);
		free(tmp);
	}
	*line = ft_strsub(tab[fd], 0, ft_linelen(tab[fd], &nl));
	if (ft_line(tab[fd]) == NULL)
		return (0);
	return (nl);
}
