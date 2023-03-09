# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAKEFILE                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hguillau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/09 13:03:38 by hguillau          #+#    #+#              #
#    Updated: 2023/03/09 15:50:51 by hguillau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    	=		main.c						\

OBJS    	=		${SRCS:.c=.o}

NAME    	=		philosophers

CC      	=		gcc

RM      	=		rm -f

CFLAGS  	=		-Wall -Wextra -Werror -Imlx #-g -fsanitize=address

all:				${NAME}

${NAME}:			${OBJS}
					${CC} ${CFLAGS} -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME} ${OBJS} ${LIBFT}

clean:
					${RM} ${OBJS}

fclean: 			clean
					${RM} ${NAME}

re:     			fclean all

bonus:				all

.PHONY: 			all clean fclean re
