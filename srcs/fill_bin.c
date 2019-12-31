#include "asm.h"

static void			exit_check_error(int type)
{
	if (type == ERROR_READ)
		ft_putendl("Wrong Binary Format!");
	else if (type == ERROR_MAGIC)
		ft_putendl("Wrong Magic Header!");
	else if (type == ERROR_ALLOC)
		ft_putendl("Can't Allocate Memory!");
	else if (type == ERROR_NULL)
		ft_putendl("Wrong Control point! (Expect 0)");
	else if (type == ERROR_WRONG_EXESIZE)
	{
		ft_putstr("The Size of the Executable Code ");
		ft_putendl("doesn't match Executable Size!");
	}
	exit(EXIT_FAILURE);
}

unsigned int		read_4_bytes(int fd)
{
	unsigned char	c[4];
	unsigned int	res;

	if (!read(fd, c, 4))
		exit_check_error(ERROR_READ);
	res = (c[0] << 24) | (c[1] << 16) |
		(c[2] << 8) | c[3];
	return (res);
}

static void			check_null(int fd)
{
	unsigned char	null[4];

	if (!read(fd, null, 4))
		exit_check_error(ERROR_READ);
	if (null[0] != 0 || null[1] != 0 ||
			null[2] != 0 || null[2] != 0)
		exit_check_error(ERROR_NULL);
}

unsigned char		*fill_exec_code(int fd, unsigned int size)
{
	unsigned char	*exec_code;
	unsigned char	c;

	if (!(exec_code =
				(unsigned char*)malloc(sizeof(unsigned char) * size)))
		exit_check_error(ERROR_ALLOC);
	if (!read(fd, exec_code, size))
	{
		free(exec_code);
		exit_check_error(ERROR_ALLOC);
	}
	if (read(fd, &c, 1))
	{
		free(exec_code);
		exit_check_error(ERROR_WRONG_EXESIZE);
	}
	return (exec_code);
}

void				fill_bin(t_bfile *bfile, int fd)
{
	bfile->mg_head = read_4_bytes(fd);
	if (bfile->mg_head != COREWAR_EXEC_MAGIC)
		exit_check_error(ERROR_MAGIC);
	ft_printf("%u\n", bfile->mg_head);			////////////////
	if (!read(fd, bfile->name, PROG_NAME_LENGTH))
		exit_check_error(ERROR_READ);
	ft_printf("%s\n", bfile->name);			////////////////
	check_null(fd);
	bfile->exec_size = read_4_bytes(fd);
	ft_printf("%u\n", bfile->exec_size);			///////////////
	if (!read(fd, bfile->comment, COMMENT_LENGTH))
		exit_check_error(ERROR_READ);
	ft_printf("%s\n", bfile->comment);			//////////////
	check_null(fd);
	bfile->exec_code = fill_exec_code(fd, bfile->exec_size);
}
