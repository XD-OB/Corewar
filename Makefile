# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaguert <aaguert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 23:03:49 by ishaimou          #+#    #+#              #
#    Updated: 2020/01/22 20:55:05 by aaguert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

YELLOW = \033[1;33m
CYAN = \033[1;36m
RED = \033[1;31m
GREEN = \033[1;32m
EOC = \033[1;0m

ASSEMBLER_NAME := asm

ASSEMBLER_DIR := src/assembler

ASM := $(ASSEMBLER_DIR)/$(ASSEMBLER_NAME)

VM_NAME := corewar

VM_DIR := src/vm

VM := $(VM_DIR)/$(VM_NAME)


all: $(VM_NAME) $(ASSEMBLER_NAME)
	@echo "$(YELLOW)"
	@echo "  _________                                                    "
	@echo "  \_   ___ \   ____  _______   ____  __  _  _______   _______  "
	@echo "  /    \  \/  /  _ \ \_  __ \_/ __ \ \ \/ \/ /\__  \  \_  __ \ "
	@echo "  \     \____(  |_| ) |  | \/\  ___/  \     /  / __ \_ |  | \/ "
	@echo "   \______  / \____/  |__|    \___  >  \/\_/  (____  / |__|    "
	@echo "          \/                      \/               \/          "
	@echo "$(EOC)                         by:   $(GREEN)Memory-Rapists$(EOC)"
	@echo ""

$(ASSEMBLER_NAME):
	make -C $(ASSEMBLER_DIR) && cp $(ASM) .

$(VM_NAME):
	make -C $(VM_DIR) && cp $(VM) .

clean:
	make clean -C $(VM_DIR)
	make clean -C $(ASSEMBLER_DIR)
	@echo "$(YELLOW)Clean the Workspace$(EOC)"

fclean: clean
	@/bin/rm -f $(VM_NAME) $(ASSEMBLER_NAME)
	@make fclean -C $(VM_DIR)
	@make fclean -C $(ASSEMBLER_DIR)
	@echo "$(RED)Remove ./corewar ./asm$(EOC)"

re: fclean all

.PHONY: re fclean clean $(VM_NAME) $(ASSEMBLER_NAME)
