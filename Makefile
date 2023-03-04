# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/01 14:42:42 by hanmpark          #+#    #+#              #
#    Updated: 2023/03/04 14:02:04 by hanmpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS_PATH = ./src/
HEADER_PATH = ./inc/
LIBFT_PATH = ./libft/

DEF = \033[0m
BOLD = \033[1m
CUR = \033[3m
UL = \033[4m

GREEN = \033[32m
GRAY = \033[2;37m
MAGENTA = \033[35m

SRCS = ${addprefix ${SRCS_PATH}, main.c \
									init_list_a.c \
									set_index.c}

OBJS = ${SRCS:.c=.o}


CC = gcc
CFLAGS = -Wall -Wextra -Werror

ifdef DEBUG
CFLAGS += -fsanitize=address -g3
endif

%.o:%.c ${HEADER_PATH}
	@${CC} ${CFLAGS} -c -I ./${HEADER_PATH} $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	@echo "\n${CUR}${GRAY}\t- Compiling...${DEF}"
	@${MAKE} -C ${LIBFT_PATH}
	@${CC} ${CFLAGS} ${LIBFT_PATH}/libft.a ${OBJS} -o ${NAME}
	@echo "${CUR}${GRAY}\t- Created ${BOLD}${NAME}${DEF}"
	@echo "   ${CUR}${BOLD}${UL}${GREEN}- Compiled -${DEF}\n"

debug:
	@${MAKE} DEBUG=1

clean:
	@echo "\n${CUR}${GRAY}\t- Removing object files${DEF}"	
	@rm -rf ${OBJS}
	@${MAKE} -C ${LIBFT_PATH} clean

fclean: clean
	@echo "${CUR}${GRAY}\t- Removing ${BOLD}${NAME}${DEF}"
	@rm -rf ${LIBFT_PATH}/libft.a
	@rm -rf ${NAME}
	@echo "   ${CUR}${BOLD}${UL}${GREEN}- Cleaned -${DEF}\n"

re: fclean all

.PHONY: all clean fclean clean re