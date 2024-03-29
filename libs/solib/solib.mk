# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    solib.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: almounib <almounib@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 15:34:37 by almounib          #+#    #+#              #
#    Updated: 2024/03/20 16:17:45 by almounib         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOLIB_PATH		= $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
SOLIB_HEAD 		= $(patsubst %/,%,$(SOLIB_PATH))/src/solib.h
SOLIB_HEADER		= $(patsubst %/,%,$(SOLIB_PATH))/solib.h
SOLIB_LIB 		= $(patsubst %/,%,$(SOLIB_PATH))/build/solib.a
MINILIBX_PATH	= $(patsubst %/,%,$(SOLIB_PATH))/libs/minilibx
MINILIBX_LIB 	= $(patsubst %/,%,$(SOLIB_PATH))/libs/minilibx/libmlx.a
SOLIB_DIR		=  $(patsubst %/,%,$(SOLIB_PATH))/src
SOLIB_BUILD_DIR	= $(patsubst %/,%,$(SOLIB_PATH))/build
SOLIB_BUILD_OBJ	= $(patsubst %/,%,$(SOLIB_PATH))/build/obj
SPECIFIED_SRC_DIRS	=	$(SOLIB_DIR)/hooks $(SOLIB_DIR)/solib_init $(SOLIB_DIR)/solib_keys \
						$(SOLIB_DIR)/solib_memory $(SOLIB_DIR)/time $(SOLIB_DIR)/solib_types \
						$(SOLIB_DIR)/ui $(SOLIB_DIR)/solib_init/init_utils $(SOLIB_DIR)/solib_types \
						$(SOLIB_DIR) $(SOLIB_DIR)/ui/canvas $(SOLIB_DIR)/ui/sprite $(SOLIB_DIR)/utils
#SOLIB_FILE		= $(wildcard $(SOLIB_DIR)/*.c) ./exemple/main_solib.c
SOLIB_FILE = $(foreach d,$(SPECIFIED_SRC_DIRS),$(wildcard $(addprefix $(d)/*,*.c))) ./exemple/exemple.c 
SOLIB_RE			= make -C $(SOLIB_PATH) re
SOLIB_OBJ = $(patsubst $(SOLIB_DIR)/%.c,$(SOLIB_BUILD_OBJ)/%.o, $(SOLIB_FILE) )