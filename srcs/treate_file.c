#include "asm.h"

static void		encode_asm(t_asm *asmbl, char *file_name)
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
		exit_ass_error(&sfile, curr, ERROR_NC_NAME_CMT);
	if (asmbl->a)
		write_stdout(sfile);
	else
		write_cor(sfile, file_name);
	free_sfile(&sfile);
}

static void		decode_asm(t_asm *asmbl, char *file_name)
{
	t_bfile		bfile;

	(void)file_name;
	if (!init_bfile(&bfile))
		exit_berror(&bfile, ERROR_ALLOC);
	fill_bin(&bfile, asmbl->fd);
	get_instructs_bin(&bfile);
	if (asmbl->a)
		write_stdout_bin(bfile);
	else
		write_s(bfile, file_name);
	free_bfile(&bfile);
}

void			treate_file(char *file, t_asm *asmbl)
{
	char		*file_name;

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
