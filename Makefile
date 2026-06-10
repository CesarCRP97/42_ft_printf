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
	ft_print_pointers.c \

OBJ = $(SRC:.c=.o)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@cp $(LIBFT) $(NAME)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJ)

$(LIBFT):
	@echo "\nAction: Compiling ... \n"
	@$(MAKE) -C libft
	@echo "\nSuccess: Compilation completed! \n"

clean:
	@$(RM) $(OBJ)
	@$(MAKE) -C libft clean

fclean:
	@echo "\nAction: Removing all .o files and libft.a \n"
	@$(RM) $(OBJ)
	@$(RM) $(NAME)
	@$(RM) tests
	@$(MAKE) -C libft fclean
	@echo "\nSuccess: All files cleaned \n"

re: fclean all

tests: re
	@echo "\nAction: Compiling tests ... \n"
	@$(CC) $(CFLAGS) -o tests main.c libftprintf.a
	./tests

.PHONY: all clean fclean re
