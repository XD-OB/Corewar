# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obelouch <OB-96@hotmail.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/24 04:59:45 by obelouch          #+#    #+#              #
#    Updated: 2020/01/27 01:06:46 by obelouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

YELLOW = \033[1;33m
CYAN = \033[1;36m
RED = \033[1;31m
GREEN = \033[1;32m
EOC = \033[1;0m

NAME = asm

CC = gcc

FLAGS = -Wall -Wextra -Werror -O3

ASM = main init free fill_optab fill_optab_p1 fill_optab_p2 fill_optab_p3\
	  fill_bin get_insts_values get_instructs get_name_cmt get_instructs_bin\
	  write_inst_low inst_error is_aloneinst write_exec_code write_cor write_s\
	  write_advinfos write_stdout write_stdout_bin fill_args_atc check_args\
	  treate_file exit1 exit2 tools1 tools2 tools3 types1 types2 add_inst\
	  save_options file_save_chr replace_label write_tools split_labels\

SRC = $(addprefix srcs/, $(addsuffix .c, $(ASM)))

OBJ = $(addprefix srcs/, $(addsuffix .o, $(ASM)))

ASM_HEAD = ../../includes/asm.h

LIB_DIR = ../../libft

all : $(NAME)

$(NAME) : $(OBJ)
	make -C $(LIB_DIR)
	$(CC) -o $(NAME) $(OBJ) -L $(LIB_DIR) -lft

$(OBJ) :	srcs/%.o : srcs/%.c $(ASM_HEAD)
	$(CC) -c $< $(FLAGS) -o $@ -I ../../includes -I $(LIB_DIR)/includes

clean :
	/bin/rm -f $(OBJ)
	make -C $(LIB_DIR) clean

fclean : clean
	/bin/rm -f $(NAME)
	make -C $(LIB_DIR) fclean

re: fclean all
