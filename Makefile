# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 16:40:47 by hanmpark          #+#    #+#              #
#    Updated: 2022/11/08 17:09:12 by hanmpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES =	ft_*.c

OBJECTS = ${SOURCES:.c=.o}

NAME = libft.a

.c.o:
		gcc -Wall -Wextra -Werror -c -I ./includes $< -o ${<:.c=.o}

${NAME}:	${OBJECTS}
		ar -rcs ${NAME} ${OBJECTS}

all:	${NAME}

clean:	
		rm -f ${OBJECTS}

fclean:	clean
		rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re