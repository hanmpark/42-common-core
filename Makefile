# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/01 14:42:42 by hanmpark          #+#    #+#              #
#    Updated: 2023/03/15 23:47:44 by hanmpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS_PATH = ./src/
HEADER_PATH = ./inc/
LIBFT_PATH = ./libft/

# <<<<<<<<<< COLORS >>>>>>>>>> #
DEF = \033[0m
BOLD = \033[1m
CUR = \033[3m
UL = \033[4m
UP = \033[A

ORANGE = \033[38;5;216m
LBLUE = \033[38;5;153m
LYELLOW = \033[38;5;222m
BEIGE = \033[38;5;223m

# <<<<<<<<<< SRC /OBJ >>>>>>>>>> #
PARSING_PATH = ${SRCS_PATH}parsing/
PARSING_SRCS = ${addprefix ${PARSING_PATH}, init_list.c \
											set_index.c \
											check_init_list.c}

INSTRUCTIONS_PATH = ${SRCS_PATH}instructions/
INSTRUCTIONS_SRCS = ${addprefix ${INSTRUCTIONS_PATH}, push.c \
														reverse_rotate.c \
														rotate.c \
														swap.c}

SORT_PATH = ${SRCS_PATH}sort/
SORT_SRCS = ${addprefix ${SORT_PATH}, sort_big_number.c \
										sort_small_number.c \
										count_moves.c \
										locate.c \
										moves.c}

SRCS = ${PARSING_SRCS} ${INSTRUCTIONS_SRCS} ${SORT_SRCS} ${SRCS_PATH}main.c

OBJS = ${SRCS:.c=.o}

# <<<<<<<<<< COMPILER >>>>>>>>>> #
CC = gcc
CFLAGS = -Wall -Wextra -Werror

ifdef DEBUG
CFLAGS += -fsanitize=address -g3
endif

SRCS_COUNT = 0
SRCS_TOT = ${shell find ./src/ -type f -name '*.c' | wc -l}
SRCS_PRCT = ${shell expr 100 \* ${SRCS_COUNT} / ${SRCS_TOT}}

%.o:%.c ${HEADER_PATH}
	@${eval SRCS_COUNT = ${shell expr ${SRCS_COUNT} + 1}}
	@${CC} ${CFLAGS} -c -I ${HEADER_PATH} $< -o ${<:.c=.o}
	@echo " ${BOLD}${CUR}${BEIGE}-> Compiling ${DEF}${BOLD}${LYELLOW}[PUSH_SWAP]${DEF}"
	@printf " ${BEIGE}  [%d/%d files (%d%%)]${DEF}" ${SRCS_COUNT} ${SRCS_TOT} ${SRCS_PRCT}
	@echo "${UP}${UP}"

# <<<<<<<<<< RULES >>>>>>>>>> #
all: ${NAME}

${NAME}: ${OBJS}
	@echo "\n\n"
	@${MAKE} -C ${LIBFT_PATH}
	@${CC} ${CFLAGS} ${LIBFT_PATH}/libft.a ${OBJS} -o ${NAME}
	@echo "\n\n\n\t${BOLD}${CUR}${LYELLOW}COMPILED ✨${DEF}\n"

debug:
	@${MAKE} DEBUG=1

norminette:
	@echo "\n\t${BOLD}${CUR}${ORANGE}NORMINETTE${DEF}\n"
	@echo "${LYELLOW}${BOLD}LIBFT${DEF}"
	@echo "${LBLUE}${CUR}ft_printf${DEF}"
	@norminette ${LIBFT_PATH}src/ft_printf/
	@echo "\n${LBLUE}${CUR}get_next_line${DEF}"
	@norminette ${LIBFT_PATH}src/get_next_line/
	@echo "\n${LBLUE}${CUR}libft${DEF}"
	@norminette ${LIBFT_PATH}src/libft/
	@echo "\n${LYELLOW}${BOLD}PUSH_SWAP${DEF}"
	@echo "${LBLUE}${CUR}instructions${DEF}"
	@norminette ${INSTRUCTIONS_PATH}
	@echo "\n${LBLUE}${CUR}parsing${DEF}"
	@norminette ${PARSING_PATH}
	@echo "\n${LBLUE}${CUR}sort${DEF}"
	@norminette ${SORT_PATH} ${SRCS_PATH}main.c
	@echo ""

clean:
	@echo "\n\t${BOLD}${CUR}${ORANGE}CLEANING...${DEF}\n"
	@rm -rf ${OBJS}
	@${MAKE} -C ${LIBFT_PATH} clean
	@echo "${LBLUE}${BOLD}${CUR}- Deleted object files${DEF}\n"

fclean: clean
	@rm -rf ${LIBFT_PATH}/libft.a
	@rm -rf ${NAME}
	@echo "${LBLUE}${BOLD}${CUR}- Deleted libft.a and ${NAME}${DEF}\n\n"

re: fclean all

.PHONY: all clean fclean clean re debug
