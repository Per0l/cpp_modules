SRCS		=	main.cpp Zombie.cpp randomChump.cpp newZombie.cpp

OBJS		=	${SRCS:.cpp=.o}

NAME		=	zombie

CC			=	c++

CFLAGS		=	-Wall -Wextra -Werror -std=c++98 -pedantic

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
