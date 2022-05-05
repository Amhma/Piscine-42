NAME = rush-02

all : $(NAME)

$(NAME) : main.o verif.o function1.o function2.o function3.o conversion2.o conversion.o
	gcc -o $(NAME) main.o verif.o function1.o function2.o function3.o conversion2.o conversion.o

main.o : main.c
	gcc -Wall -Werror -Wextra -o main.o -c main.c

verif.o : verif.c
	gcc -Wall -Werror -Wextra -o verif.o -c verif.c

function1.o : function1.c
	gcc -Wall -Werror -Wextra -o function1.o -c function1.c

function2.o : function2.c
	gcc -Wall -Werror -Wextra -o function2.o -c function2.c

function3.o : function3.c
	gcc -Wall -Werror -Wextra -o function3.o -c function3.c

conversion.o : conversion.c
	gcc -Wall -Werror -Wextra -o conversion.o -c conversion.c

conversion2.o : conversion2.c
	gcc -Wall -Werror -Wextra -o conversion2.o -c conversion2.c


.PHONY : all clean fclean re

clean :
	rm -f main.o verif.o function1.o function2.o function3.o conversion2.o conversion.o

fclean : clean
	rm -f $(NAME)

re : fclean all
