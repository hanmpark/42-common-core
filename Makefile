# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/25 13:32:25 by hanmpark          #+#    #+#              #
#    Updated: 2023/03/30 18:17:33 by hanmpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------------------------- COLORS ---------------------------------- #
DEF = \033[0m
BOLD = \033[1m
CUR = \033[3m
UL = \033[4m
UP = \033[A

ORANGE = \033[38;5;216m
LBLUE = \033[38;5;153m
LYELLOW = \033[38;5;222m
BEIGE = \033[38;5;223m

# --------------------------------- SOURCES ---------------------------------- #
SRC_PATH = ./src/

MAIN_PATH = ${SRC_PATH}main/
SRCS_MAIN = ${addprefix ${MAIN_PATH}, defineCommand.c \
										execCommand.c \
										pipex.c}

BONUS_PATH = ${SRC_PATH}bonus/
SRCS_BONUS = ${addprefix ${BONUS_PATH}, pipex_bonus.c \
										defineCommand_bonus.c \
										execCommand_bonus.c}

OBJS_MAIN = ${SRCS_MAIN:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

ifdef BONUS
OBJS = ${OBJS_BONUS}
else
OBJS = ${OBJS_MAIN}
endif

# --------------------------------- COMPILER --------------------------------- #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
ifdef DEBUG
CFLAGS += -fsanitize=address -g3
endif
HEADER_PATH = ./inc/

SRCS_COUNT = 0
SRCS_TOT = ${shell find ./src/ -type f -name '*.c' | wc -l}
SRCS_PRCT = ${shell expr 100 \* ${SRCS_COUNT} / ${SRCS_TOT}}

%.o:%.c ${HEADER_PATH}
	@${eval SRCS_COUNT = ${shell expr ${SRCS_COUNT} + 1}}
	@${CC} ${CFLAGS} -I ${HEADER_PATH} -c $< -o ${<:.c=.o}
	@echo " ${BOLD}${CUR}${BEIGE}-> Compiling ${DEF}${BOLD}${LYELLOW}[LIBFT]${DEF}"
	@printf " ${BEIGE}  [%d/%d files (%d%%)]${DEF}" ${SRCS_COUNT} ${SRCS_TOT} ${SRCS_PRCT}
	@echo "${UP}${UP}"

# ---------------------------------- RULES ----------------------------------- #
LIBFT_PATH = ./libft/
NAME = pipex

all: ${NAME}

${NAME}:	${OBJS} ${OBJS_BONUS}
	@echo "\n\n"
	@${MAKE} -C ${LIBFT_PATH}
	@${CC} ${CFLAGS} ${LIBFT_PATH}libft.a ${OBJS} -o ${NAME}
	@echo "\n\n\n   ${BOLD}${CUR}${LYELLOW}PIPEX COMPILED ✨${DEF}\n"

bonus:
	@${MAKE} BONUS=1

debug:
	@${MAKE} DEBUG=1

clean:
	@echo "\n\t${BOLD}${CUR}${ORANGE}CLEANING...${DEF}\n"
	@rm -f ${OBJS_MAIN} ${OBJS_BONUS}
	@${MAKE} -C ${LIBFT_PATH} clean
	@echo "${LBLUE}${BOLD}${CUR}- Deleted object files${DEF}\n"

fclean: clean
	@${eval SRCS_COUNT = 0}
	@rm -f ${LIBFT_PATH}libft.a
	@rm -f ${NAME}
	@echo "${LBLUE}${BOLD}${CUR}- Deleted libft.a ${NAME}${DEF}\n\n"

re: fclean all

.PHONY: all clean fclean re debug bonus