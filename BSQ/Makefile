NAME	= bsq
CC		= clang
CFLAGS	= -Wall -Wextra -Werror
SRC		= srcs/verif.c srcs/main.c srcs/function.c srcs/function2.c srcs/list.c srcs/malloc.c srcs/resolve.c srcs/rsa.c
INC		= -I includes
OBJ		= ${SRC:.c=.o}
RM		= rm -rf

all : ${NAME}

${NAME} : ${OBJ}
	${CC} -o $@ $^

.c.o :
	${CC} ${CFLAGS} $(INC) -o $@ -c $<

.PHONY : all clean fclean re

clean :
	${RM} ${OBJ}

fclean : clean
	${RM} ${NAME}

re : fclean all
