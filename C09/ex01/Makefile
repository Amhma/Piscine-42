NAME	= libft.a
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
SRC		= srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJ		= $(SRC:.c=.o)
RM		= rm -f
INC		= -I includes/

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $@ $^
	ranlib $@

.c.o :
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

.PHONY : all clean fclean re

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all
