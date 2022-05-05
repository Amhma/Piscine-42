NAME	= do-op
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
SRC		= srcs/calculator.c srcs/function.c srcs/main.c srcs/operation.c
OBJ		= $(SRC:.c=.o)
RM		= rm -f
INC		= -I includes/

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) -o $@ $^

.c.o :
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

.PHONY : all clean fclean re

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all
