NAME = push_swap
OBJ_FILES = push_swap.o utilities.o
HEADER_FILES = push_swap.h
CFLAGS = -Wall -Werror -Wextra
INPUT = 3 2 1 0

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(MAKE) bonus -C ./libft
	$(CC) $(CFLAGS) $(OBJ_FILES) libft/libft.a -o $(NAME)

%.o: %.c $(HEADER_FILES)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJ_FILES)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all

bonus: all

run: all
	./$(NAME) $(INPUT)
	@echo "Checker:"
	@./$(NAME) $(INPUT) | ./checker_Mac $(INPUT)

.PHONY: all clean fclean re bonus run
