#ifndef ASM_H
# define ASM_H

# include "../libft/includes/libft.h"
# include "op.h"

#include <sys/stat.h> 
#include <sys/types.h>
#include <fcntl.h>

# define ERROR_NAME_LENGTH 1
# define ERROR_COMMENT_LENGTH 2
# define ERROR_LEXICAL 3
# define ERROR_NC_NAME_CMT 4
# define ERROR_BAD_INSTRUCT 5
# define ERROR_EXEC_SIZE 6
# define ERROR_ALLOC 7
# define ERROR_FD 8
# define ERROR_LESS_QUOTES 9
# define ERROR_CHAR_QUOTES 10
# define ERROR_NO_QUOTES 11
# define ERROR_NO_STR 12

typedef struct		s_arg
{
	int				type;
	char			*str;
	int				value;
}					t_arg;

/*
**	inst = instruction
*/

typedef struct		s_inst
{
	char			*op_name;
	int				op_nbr;
	t_chr			*labels;
	t_arg			args[3];
	int				nbr_bytes;
	int				line;
}					t_inst;

/*
**	atc: argument type code
*/

typedef struct		s_op
{
	char			*name;
	int				nbr;
	int				args_nbr;
	int				args_type[3];
	int				atc;
	int				tdir_size;
}					t_op;

typedef struct		s_sfile
{
	char			*name;
	char			*comment;
	t_list			*insts;
	t_chr			*sf;
	t_op			*op_tab;
	int				exec_size;
}					t_sfile;

void		fill_op_tab(t_op *op_tab);
void		fill_optab_p1(t_op *op_case);
void		fill_optab_p2(t_op *op_case);
void		fill_optab_p3(t_op *op_case);
void		free_sfile(t_sfile *sfile);
int			init_sfile(t_sfile *sfile, int fd);
void		exit_usage(char *exe);
void		exit_error(t_sfile *sfile, t_chr *def, int type);
void		exit_qerror(t_sfile *sfile, t_chr *def, int type);
void		exit_serror(t_sfile *sfile, int type);
t_chr		*file_save_chr(int fd);
void		tabstr_trim(char **tab);
void		exit_instruct_error(t_sfile *sfile, t_chr *curr);
void		exit_error_label(t_sfile *sfile, t_inst *inst, char *label);
int			type_arg(char *str);
int			is_op(t_op *op_tab, char *str);
int			is_reg(char *str);
int			is_dir(char *str);
int			is_ind(char *str);
int			replace_label(t_list *list_insts, t_inst *inst, t_inst *label_pos);
void		get_insts_values(t_sfile *sfile);
int			get_name_cmt(t_sfile *sfile, t_chr **curr, char *str);
void		write_exec_code(t_sfile sfile, int fd);
void		write_bin(t_sfile sfile, char *file_name);
void		write_short(short n, int fd);
void		write_int(int n, int fd);


void		print_insts(t_list *cmds);
void		print_op_tab(t_op *op_tab);


#endif
