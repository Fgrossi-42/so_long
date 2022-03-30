NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

FILES =	ft_memset \
		ft_bzero \
		ft_memmove \
		ft_calloc \
		ft_memcpy \
		ft_strdup \
		ft_memchr \
		ft_putstr_fd \
		ft_putendl_fd \
		ft_putchar_fd \
		ft_putnbr_fd \
		ft_strlen \
		ft_strlcpy \
		ft_strlcat \
		ft_strncmp \
		ft_memcmp \
		ft_striteri \
		ft_strnstr \
		ft_strmapi \
		ft_atoi \
		ft_strchr \
		ft_strjoin \
		ft_isalpha \
		ft_isdigit \
		ft_isalnum \
		ft_isascii \
		ft_isprint \
		ft_itoa \
		ft_strtrim \
		ft_substr \
		ft_toupper \
		ft_strrchr \
		ft_tolower \

FILES_B=ft_lstadd_front \
		ft_lstadd_back \
		ft_lstclear \
		ft_lstdelone \
		ft_lstiter \
		ft_lstlast \
		ft_lstmap \
		ft_lstnew \
		ft_lstsize \

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
SRCS_B = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES_B)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
OBJS_B = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES_B)))


.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(AR) $@ $^

bonus: $(OBJS_B)
	ar rcs $(NAME) $(OBJS_B)

all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: bonus all clean fclean re