YELLOW = \033[1;33m
CYAN = \033[1;36m
RED = \033[1;31m
GREEN = \033[1;32m
EOC = \033[1;0m

NAME = asm

CC = gcc

FLAGS = -Wall -Wextra -Werror

ASM = main init_free fill_optab fill_optab_p1 fill_optab_p2 fill_optab_p3\
	  get_insts_values get_instructs get_name_cmt replace_label types\
	  tools exit inst_error type_inst add_inst write_exec_code write_cor\
	  write_advinfos write_stdout save_options delete_me\

SRC = $(addprefix srcs/, $(addsuffix .c, $(ASM)))

OBJ = $(addprefix srcs/, $(addsuffix .o, $(ASM)))

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C ./libft
	@$(CC) -o $(NAME) $(OBJ) -L ./libft -lft
	@echo "$(YELLOW)  __  _  __  $(RED) $(YELLOW)   _   __  __  ___  _   _  ___ _    ___  ___   "
	@echo "$(YELLOW) |  \| |/ _| $(RED)|$(YELLOW)  / \ / _|/ _|| __|| \_/ || o ) |  | __|| o \  "
	@echo "$(YELLOW) | o ) |\_ \ $(RED)|$(YELLOW) | o |\_ \|_ \| _| | \_/ || o \ |_ | _| |   /  "
	@echo "$(YELLOW) |__/|_||__/ $(RED)|$(YELLOW) |_n_||__/|__/|___||_| |_||___/___||___||_|\_\ "
	@echo "$(EOC)"
	@echo "   Assembler & Disassembler    by:$(GREEN) MEMORY-RAPISTS\n$(EOC)"

$(OBJ) :	srcs/%.o : srcs/%.c
	@$(CC) -c $< $(FLAGS) -o $@ -I ./includes

clean :
	@/bin/rm -f $(OBJ)
	@make -C ./libft clean
	@echo "$(YELLOW)Clean The Workspace$(EOC)"

fclean : clean
	@/bin/rm -f $(NAME)
	@make -C ./libft fclean
	@echo "$(RED)Totaly Cleaned ASM$(EOC)"

re: fclean all
