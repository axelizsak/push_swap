# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aizsak <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/10 12:41:39 by aizsak            #+#    #+#              #
#    Updated: 2023/02/08 13:29:54 by aizsak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIRSRC		= ./srcs/

DIRINC		= ./includes/

DIRLIB		= ./libft/

DIROBJ		= ./objs/

SRC			= cmd1 cmd2 utils utils1 main parsing sorting sorting_for_n 

SRCS		= $(addprefix ${DIRSRC}, $(addsuffix .c, ${SRC}))

HEAD		= ./includes/

OBJS		= ${SRCS:.c=.o}

NAME		= push_swap.a

NAMELFT		= libft.a

CC			= gcc
RM			= rm -f
AR			= ar rc
RN			= ranlib

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c -I${DIRINC} -I${DIRLIB} $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			cd ${DIRLIB} && ${MAKE} && cp -v ${NAMELFT} ../${NAME}
			${AR} ${NAME} ${OBJS}
			${RN} ${NAME}

main:		${NAME}
			${CC} -I ${DIRINC} -I ${DIRLIB} ${NAME} main.c
all:		$(NAME)

clean:
			${RM} ${OBJS}
			cd ${DIRLIB} && ${MAKE} clean

fclean:		clean
			${RM} $(NAME)
			cd ${DIRLIB} && ${MAKE} fclean

re:		fclean all

.PHONY:		all clean fclean re
