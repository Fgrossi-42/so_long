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

BLU			= \033[0;34m
GRN			= \033[0;32m
RED			= \033[0;31m
PUR			= \033[0;35m
YLW			= \033[0;33m
RST			= \033[0m
END			= \e[0m

NAME		= so_long

FILES = so_long map_utils get_next_line ft_split \
				move_utils monster_moves map_utils2 \
				so_long_utils so_long_utils2\

PROJECT_H	= ./Incl/so_long.h
OBJS		= $(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

SRCS_DIR = Src/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = Src/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

CC			= gcc
CC_FLAGS	= -Wall -Werror -Wextra
MLX         =   libmlx.dylib
LIBFT       =   libft/libft.a
FT_PRINTF   =   ft_printf/libftprintf.a

$(OBJS_DIR)%.o : %.c $(PROJECT_H)
	@mkdir -p $(OBJS_DIR)src
	@$(CC) $(CC_FLAGS) -c $< -o $@
	@printf	"\033[2K\r${GRN}[COMPILING]${RST} '$<' $(END)\n"

$(NAME): $(OBJECTS_PREFIXED)
	@make -s -C ./libft
	@printf "\033[2K\r${PUR}[CREATED]\033[0m $(LIBFT)$(END)\n"
	@make -s -C ./mlx
	@printf "\033[2K\r${PUR}[CREATED]\033[0m $(MLX)$(END)\n"
	@make -s -C ./ft_printf
	@printf "\033[2K\r${PUR}[CREATED]\033[0m $(FT_PRINTF)$(END)\n"
	@$(CC) -o $(NAME) $(OBJECTS_PREFIXED) $(CC_FLAGS) $(MLX) $(LIBFT) $(FT_PRINTF)
	@printf "\033[2K\r${PUR}[CREATED]\033[0m $(NAME)$(END)\n"

all: $(NAME)

clean:
	@make clean -s -C libft
	@printf "\033[2K\r${YLW}[CLEAN]${RST} $(LIBFT)done$(END)\n"
	@make clean -s -C ft_printf
	@printf "\033[2K\r${YLW}[CLEAN]${RST} $(FT_PRINTF)done$(END)\n"
	@rm -rf $(addprefix $(OBJS_DIR), $(SRCS_DIR))
	@printf "\033[2K\r${YLW}[CLEAN]${RST} done$(END)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "\033[2K\r${RED}[DESTROYED]${RST} $(NAME)$(END)\n"

fclean.all: fclean
			@make fclean -s -C libft
			@make clean -s -C mlx
			@make fclean -s -C ft_printf
			@printf "\033[2K\r${RED}[CLEANED]${RST} $(LIBFT)$(END)\n"
			@printf "\033[2K\r${RED}[CLEANED]${RST} $(FT_PRINTF)$(END)\n"
			@printf "\033[2K\r${RED}[CLEANED]${RST} $(MLX)$(END)\n"

re: fclean all

.PHONY:		all clean fclean re
