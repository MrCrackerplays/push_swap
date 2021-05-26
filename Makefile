NAME = push_swap
OBJ_FILES = utilities.o
O_CHECKER = get_next_line/get_next_line.o \
	get_next_line/get_next_line_utils.o
HEADER_FILES = push_swap.h
CFLAGS = -Wall -Werror -Wextra
INPUT = 3 2 1 0

all: $(NAME)

$(NAME): $(OBJ_FILES) $(NAME).o
	$(MAKE) bonus -C ./libft
	$(CC) $(CFLAGS) $(OBJ_FILES) $(NAME).o libft/libft.a -o $(NAME)

%.o: %.c $(HEADER_FILES)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJ_FILES) $(O_CHECKER) $(NAME).o checker.o

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)
	rm -f checker

re: fclean all

bonus: checker all

checker: $(O_CHECKER) checker.o $(OBJ_FILES)
	$(MAKE) bonus -C ./libft
	$(CC) $(CFLAGS) $(OBJ_FILES) $(O_CHECKER) checker.o libft/libft.a -o checker

run: all
	./$(NAME) $(INPUT)
	@echo "Checker:"
	@./$(NAME) $(INPUT) | ./checker_Mac $(INPUT)

.PHONY: all clean fclean re bonus checker run
