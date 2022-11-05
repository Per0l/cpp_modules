SRCS		=	main.cpp ClapTrap.cpp ScavTrap.cpp

OBJS		=	${SRCS:.cpp=.o}

NAME		=	claptrap

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
