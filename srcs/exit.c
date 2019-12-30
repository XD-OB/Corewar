#include "asm.h"

void	exit_serror(t_sfile *sfile, int type)
{
	free_sfile(sfile);
	if (type == ERROR_FD)
		ft_printf("Error While Creating the .cor File!\n");
	else if (type == ERROR_ALLOC)
		ft_printf("Error Will Allocating Memory\n");
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
	ft_printf(" [-r | --reverse] <sourcefile.s> ...\n");
	ft_printf("       -r : deassembler mode\n");
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

void	exit_error(t_sfile *sfile, t_chr *def, int type)
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
