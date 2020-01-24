NAME = corewar

####################### vm source files ########################

SRCS :=		main/main.c main/arena.c main/op.c \
			\
			\
			input/flags.c \
			\
			input/flag_list/order_flag.c \
			input/flag_list/dump_flag.c \
			input/flag_list/s_flag.c \
			\
			input/get_players_data.c \
			\
			input/player_data/get_player_data.c \
			input/player_data/get_player_data_errors.c \
			input/flag_list/add_sm_d_flag.c \
			\
			arena/run_vm.c \
			arena/init.c \
			arena/process.c \
			arena/check.c \
			\
			arena/init_arena/place_players.c \
			arena/init_arena/introduce_players.c \
			arena/init_arena/init_processes.c\
			\
			mainloop/exec_cycle.c \
			mainloop/mainloop.c \
			mainloop/endgame.c \
			\
			visual/arena/print_arena.c \
			visual/arena/render_pcursors.c \
			visual/arena/init_arena.c \
			visual/arena/destroy_cursor.c \
			\
			visual/sider/main/init_sider.c \
			visual/sider/main/progress_bar.c \
			\
			visual/sider/gstate/render_gstate.c \
			visual/sider/gstate/gstate_parts.c \
			visual/sider/gstate/indicators.c \
			\
			visual/sider/players/players.c \
			visual/sider/players/chatbox.c \
			\
			visual/main/init.c \
			visual/main/screesn.c \
			visual/main/print_frame.c \
			visual/main/mods.c \
			visual/main/usage.c \
			visual/main/anounce_winner.c \
			visual/main/vfree.c \
			\
			instructions/inst.c \
			\
			instructions/list/exec_live.c \
			instructions/list/exec_add.c \
			instructions/list/exec_aff.c \
			instructions/list/exec_and.c \
			instructions/list/exec_fork.c \
			instructions/list/exec_ld.c \
			instructions/list/exec_ldi.c \
			instructions/list/exec_lfork.c \
			instructions/list/exec_lld.c \
			instructions/list/exec_lldi.c \
			instructions/list/exec_or.c \
			instructions/list/exec_st.c \
			instructions/list/exec_sti.c \
			instructions/list/exec_sub.c \
			instructions/list/exec_xor.c \
			instructions/list/exec_zjmp.c \
			\
			instructions/tools/read_mem.c \
			instructions/tools/check_op.c \
			instructions/tools/tools.c \
			\
			dump/dump.c \
			dump/memory_dump.c



####################### vm object files ########################

OBJS_DIR := .objs

OBJS := $(SRCS:%.c=$(OBJS_DIR)/%.o)

###################### headers ###########################

INCLUDES_DIR := ../../includes

HEADER_FILES := vm.h vm_visu.h op.h

INCLUDES := $(addprefix $(INCLUDES_DIR)/, $(HEADER_FILES))

#################### libft ##################################

LIBFT_DIR := ../../libft

LIBFT_NAME := libft.a

LIBFT_SUFF = ft

LIBFT = $(LIBFT_DIR)/$(LIBFT_NAME)

LIBFT_INCLUDES_DIR := ../../libft/includes

LIBDT_INCLUDES_FLAGS := $(addprefix -I, $(LIBFT_INCLUDES_DIR))

###################### ncurses #################################

NCURSES_SUFF = ncurses

###################### compiler info #############################

CC := gcc

CC_FLAGS := -Wall -Wextra -Werror -O3

DEBUG_FLAG := #-g #uncomment to use debugging flags in compilation

INCLUDES_FLAGS := $(addprefix -I, $(INCLUDES_DIR)) $(LIBDT_INCLUDES_FLAGS)

LINKING_FLAGS := -L $(LIBFT_DIR) -l $(LIBFT_SUFF) -l $(NCURSES_SUFF) -l termcap

#################################################################
#							rules
#################################################################

all: $(NAME)

$(NAME): $(OBJS) | $(LIBFT)
	$(CC) $(OBJS) $(LINKING_FLAGS) -o $(NAME)

$(OBJS_DIR)/%.o : %.c $(INCLUDES)
	@mkdir -p $(dir $@)
	$(CC) $(CC_FLAGS) -c $< -o $@ $(INCLUDES_FLAGS) $(DEBUG_FLAG)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

fclean_libs:
	make fcelan -C $(LIBFT_DIR)

re: fclean all

.PHONY: clean fclean re all fclean_libs $(LIBFT)
