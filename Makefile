NAME = push_swap checker
O_UNIVERSAL = utilities_general.o utilities_setup.o swap.o push.o rotate.o \
	reverse_rotate.o
O_PUSH_SWAP = push_swap.o push_swap_utils.o $(O_UNIVERSAL)
O_CHECKER = checker.o checker_utils.o get_next_line/get_next_line.o \
	get_next_line/get_next_line_utils.o $(O_UNIVERSAL)
HEADER_FILES = universal_stacks.h push_swap.h checker.h
CFLAGS = -Wall -Werror -Wextra
INPUT = 3 2 1 0

all: $(NAME)

$(word 1, $(NAME)): $(O_PUSH_SWAP)
	$(MAKE) bonus -C ./libft
	$(CC) $(CFLAGS) $(O_PUSH_SWAP) libft/libft.a -o push_swap

%.o: %.c $(HEADER_FILES)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	$(MAKE) clean -C ./libft
	rm -f $(O_PUSH_SWAP) $(O_CHECKER)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all

bonus: checker

$(word 2, $(NAME)): $(O_CHECKER)
	$(MAKE) bonus -C ./libft
	$(CC) $(CFLAGS) $(O_CHECKER) libft/libft.a -o checker

run: all
	./push_swap $(INPUT)
	@echo "Checker:"
	@./push_swap $(INPUT) | ./checker_Mac $(INPUT)

.PHONY: all clean fclean re bonus run
