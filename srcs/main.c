#include "asm.h"

void			encode_asm(t_asm *asmbl, char *file_name)
{
	t_sfile		sfile;
	t_chr		*curr;

	if (!init_sfile(&sfile, asmbl->fd))
		exit_serror(&sfile, ERROR_ALLOC);
	curr = sfile.sf;
	while (curr)
	{
		if (get_name_cmt(&sfile, &curr, curr->str))
			break ;
		curr = curr->next;
	}
	if (sfile.name && sfile.comment)
		get_instructs(&sfile, curr);
	else
		exit_error(&sfile, curr, ERROR_NC_NAME_CMT);
	if (asmbl->a)
		write_stdout(sfile);
	else
		write_cor(sfile, file_name);
	free_sfile(&sfile);
}

int				init_bfile(t_bfile *bfile)
{
	bfile->name = NULL;
	bfile->comment = NULL;
	bfile->insts = NULL;
	if (!(bfile->op_tab = (t_op*)malloc(sizeof(t_op) * 16)))
		return (0);
	fill_op_tab(bfile->op_tab);
	return (1);
}

void	exit_berror(t_bfile *bfile, int type)
{
	free_bfile(bfile);
	if (type == ERROR_FD)
		ft_printf("Error While Creating the .s File!\n");
	else if (type == ERROR_ALLOC)
		ft_printf("Error Will Allocating Memory\n");
	else if (type == ERROR_EXEC_SIZE)
	{
		ft_printf("Executable Code Exceed the Max!");
		ft_printf(" (Max %d)\n", CHAMP_MAX_SIZE);
	}
	exit(EXIT_FAILURE);
}

void			fill_bin(t_bin *bf, int fd)
{
	if (!read(fd, bf->header, 4))
		exit(1);
	ft_printf("%d\n", (int)bf->header[0]);
	ft_printf("%d\n", (int)bf->header[1]);
	ft_printf("%d\n", (int)bf->header[2]);
	ft_printf("%d\n", (int)bf->header[3]);
	if (!read(fd, bf->name, PROG_NAME_LENGTH))
		exit(1);
	ft_printf("%s\n", &bf->name);
	if (!read(fd, bf->null, 4))
		exit(1);
	if (!read(fd, bf->exec_size, 4))
		exit(1);
	ft_printf("%d\n", (int)bf->exec_size[0]);
	ft_printf("%d\n", (int)bf->exec_size[1]);
	ft_printf("%d\n", (int)bf->exec_size[2]);
	ft_printf("%d\n", (int)bf->exec_size[3]);
	if (!read(fd, bf->comment, COMMENT_LENGTH))
		exit(1);
	ft_printf("%s\n", &bf->comment);
	if (!read(fd, bf->null, 4))
		exit(1);
}

void			decode_asm(t_asm *asmbl, char *file_name)
{
	t_bfile		bfile;

	(void)file_name;
	if (!init_bfile(&bfile))
		exit_berror(&bfile, ERROR_ALLOC);
	fill_bin(&bfile.bf, asmbl->fd);
}

void	treate_file(char *file, t_asm *asmbl)
{
	char	*file_name;

	asmbl->fd = open(file, O_RDONLY);
	if (asmbl->fd < 0)
		exit_ferror(file, ERROR_FILE_NF);
	if (asmbl->r)
	{
		if (ft_strcmp(&file[ft_strlen(file) - 4], ".cor"))
			exit_ferror(file, ERROR_FILE_BE);
		file_name = ft_strndup(file, ft_strlen(file) - 4);
		decode_asm(asmbl, file_name);
		free(file_name);
	}
	else
	{
		if (ft_strcmp(&file[ft_strlen(file) - 2], ".s"))
			exit_ferror(file, ERROR_FILE_BE);
		file_name = ft_strndup(file, ft_strlen(file) - 2);
		encode_asm(asmbl, file_name);
		free(file_name);
	}
	close(asmbl->fd);
}

void	init_asmbl(t_asm *asmbl)
{
	asmbl->fd = -1;
	asmbl->r = 0;
	asmbl->a = 0;
}

int		main(int ac, char **av)
{
	t_asm	asmbl;
	int		i;

	if (ac == 1)
		exit_usage(av[0]);
	init_asmbl(&asmbl);
	i = save_options(&asmbl, ac, av);
	while (i < ac)
		treate_file(av[i++], &asmbl);			//!!!!!!
	return (EXIT_SUCCESS);
}
