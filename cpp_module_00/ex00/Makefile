SRCS		=	megaphone.cpp

OBJS		=	${SRCS:.cpp=.o}

NAME		=	megaphone

CC			=	c++

WFLAGS		=	-Wall -Wextra -Werror

all:			${NAME}

${NAME}:		${OBJS}
				${CC} ${WFLAGS} ${OBJS} -o ${NAME}
			
clean:
				rm -f ${OBJS} 

fclean:			clean
				rm -f ${NAME}

re:				fclean all

.PHONY:			all clean fclean re
