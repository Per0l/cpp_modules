SRCS		=	main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp

OBJS		=	${SRCS:.cpp=.o}

NAME		=	animals

CC			=	c++

CFLAGS		=	-Wall -Wextra -Werror -std=c++98 -pedantic -fsanitize=address -g

%.o: %.cpp
				$(CC) $(CFLAGS) $< -c -o ${<:.cpp=.o}

all:			${NAME}

${NAME}:		${OBJS}
				${CC} ${CFLAGS} ${OBJS} -o ${NAME}
			
clean:
				rm -f ${OBJS} 

fclean:			clean
				rm -f ${NAME}

re:				fclean all

.PHONY:			all clean fclean re
