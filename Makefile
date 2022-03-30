# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgrossi <fgrossi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 10:01:06 by fgrossi           #+#    #+#              #
#    Updated: 2022/03/30 13:18:16 by fgrossi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        =   so_long

SRC         =   so_long.c map_utils.c get_next_line.c ft_split.c \
				move_utils.c monster_moves.c map_utils2.c \
				so_long_utils.c so_long_utils2.c\

OBJ         =   $(SRC:.c=.o)

MLX         =   ./libmlx.dylib

LIBFT       =   libft/libft.a

FT_PRINTF   =   ft_printf/libftprintf.a

CC          =   gcc

RM          =   rm -f

CFLAGS      =   -Wall -Wextra -Werror

$(NAME):    $(OBJ)
			make -C ./libft
			make -C ./mlx
			make -C ./ft_printf
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -g $(MLX) $(LIBFT) $(FT_PRINTF)
			
all:        $(NAME)

clean:
			${RM} $(OBJ)
			
fclean:		clean
			${RM} $(NAME) ${OBJ}
			
fclean.all: fclean
			make fclean -C libft
			make clean -C mlx
			make fclean -C ft_printf
			
re:         fclean all

re.all:     fclean

.PHONY:     all clean fclean re