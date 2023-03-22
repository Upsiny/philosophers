# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hguillau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 15:56:20 by hguillau          #+#    #+#              #
#    Updated: 2023/03/22 11:47:57 by hguillau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    	=		main.c						\
					philo.c						\
					philo_utils.c				\
					routine.c					\

OBJS    	=		${SRCS:.c=.o}

NAME    	=		philosophers

CC      	=		gcc

RM      	=		rm -f

CFLAGS  	=		-Wall -Wextra -Werror -pthread #-g -fsanitize=thread

all:				${NAME}

${NAME}:			${OBJS}
					${CC} ${CFLAGS} -o ${NAME} ${OBJS} 

clean:
					${RM} ${OBJS}

fclean: 			clean
					${RM} ${NAME}

re:     			fclean all

bonus:				all

.PHONY: 			all clean fclean re
