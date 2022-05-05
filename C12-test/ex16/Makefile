NAME	= a.out
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
SRC		= main.c ft_sorted_list_insert.c
OBJ		= ${SRC:.c=.o}
RM		= rm -rf

all : ${NAME}

${NAME} : ${OBJ}
	${CC} -o $@ $^

.c.o :
	${CC} ${CFLAGS} -o $@ -c $<

.PHONY : all clean fclean re

clean :
	${RM} ${OBJ}

fclean : clean
	${RM} ${NAME}

re : fclean all
