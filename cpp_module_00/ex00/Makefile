SRCS		=	megaphone.cpp

OBJS		=	${SRCS:.cpp=.o}

NAME		=	megaphone

CC			=	c++

WFLAGS		=	-Wall -Wextra -Werror -std=c++98 -pedantic

all:			${NAME}

${NAME}:		${OBJS}
				${CC} ${WFLAGS} ${OBJS} -o ${NAME}
			
clean:
				rm -f ${OBJS} 

fclean:			clean
				rm -f ${NAME}

re:				fclean all

.PHONY:			all clean fclean re
