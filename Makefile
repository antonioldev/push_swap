NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.$(DEPS)
SRC = 	main.c ft_*.c
OBJ = $(SRC:.c=.o)
DEPS = pushswap.h

RM = rm -f

all: $(NAME)

test:
	cc -g main.c ft_*.c
	$(RM) $(OBJ)

$(NAME) : $(OBJ) 
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ) : $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
