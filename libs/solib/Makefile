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
CFLAG		= -Wall -Wextra -Werror -g3 -gdwarf-4
AR			= ar rc
LIB			= ranlib
MINILIBX    = libs/minilibx
LDFLAGS 	= -L./minilibx-linux -lX11 -lXext
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
	@echo $(SOLIB_OBJ)
	${AR} $(SOLIB_BUILD_DIR)/${NAME}.a ${SOLIB_OBJ}
			${LIB} $(SOLIB_BUILD_DIR)/${NAME}.a
	@$(CC) $(SOLIB_OBJ) -o $(SOLIB_BUILD_DIR)/$(NAME) $(CFLAG) $(LDFLAGS) $(MINILIBX)/libmlx.a
	@clear

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

minlibx :
	@git clone https://github.com/42Paris/minilibx-linux.git $(MINILIBX)
	make -C ./libs/minilibx re
	clear
	
cleanlib :
	@rm -rf minilibx-linux

re: fclean all clear 

.PHONY: all clean fclean re