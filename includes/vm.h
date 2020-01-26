/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaguert <aaguert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 14:19:36 by aaguert           #+#    #+#             */
/*   Updated: 2020/01/26 04:48:12 by obelouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <stdio.h>
# include "libft.h"
# include "op.h"

/*
** general defines
*/

# define COREWAR_FILE_EXTENTIN ".cor"

/*
** list of flags defines
** _T suffix means the extual representation of tha flag
** _I represents the index of the flag in the global array of flags (g_flags)
*/

# define SUPPORTED_FLAGS_NUM 7

# define FLAG_VISUAL_I 0
# define FLAG_VISUAL_T "v"
# define VIS g_flags[FLAG_VISUAL_I].present

# define FLAG_ORDER_I 1
# define FLAG_ORDER_T "n"

# define FLAG_DUMP_I 2
# define FLAG_DUMP_T "dump"

# define FLAG_S_I 3
# define FLAG_S_T "s"

# define FLAG_D_I 4
# define FLAG_D_T "D"

# define FLAG_SM_D_I 5
# define FLAG_SM_D_T "d"

# define FLAG_A_I 6
# define FLAG_A_T "a"

# define SET_CARRY 1

# define FSE (g_flags[FLAG_S_I].present)
# define FDE (g_flags[FLAG_D_I].present)
# define SMD (g_flags[FLAG_SM_D_I].present)

# define DUMP (g_flags[FLAG_DUMP_I].present || FDE || FSE || SMD)

/*
*******
*/

typedef struct			s_order_flag_arg
{
	t_bool				visited;
	char				*champ;
}						t_order_flag_arg;

union					u_flag_arg
{
	char				*order_data[MAX_PLAYERS];
	int					num;
};

typedef struct			s_flag
{
	t_bool				present;
	union u_flag_arg	data;
}						t_flag;

extern t_flag			g_flags[];

/*
** *****************************************************************
*/

/*
** player management
*/

typedef struct			s_player
{
	t_bool				present;
	t_header			header;
	unsigned char		ex_code[CHAMP_MAX_SIZE];
	int					lives_last_check;
	int					last_live_cycle;
}						t_player;

extern t_player			g_players[];

/*
** ***************** ARENA ********************
** --------------------------------------------
*/

/*
** peocesses
*/

typedef struct			s_op_buff
{
	int					op;
	int					cycles_last;
}						t_op_buff;

typedef struct			s_pvis
{
	int					prev_color;
	int					prev_attrs;
}						t_pvis;

typedef	struct			s_process
{
	int					pid;
	int					player_id;
	int					carry;
	int					last_live_cycle;
	int					pc;
	int					reg[REG_NUMBER];
	t_bool				declared_live;
	t_op_buff			op_buff;
	t_pvis				pvis;
	struct s_process	*next;
}						t_process;

/*
** **
*/

/*
**	operations
*/

# define OPS_NUM 17

enum	e_inst
{
	LIVE_I,
	LD_I,
	ST_I,
	ADD_I,
	SUB_I,
	AND_I,
	OR_I,
	XOR_I,
	ZJMP_I,
	LDI_I,
	STI_I,
	FORK_I,
	LLD_I,
	LLDI_I,
	LFORK_I,
	AFF_I
};

/*
** t_dir types
*/

typedef	union			u_dir
{
	short				s;
	int					n;
}						t_dir;

# define SHORT_TDIR 1
# define NORMAL_TDIR 0

# define MAX_OP_ARGS 3

/*
** operation type macro
*/

# define LONG_OP	1
# define NORM_OP	0

/*
** register macro
*/

# define R_SRC		1
# define R_DST		0

typedef struct			s_op
{
	char				*name;
	int					argnum;
	char				arg_type[3];
	int					op_code;
	int					cycles;
	char				*description;
	t_bool				has_type_byte;
	t_bool				t_dir_size_type;
	void				(*exec_func)(t_process*);
}						t_op;

typedef short			t_ind;

extern t_op				g_op_tab[];

/*
** *****************************************
*/

typedef struct			s_check
{
	int					total_checks;
	int					max_checks;
	int					remain;
	int					lives;
}						t_check;

typedef struct			s_arena
{
	unsigned char		memory[MEM_SIZE];
	t_bool				game_run;
	int					last_live_player;
	int					players_nb;
	int					cycles_to_die;
	int					cycles_nb;
	int					lives_performed;
	t_check				check;
	int					check_nb;
	int					pnum;
	t_process			*processes;

}						t_arena;

extern t_arena			g_arena;

/*
** helper defines
** FGV stands for free global variable
*/

# define MEXIT perror("error");exit(EXIT_FAILURE)

# define FG free_all()

# define SAFE(x) if (!(x)){FG;MEXIT;}

/*
** this define designed to red from memory
** is ops > MEM_SIZE return from the begining
*/

# define M(pos) (pos < 0 ? (MEM_SIZE + ((pos) % MEM_SIZE)) : ((pos) % MEM_SIZE))

/*
** ****************** function definitions **************************
*/

/*
** free
*/

void					free_processes(void);
void					free_all(void);

/*
** header
*/

void					magic_header_error(char *file);
void					delimiter_error(char *file, char *befor_delimiter);
void					check_prog_size(char *file, int prog_size);
void					check_ex_code(int fd, char *file, int prog_size,
		int bytes_read);

/*
** input
*/

void					process_flags(int argc, char **argv);
void					add_order_flag(char **argv, int position);
void					add_dump_flag(char **argv, int position);
void					add_s_flag(char **argv, int position);
void					get_players_data(int argc, char **argv);
void					get_player_data(int fd, char *file);
void					reverse_bytes(void *add, size_t size);
void					invalid_dump_arg_err(char *arg);
void					invalid_dump_num(int n);
void					add_sm_d_flag(char **argv, int position);
/*
** helpers
*/

void					print_usage_and_exit(void);

/*
** vm
*/

void					run_vm(void);
void					endgame(void);

/*
** help.c
*/

void					print_players(void);
void					print_flags(void);
void					print_proccesses(void);
void					print_flags(void);

/*
** arena
*/

void					init_arena(void);
void					place_players(void);
void					introduce_players(void);
int						players_number(void);
void					mainloop(void);
void					perform_check(void);

/*
** processes
*/

void					init_processes(void);
void					push_process_front(int player_id, int pc);
void					exec_cycle(void);
void					pexec_inst(t_process *p);
t_process				*pdup(t_process *p);

/*
** instructions
*/

void					exec_live(t_process *p);
void					exec_ld(t_process *p);
void					exec_st(t_process *p);
void					exec_add(t_process *p);
void					exec_sub(t_process *p);
void					exec_and(t_process *p);
void					exec_or(t_process *p);
void					exec_xor(t_process *p);
void					exec_zjmp(t_process *p);
void					exec_ldi(t_process *p);
void					exec_sti(t_process *p);
void					exec_fork(t_process *p);
void					exec_lld(t_process *p);
void					exec_lldi(t_process *p);
void					exec_lfork(t_process *p);
void					exec_aff(t_process *p);

void					pload_op(t_process*p);

/*
**  mem
*/

t_dir					read_dir_val(int pc, int type);
t_ind					read_ind_val(t_process *p, int *offset, int type);

void					reverse_bytes(void *add, size_t size);
void					get_op_args(t_process *p, int args[2], int *pos,
		int reg_type);
void					write_into_reg(t_process *p, int r_num, int val,
		int cflag);
void					write_mem(t_process *p, int *reg, int addr,
		size_t size);
t_bool					check_operation(t_process *p, int t_dir_type,
		int *offset);
t_bool					is_valid_reg(int reg_num);

/*
** memory dumping
*/

void					dump_memory(int bytes_per_line);
void					manage_dump(void);

#endif
