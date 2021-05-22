NAME = push_swap
OBJ_FILES = 
HEADER_FILES = push_swap.h
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJ_FILES)

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
	$(CC) $(CFLAGS) $(NAME) main.c -o a.out && ./a.out

.PHONY: all clean fclean re bonus run
