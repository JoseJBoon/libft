NAME = libft.a
PROGRAM = libft
CC = cc
CFLAGS = -Wall -Werror -Wextra -std=c99
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
SRCS_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
BIN_DIR = ./bin/
DEP = libft.h
OBJS := $(SRCS:%.c=$(BIN_DIR)%.o)
OBJS_BONUS := $(SRCS_BONUS:%.c=$(BIN_DIR)%.o)

all: $(BIN_DIR) $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: all $(OBJS_BONUS)
	ar rcs $(NAME) $(OBJS_BONUS)

so: bonus
	gcc -shared -o libft.so $(OBJS) $(OBJS_BONUS)

build: all bonus
	$(CC) -c $(CFLAGS) tests/main.c -o $(BIN_DIR)main.o
	$(CC) -o $(PROGRAM) $(BIN_DIR)main.o $(NAME)

$(BIN_DIR)%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	rm -fv $(OBJS)
	rm -fv $(OBJS_BONUS)
	rm -fv $(BIN_DIR)main.o

fclean: clean
	rm -fv $(PROGRAM)
	rm -fv libft.so
	rm -fv $(NAME)
	rmdir $(BIN_DIR)

re: fclean all

.PHONY: all clean fclean re build bonus
