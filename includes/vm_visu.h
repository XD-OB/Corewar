/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_visu.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishaimou <ishaimou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 18:03:07 by aaguert           #+#    #+#             */
/*   Updated: 2020/01/24 00:05:54 by ishaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_VISU_H
# define VM_VISU_H

# include "op.h"
# include "vm.h"
# include <time.h>
# include <ncurses.h>
# include <termcap.h>

# define MIN(a, b) (a < b ? a : b)

/*
** ******************* ARENA *********************
** _______________________________________________
*/

# define BYTES_PER_LINE 64

# define TO_HEX_F(n) (n * 2 + n - 1)

# define H_PADDING 2
# define V_PADDING 1

# define ARENA_WIDTH (TO_HEX_F(BYTES_PER_LINE) + 2 * H_PADDING + 2)
# define ARENA_HEIGHT ((MEM_SIZE / BYTES_PER_LINE) + 2 + 2 * V_PADDING)

# define ARENA_ROW 5
# define ARENA_COL 80

/*
** input_keys
*/

# define PAUSE_KEY ' '
# define NEXT_KEY 'n'
# define NEXT_KEY2 KEY_ENTER
# define SPEED_UP_KEY KEY_RIGHT
# define SPEED_DOWN_KEY KEY_LEFT
# define QUIT_KEY 'q'

/*
** .
*/

enum	e_colors
{
	NO_COLOR = -1,
	DEFULT_COLOR,
	P1COLOR,
	P2COLOR,
	P3COLOR,
	P4COLOR,
	WRCOLOR,
	WWCOLOR,
	GBCOLOR,
	RBCOLOR,
	BLBCOLOR,
	YBCOLOR
};

typedef struct	s_siders
{
	WINDOW		*player[MAX_PLAYERS + 1];
	WINDOW		*gstate;
	WINDOW		*chatbox;
}				t_siders;

# define MAX_COMMENTS 5

typedef struct	s_comment
{
	int			plid;
	char		*comment;
}				t_comments;

typedef	struct	s_game
{
	t_bool		paused;
	t_bool		canjump;
	t_comments	comments[MAX_COMMENTS];
	int			speed;
}				t_game;

/*
** speed settings
*/

# define MAX_SPEED 7
# define MIN_SPEED 1
# define INIT_SPEED 2
# define SPEED_SCALE 8

/*
** **
*/

typedef struct	s_vis
{
	WINDOW		*arena;
	WINDOW		*usage;
	t_siders	siders;
	t_game		game;
}				t_vis;

extern t_vis	g_vis;

typedef struct	s_progbar_state
{
	int		width;
	int		attrs;
	int		battrs;
	double	progress;
}				t_progbar_state;

/*
** ***************** GSTATE **********************
** ______________________________________________
*/

# define GSTATE_WIDTH 160
# define GSTATE_HEIGHT (ARENA_HEIGHT )
# define GSTATE_COL (ARENA_COL + ARENA_WIDTH)
# define GSTATE_ROW ARENA_ROW

# define WORDS_COL 6
# define LINEHEIGHT 2
# define BASE_LINE 1
# define SL(x) (BASE_LINE + x * LINEHEIGHT)

# define SLD_WIDTH 35

/*
** ***************** PLAYER BOX **********************
*/

# define PB_WIDTH 40
# define PB_HEIGHT (ARENA_HEIGHT / 7)
# define PB_L_HIGHT 2

# define PB_RESF_ROW ARENA_ROW
# define PB_RESF_COL (ARENA_COL - (PB_WIDTH + 10))

/*
** *********************************************************
*/

# define BOX_MMNB MAX_COMMENTS
# define THIGHT 4

# define BOX_ROW (ARENA_ROW + (0.6) * ARENA_HEIGHT)
# define BOX_COL (PB_RESF_COL - 2)
# define BOX_WIDTH	(PB_WIDTH + 4)
# define BOX_HEIGHT (BOX_MMNB * 3)

# define FIRST_COM_ROW (BOX_HEIGHT - 3)
# define COMS_COL 2

/*
** ****************** usage *********************
*/

# define USAGE_ROW (ARENA_ROW + ARENA_HEIGHT + 1)
# define USAGE_COL (ARENA_COL + 20)
# define USAGE_WIDTH ARENA_WIDTH
# define USAGE_HEIGHT 50

/*
** **
*/

void			vinit_arena();
void			load_arena();
void			paint_players();
void			print_arena();
void			init_vis();
void			render_rc_byte(WINDOW *arena, int row, int col,
															unsigned int attr);
void			render_byte(WINDOW *arena, int pos, unsigned int attr);
void			render_pcursors();
void			destroy_cursor(t_process *p);
chtype			get_byte_color(int pos);
chtype			get_byte_attrs(int pos);

void			init_siders(void);
void			init_players();
void			refresh_players(void);
void			render_players_info();
void			init_chat_box(void);
void			render_comments();
void			add_comment(int plid, char *cmt);

void			print_frame();
void			render_gstate();
void			progbar(WINDOW *win, int row, int col, t_progbar_state state);
t_progbar_state	get_pb_state(int width, double progress, int attrs, int battrs);
void			speed_pb(WINDOW *win, int row, int col, t_progbar_state state);
void			render_top_infos();
void			render_important_info();
void			render_indicated_data();

void			g_flow();
void			catch_speed_keys(int c);
void			handle_time_flow();

void			init_usage(void);

void			v_anounce_winner(void);
void			vfree_comments();

#endif
