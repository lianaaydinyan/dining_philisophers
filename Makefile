NAME= philo
SRC= src/philo.c src/treadHelpers.c src/helpers.c src/parsing.c \
		src/checking.c  src/errorManagment.c src/mutexHelpers.c
OBJ= $(SRC:src/%.c=obj/%.o)
CC=cc
CFLAGS=-Wall -Werror -Wextra #-fsanitize=thread -pthread -g
RM=rm -rf

LIBFT=libft/libft.a

all: lobi creat_directory $(NAME) $(OBJ) Makefile

HEADER = philo.h

lobi:
	@make -C libft

creat_directory:
	mkdir -p obj

obj/%.o : src/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ) Makefile
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	@make -C libft clean
	$(RM) obj

fclean: clean
	@make -C libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean clean all
