#ifndef ASM_H
# define ASM_H

# include "../libft/includes/libft.h"
# include "op.h"

#include <sys/stat.h> 
#include <sys/types.h>
#include <fcntl.h>

# define ERROR_NAME_LENGTH 1
# define ERROR_COMMENT_LENGTH 2
# define ERROR_LESS_QUOTES 3
# define ERROR_LEXICAL 4
# define ERROR_NC_NAME_CMT 5
# define ERROR_BAD_INSTRUCT 6

typedef struct		s_arg
{
	int				type;
	int				value;
}					t_arg;

/*
**	inst = instruction
*/

typedef struct		s_cmd
{
	char			*op;
	t_chr			*labels;
	char			*args[3];
}					t_cmd;

typedef struct		s_inst
{
	int				op;
	t_arg			args[3];
	int				nbr_bytes;
}					t_inst;

typedef struct		s_op
{
	char			*name;
	int				nbr;
	int				args_nbr;
	int				args_type[3];
	int				args_type_code;
	int				tdir_size;
}					t_op;

typedef struct		s_sfile
{
	char			*name;
	char			*comment;
	t_list			*cmds;
	t_list			*insts;
	t_chr			*sf;
	t_op			*op_tab;
}					t_sfile;

void		fill_op_tab(t_op *op_tab);
void		fill_optab_p1(t_op *op_case);
void		fill_optab_p2(t_op *op_case);
void		fill_optab_p3(t_op *op_case);
void		free_sfile(t_sfile *sfile);
int			init_sfile(t_sfile *sfile, int fd);
void		exit_usage(char *exe);
void		exit_error(t_sfile *sfile, t_chr *def, int type);
void		exit_serror(t_sfile *sfile);
t_chr		*file_save_chr(int fd);
void		tabstr_trim(char **tab);
void		exit_instruct_error(t_sfile *sfile, t_chr *curr);
int			type_arg(char *str);
int			is_op(t_op *op_tab, char *str);
int			is_reg(char *str);
int			is_dir(char *str);
int			is_ind(char *str);

#endif
