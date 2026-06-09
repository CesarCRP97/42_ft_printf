NAME = libftprintf.a
LIBFT = libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
RM = rm -rf

HEADERS = libft.h

SRC = ft_printf.c \
	ft_print_words.c \
	ft_print_numbers.c \

OBJ = $(SRC:.c=.o)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJ)

$(LIBFT):
	$(MAKE) -C libft

clean:
	$(RM) $(OBJ)
	$(MAKE) -C libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
