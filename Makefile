# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 16:40:47 by hanmpark          #+#    #+#              #
#    Updated: 2022/11/10 16:16:17 by hanmpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES =	ft_bzero.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_memcpy.c \
			ft_memset.c \
			ft_strlen.c \
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c 

OBJECTS = ${SOURCES:.c=.o}

NAME = libft.a

.c.o:
		gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

${NAME}:	${OBJECTS}
		ar -rcs ${NAME} ${OBJECTS}

all:	${NAME}

clean:	
		rm -f ${OBJECTS}

fclean:	clean
		rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re