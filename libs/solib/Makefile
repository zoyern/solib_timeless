# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: almounib <almounib@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 15:35:42 by almounib          #+#    #+#              #
#    Updated: 2024/03/20 16:03:55 by almounib         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include solib.mk

NAME		= solib
CFLAG		= -Wall -Wextra -Werror -I$(SOLIB_DIR) -I$(MINILIBX_PATH) -g3 -gdwarf-4
AR			= ar rc
LIB			= ranlib
LDFLAGS 	= -L$(MINILIBX_PATH) -lmlx_Linux -lmlx -lX11 -lXext
CC			= cc

$(SOLIB_BUILD_DIR)/%.o: $(SOLIB_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC)	$(CFLAG) -c	$< -o $@
	@clear

$(SOLIB_BUILD_OBJ)/%.o: $(SOLIB_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC)	$(CFLAG) -c	$< -o $@
	@clear

all : $(NAME)

$(NAME): $(SOLIB_OBJ) 
	${AR} $(SOLIB_BUILD_DIR)/${NAME}.a ${SOLIB_OBJ} $(wildcard $(MINILIBX_PATH)/obj/*.o)
			${LIB} $(SOLIB_BUILD_DIR)/${NAME}.a
	@clear
	@$(CC) $(SOLIB_OBJ) -o $(SOLIB_BUILD_DIR)/$(NAME) $(CFLAG) $(LDFLAGS) $(SOLIB_LIB)

clear :
	@clear
	@echo "42Paris : $(NAME)"
	@echo ""

val :
	@clear
	valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --track-origins=yes ./$(NAME)
	@echo ""

clean : clear
	@rm -rf build/
	@echo "Clean   : *.o in build !"

fclean : clean
	@rm -f $(NAME)
	@echo "Clean   : ./$(NAME)"

aclean : fclean cleanlib clear

minilibx :
	@git clone https://github.com/42Paris/minilibx-linux.git libs/minilibx
	make -C libs/minilibx
	clear
	
cleanlib :
	@rm -rf minilibx-linux

re: fclean all clear 

.PHONY: all clean fclean re