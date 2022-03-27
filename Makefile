# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouhlel <abouhlel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/09 17:44:09 by bledda            #+#    #+#              #
#    Updated: 2022/03/27 18:45:11 by abouhlel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= so_long

#################### * F I L E S * #############################################
FOLDER_HEADER		= header/
FOLDER				= src/
FOLDER_B			= src_bonus/

HEADER_FILE 		= so_long.h

SRCS				= main.c \
						ft_define_img.c \
						ft_parsing.c \
						ft_push_key.c \
						ft_print_map.c \
						ft_camera.c \
						ft_game_over.c \
						ft_key_moves.c \
						ft_valid_map.c \

SRCS_B				= main_b.c \
						ft_define_img_b.c \
						ft_parsing_b.c \
						ft_push_key_b.c \
						ft_print_map_b.c \
						ft_camera_b.c \
						ft_game_over_b.c \
						ft_key_moves_b.c \
						ft_valid_map_b.c \

SRC					= $(addprefix ${FOLDER},${SRCS})
SRC_B				= $(addprefix ${FOLDER_B},${SRCS_B})
HEADERS				= $(addprefix ${FOLDER_HEADER},${HEADER_FILE})

OBJS				= ${SRC:.c=.o}
OBJS_B				= ${SRC_B:.c=.o}
################################################################################

#################### * C O M P I L A T I O N * #################################
CC					= gcc
CFLAGS  			= -Wall -Wextra -Werror
RM					= rm -rf
MAKE_EXT			= @make -s --no-print-directory -C

OBJ					= ${OBJS}
OBJ_B				= ${OBJS_B}

UNAME_S				= $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	LIBS 			= -L ./libft -lft -lmlx -lXext -lX11
endif
ifeq ($(UNAME_S),Darwin)
	LIBS 			= -L ./libft -lft -lmlx -framework OpenGL -framework AppKit -lz
endif

COMPIL		= $(CC) $(CFLAGS) ${OBJ} $(LIBS) -o $(NAME)
COMPIL_B	= $(CC) $(CFLAGS) ${OBJ_B} $(LIBS) -o $(NAME)
################################################################################

######################### * R U L E S * ########################################
$(NAME):	${OBJ}
			@printf $(blue)
			@printf "\n"
			@printf $(magenta)
			$(MAKE_EXT) ./libft
			@$(COMPIL)
			@printf $(reset)

all:		${NAME}

%.o: %.c	$(HEADERS)
			@printf $(yellow)
			@printf "Generating so_long objects... %-33.33s\r" $@
			@$(CC) -c $(CFLAGS) -o $@ $<
			@printf $(reset)

bonus : 	${OBJ_B}
			@printf $(blue)
			@printf " Generating bonus objects... %-33.33s                                 \r" $@
			@printf $(magenta)
			$(MAKE_EXT) ./libft
			@$(COMPIL_B)
			@printf "➖➖➖➖➖➖➖➖➖➖➖➖                         \n"
			@printf "🐷 BEWARE THE PIGS 🐷 \n"
			@printf "➖➖➖➖➖➖➖➖➖➖➖➖\n"
			@printf $(reset)

re: 		fclean all

clean:
			$(MAKE_EXT) ./libft clean
			@${RM} ${OBJ} ${OBJ_B}
			@printf $(magenta)
			@printf "Object files have been deleted 🚮\n"
			@printf $(reset)

fclean:		clean
			$(MAKE_EXT) ./libft fclean
			@${RM} $(NAME)
			@printf $(magenta)
			@printf "Your folder is now clean 🧹\n"
			@printf $(reset)

.PHONY: 	all clean fclean bonus re
#################################################################################

#################### * C O L O R *** S E T T I N G * ############################
black 				=	"[1;30m"
red 				=	"[1;31m"
green 				=	"[1;32m"
yellow 				=	"[1;33m"
blue 				=	"[1;34m"
magenta 			=	"[1;35m"
cyan 				=	"[1;36m"
white 				=	"[1;37m"

bg_black 			=	"[40m"
bg_red 				=	"[41m"
bg_green 			=	"[42m"
bg_yellow 			=	"[43m"
bg_blue 			=	"[44m"
bg_magenta 			=	"[45m"
bg_cyan 			=	"[46m"
bg_white 			=	"[47m"

reset 				=	"[0m"

#################################################################################
#                                                                               #
#                   ##                                             #####        #
#                   ##                                             #            #
#                   ##                                           #######        #
#                   ##                                              ##          #
#       #####       ##          ####           #    #    #          ##          #
#       #           ##         #    #          #    #    #          ##          #
#     ########      ########################### #### ####           ##          #
#                                                                               #
#################################################################################