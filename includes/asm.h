#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "errors.h"
# include "op.h"

#include <sys/stat.h> 
#include <sys/types.h>
#include <fcntl.h>

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

typedef struct		s_bfile
{
	unsigned int	mg_head;
	unsigned int	exec_size;
	unsigned int	index;
	unsigned char	name[PROG_NAME_LENGTH + 1];
	unsigned char	comment[COMMENT_LENGTH + 1];
	unsigned char	*exec_code;
	t_list			*insts;
	t_op			*op_tab;
}					t_bfile;

/*
**	r: (reverse ) 0 = Assembler
**				  1 = Disassembler
**	a: (annotate) 0 = create the binary file
**				  1 = show the code annotated in stdout
*/

typedef struct		s_asm
{
	int				fd;
	int				r:1;
	int				a:1;
}					t_asm;

int			save_options(t_asm *asmbl, int ac, char **av);
void		treate_file(char *file, t_asm *asmbl);
void		fill_op_tab(t_op *op_tab);
void		fill_optab_p1(t_op *op_case);
void		fill_optab_p2(t_op *op_case);
void		fill_optab_p3(t_op *op_case);
void		free_inst(t_inst *inst);
void		free_sfile(t_sfile *sfile);
void		free_bfile(t_bfile *bfile);
int			init_sfile(t_sfile *sfile, int fd);
int			init_bfile(t_bfile *bfile);
void		init_asmbl(t_asm *asmbl);
t_inst		*create_inst(void);
t_chr		*file_save_chr(int fd);
void		tabstr_trim(char **tab);
void		exit_usage(char *exe);
void		exit_ass_error(t_sfile *sfile, t_chr *def, int type);
void		exit_dis_error(t_bfile *bfile, t_inst *inst, int type);
void		exit_qerror(t_sfile *sfile, t_chr *def, int type);
void		exit_serror(t_sfile *sfile, int type);
void		exit_ferror(char *file, int type);
void		exit_berror(t_bfile *bfile, int type);
void		exit_inst_error(t_sfile *sfile, t_chr *curr);
void		exit_error_label(t_sfile *sfile, t_inst *inst, char *label);
int			is_alonelabel(char *str);
int			is_instlabel(t_op *op_tab, char *str);
int			is_aloneinst(t_op *op_tab, char *str);
void		add_instlabel(t_sfile *sfile, t_chr **labels, char *str, int len);
void		add_aloneinst(t_sfile *sfile, t_chr **labels, char *str, int len);
int			type_arg(char *str);
int			is_op(t_op *op_tab, char *str);
int			is_reg(char *str);
int			is_dir(char *str);
int			is_ind(char *str);
int			replace_label(t_list *list_insts, t_inst *inst, t_inst *label_pos);
void		get_insts_values(t_sfile *sfile);
void		get_instructs_bin(t_bfile *bfile);
void		get_instructs(t_sfile *sfile, t_chr *begin);
int			get_name_cmt(t_sfile *sfile, t_chr **curr, char *str);
void		write_exec_code(t_sfile sfile, int fd);
void		write_cor(t_sfile sfile, char *file_name);
void		write_s(t_bfile bfile, char *file_name);
void		write_short(short n, int fd);
void		write_int(int n, int fd);
void		write_inst_advinfos(t_op op_infos, t_inst *inst);
void		write_stdout_bin(t_bfile bfile);
void		write_stdout(t_sfile sfile);
void		write_inst_low(t_bfile bfile, t_inst *inst, int bytes);
char		*itohex_w2(int n);
char		*itobin_w8(int n);
int			int_atc(t_inst *inst);
int			int_2_bytes(unsigned char *binary);
int			int_4_bytes(unsigned char *binary);
void		fill_bin(t_bfile *bfile, int fd);
void		fill_args_atc(t_bfile *bfile, unsigned char *binary, t_inst *inst);

void		print_insts(t_op *op_tab, t_list *insts);
void		print_op_tab(t_op *op_tab);


#endif
