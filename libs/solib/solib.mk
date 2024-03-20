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
SOLIB_DIR		=  ./src
SOLIB_BUILD_DIR	= build
SOLIB_BUILD_OBJ	= build/obj
SPECIFIED_SRC_DIRS	=	$(SOLIB_DIR)/solib_hooks $(SOLIB_DIR)/solib_init $(SOLIB_DIR)/solib_keys \
						$(SOLIB_DIR)/solib_memory $(SOLIB_DIR)/solib_time $(SOLIB_DIR)/solib_types \
						$(SOLIB_DIR)/solib_ui $(SOLIB_DIR)/solib_init/init_utils $(SOLIB_DIR)/solib_types \
#SOLIB_FILE		= $(wildcard $(SOLIB_DIR)/*.c) ./exemple/main_solib.c
SOLIB_FILE = $(foreach d,$(SPECIFIED_SRC_DIRS),$(wildcard $(addprefix $(d)/*,*.c))) exemple/main_solib.c
SOLIB_RE			= make -C $(SOLIB_PATH) re
SOLIB_OBJ = $(patsubst $(SOLIB_DIR)/%.c,$(SOLIB_BUILD_OBJ)/%.o, $(SOLIB_FILE) )