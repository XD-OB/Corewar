/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelouch <obelouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 04:00:06 by obelouch          #+#    #+#             */
/*   Updated: 2020/01/28 02:28:04 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "errors.h"
# include "op.h"

# include <sys/stat.h>
# include <sys/types.h>
# include <limits.h>
# include <fcntl.h>

/*
**	r: (reverse ) 0 = Assembler
**				  1 = Disassembler
**	a: (annotate) 0 = create the binary file
**				  1 = show the code annotated in stdout
*/

typedef struct		s_asm
{
	int				multi:1;
	int				fd;
	int				r:1;
	int				a:1;
}					t_asm;

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
	char			*file_name;
	char			*name;
	char			*comment;
	t_list			*insts;
	t_chr			*sf;
	t_op			*op_tab;
	int				exec_size;
	t_asm			param_asm;
	int				nl;
}					t_sfile;

typedef struct		s_bfile
{
	char			*file_name;
	unsigned int	mg_head;
	unsigned int	exec_size;
	unsigned int	index;
	unsigned char	name[PROG_NAME_LENGTH + 1];
	unsigned char	comment[COMMENT_LENGTH + 1];
	unsigned char	*exec_code;
	t_list			*insts;
	t_op			*op_tab;
	t_asm			param_asm;
}					t_bfile;

t_chr				*file_save_chr(int fd, int *nl);
void				add_aloneinst(t_sfile *sfile, t_chr **labels,
										char *str, int len);
void				check_args(t_op *op_tab, int op_nbr, char *str);
void				fill_args_atc(t_bfile *bfile, unsigned char *binary,
										t_inst *inst);
void				fill_bin(t_bfile *bfile, int fd);
void				fill_op_tab(t_op *op_tab);
void				fill_optab_p1(t_op *op_case);
void				fill_optab_p2(t_op *op_case);
void				fill_optab_p3(t_op *op_case);
void				get_instructs(t_sfile *sfile, t_chr *begin);
void				get_instructs_bin(t_bfile *bfile);
void				get_insts_values(t_sfile *sfile);
int					get_name_cmt(t_sfile *sfile, t_chr *curr, char *str);
void				exit_inst_error(t_sfile *sfile, t_chr *curr);
int					is_aloneinst(t_op *op_tab, char *str);
int					replace_label(t_list *list_insts, t_inst *inst,
										t_inst *label_pos);
int					save_options(t_asm *asmbl, int ac, char **av);
void				treate_file(char *file, t_asm *asmbl);
void				write_inst_advinfos(t_op op_infos, t_inst *inst);
void				write_exec_code(t_sfile sfile, int fd);
void				write_cor(t_sfile sfile);
void				write_inst_low(t_bfile bfile, t_inst *inst, int bytes);
void				write_s(t_bfile bfile);
void				write_stdout_bin(t_bfile bfile);
void				write_stdout(t_sfile sfile);
char				**split_labels(char *str);

/*
**	exit1:
*/
void				exit_usage(char *exe);
void				exit_serror(t_sfile *sfile, int type);
void				exit_berror(t_bfile *bfile, int type);

/*
**	exit2:
*/
void				exit_ass_error(t_sfile *sfile, t_chr *def, int type);
void				exit_dis_error(t_bfile *bfile, t_inst *inst, int type);
void				exit_error_label(t_sfile *sfile, t_inst *inst, char *label);

/*
**	free:
*/
void				free_inst(t_inst *inst);
void				free_sfile(t_sfile *sfile);
void				free_bfile(t_bfile *bfile);

/*
**	init:
*/
int					init_sfile(t_sfile *sfile, int fd);
int					init_bfile(t_bfile *bfile);
void				init_asmbl(t_asm *asmbl);

/*
**	tools1:
*/
t_inst				*create_inst(void);
long long			ft_strcalcul(char **opts);
void				str_n_combin(char **s1, char *s2);
int					ret_tabstr_free(char ***atab, int ret);

/*
**	tools2:
*/
char				*itohex_w2(int n);
char				*itobin_w8(int n);
int					int_2_bytes(unsigned char *binary);
int					int_4_bytes(unsigned char *binary);
int					int_atc(t_inst *inst);

/*
**	tools3:
*/
int					is_label(char *str);
int					is_comment(char *str);
int					is_cmd(char *str, char *cmd);
int					is_cmds(char *str);

/*
**	types1:
*/
int					is_reg(char *str);
int					is_dir(char *str);
int					is_ind(char *str);

/*
**	types2:
*/
int					is_op(t_op *op_tab, char *str);
int					type_arg(char *str);

/*
**	write_tools:
*/
void				write_short(short n, int fd);
void				write_int(int n, int fd);

#endif
