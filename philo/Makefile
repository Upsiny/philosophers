# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hguillau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 15:56:20 by hguillau          #+#    #+#              #
#    Updated: 2023/03/29 14:53:23 by hguillau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    	=		main.c						\
					death.c						\
					philo_utils.c				\
					philo_utils2.c				\
					routine.c					\

OBJS    	=		${SRCS:.c=.o}

NAME    	=		philo

CC      	=		gcc -g

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
