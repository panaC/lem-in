# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pierre <pleroux@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/11 13:59:37 by pierre            #+#    #+#              #
#    Updated: 2018/05/09 16:26:09 by pleroux          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DBG=-ggdb -fsanitize=address -fno-omit-frame-pointer -g3
DBG2=-ggdb  -fsanitize=address -fsanitize-memory-track-origins

NAME = lem-in
CC = gcc
LIB_PRINTF = ft_printf/libftprintf.a
LIB_PRINTF_PATH = ft_printf/
LIB_PRINTF_HEADER = ft_printf/inc
LIB_PRINTF_LINK = ftprintf
LIB = libft/libft.a
LIB_PATH = libft/
LIB_HEADER = libft/includes
LIB_LINK = ft
CFLAGS = -Wall -Werror -Wextra -I $(LIB_HEADER) -I $(LIB_PRINTF_HEADER)
LIB_FLAGS = -L$(LIB_PATH) -l$(LIB_LINK) \
			-L$(LIB_PRINTF_PATH) -l$(LIB_PRINTF_LINK)
SRC_DIR = src/
INC_FILE = algo.h \
		   lemin.h \
		   move.h \
		   parser.h \
		   room.h
SRC_FILE = algo.c \
		   init.c \
		   parser.c \
		   parser_tools.c \
		   algo_bfs.c \
		   main.c \
		   parser_handle.c \
		   room.c \
		   algo_tools.c \
		   move.c \
		   parser_pipe.c \
		   room_cmp.c \
		   free.c \
		   move_node.c \
		   parser_room.c \
		   room_set.c
SRC = $(addprefix $(SRC_DIR), $(SRC_FILE))
INC = $(addprefix $(SRC_DIR), $(INC_FILE))
OBJ = $(SRC:.c=.o)

all		: $(LIB) $(LIB_PRINTF) $(NAME)

$(LIB)	:
	make -C $(LIB_PATH)

$(LIB_PRINTF)	:
	make -C $(LIB_PRINTF_PATH)

%.o: %.c $(INC)
	     $(CC) $(CFLAGS) -o $@ -c $<

$(NAME)	: $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIB_FLAGS)

clean	:
	rm -f $(OBJ)
	make -C $(LIB_PATH) fclean
	make -C $(LIB_PRINTF_PATH) fclean

fclean	: clean
	rm -f $(NAME)

re		: clean all

.PHONY	: all clean re fclean $(LIB) $(LIB_PRINTF)
