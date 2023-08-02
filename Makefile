# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dferjul <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/08 21:01:48 by dferjul           #+#    #+#              #
#    Updated: 2023/08/02 01:48:46 by dferjul          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	main.c \
			src/parsing.c \
			src/check_error.c \
			src/check_error_bis.c \
			src/picture_utils.c \
			src/player.c \
			src/player_collect_and_exit.c \
			src/resolve_map.c \
			Get_next_line/get_next_line.c \
			Get_next_line/get_next_line_utils.c \
			printf/ft_flags.c \
			printf/ft_printf_tools_bis.c \
			printf/ft_printf_tools.c \
			printf/ft_printf.c \
			libft/ft_strlen.c \

OBJ_DIR = obj_o

# Extraire les noms de dossiers à partir de la variable SRCS #
DIRS := $(sort $(dir $(SRCS)))

OBJS	=	$(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

CC	=	gcc

CFLAGS	=	-g -Wall -Wextra -Werror

RM	=	rm -rf

NAME	=	so_long

MAC_MLX	=	-L/usr/X11/lib -lmlx -lX11 -lXext

# Règle pour compiler les fichiers .c en fichiers .o #
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

#---------------------rules---------------------#

all : $(NAME)

$(NAME) : $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(MAC_MLX) -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)
	$(RM) $(OBJ_DIR)

re : fclean all

.PHONY : all so_long.a clean fclean re