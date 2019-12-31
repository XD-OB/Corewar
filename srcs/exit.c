#include "asm.h"

void	exit_serror(t_sfile *sfile, int type)
{
	free_sfile(sfile);
	if (type == ERROR_FD)
		ft_printf("Error While Creating the .cor File!\n");
	else if (type == ERROR_ALLOC)
		ft_printf("Can't Allocate Memory\n");
	else if (type == ERROR_EXEC_SIZE)
	{
		ft_printf("Executable Code Exceed the Max!");
		ft_printf(" (Max %d)\n", CHAMP_MAX_SIZE);
	}
	exit(EXIT_FAILURE);
}

void	exit_usage(char *exe)
{
	ft_printf("%{red}Usage:%{eoc} %s", exe);
	ft_printf(" [-ra] <sourcefile.s> ...\n");
	ft_printf("  --reverse   -r : deassembler mode\n");
	ft_printf("  --annotated -a : annotated mode\n");
	exit(EXIT_FAILURE);
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

void	exit_qerror(t_sfile *sfile, t_chr *def, int type)
{
	ft_printf("line %{red}%d%{eoc}:", def->len);
	if (type == ERROR_LESS_QUOTES)
		ft_printf(" Closing quote not found!\n");
	else if (type == ERROR_CHAR_QUOTES)
		ft_printf(" Character before the quote!\n");
	else if (type == ERROR_NO_STR)
		ft_printf(" No string after the parameter!\n");
	else if (type == ERROR_NO_QUOTES)
		ft_printf(" No Quotes for the string!\n");
	free_sfile(sfile);
	exit(EXIT_FAILURE);
}

void	exit_ferror(char *file, int type)
{
	if (type == ERROR_FILE_NF)
		ft_printf("%{red}%s%{eoc}: File not found!\n", file);
	else if (type == ERROR_FILE_BE)
		ft_printf("%{red}%s%{eoc}: File with Bad extension!\n", file);
	exit(EXIT_FAILURE);
}

void	exit_dis_error(t_bfile *bfile, t_inst *inst, int type)
{
	ft_printf("Byte %{red}%d%{eoc}: ", bfile->index);
	if (type == ERROR_WRONG_OP)
		ft_printf("Invalid Id Operation! [ %d ]\n", inst->op_nbr);
	if (type == ERROR_WRONG_ATC)
		ft_printf("Invalid Argument Type Code for %{green}%s%{eoc}!\n",
				bfile->op_tab[inst->op_nbr - 1].name);
	if (type == ERROR_INCOMPLET_OP)
		ft_printf("Less Bytes to treate The Operations! %{green}%s%{green}\n",
				bfile->op_tab[inst->op_nbr - 1].name);
	free_bfile(bfile);
	free_inst(inst);
	exit(EXIT_FAILURE);
}

void	exit_ass_error(t_sfile *sfile, t_chr *def, int type)
{
	ft_printf("line %{red}%d%{eoc}:", def->len);
	if (type == ERROR_NAME_LENGTH)
	{
		ft_printf(" Champion name is too long ");
		ft_printf("(Max length %d)\n", PROG_NAME_LENGTH);
	}
	else if (type == ERROR_COMMENT_LENGTH)
	{
		ft_printf(" Champion comment is too long ");
		ft_printf("(Max length %d)\n", COMMENT_LENGTH);
	}
	else if (type == ERROR_LEXICAL)
		ft_printf(" Lexical Error!\n");
	else if (type == ERROR_NC_NAME_CMT)
	{
		ft_printf(" Syntax Error! Wrong line ");
		ft_printf("or Executable Code before name and comment!\n");
	}
	else if (type == ERROR_BAD_INSTRUCT)
	{
		ft_printf(" Syntax Error! Bad Instruction! ");
		ft_printf("%{green}[%{eoc}%s%{green}]%{eoc}\n", def->str);
	}
	free_sfile(sfile);
	exit(EXIT_FAILURE);
}

void		exit_error_label(t_sfile *sfile, t_inst *inst, char *label)
{
	ft_printf("line %{red}%d%{eoc}:", inst->line);
	ft_printf("Invalid Label [%s] As Argument!\n", label);
	free_sfile(sfile);
	exit(EXIT_FAILURE);
}
