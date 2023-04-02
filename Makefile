# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/25 13:32:25 by hanmpark          #+#    #+#              #
#    Updated: 2023/04/02 15:43:52 by hanmpark         ###   ########.fr        #
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
LGREEN = \033[38;5;155m

# --------------------------------- SOURCES ---------------------------------- #
SRC_PATH = ./src/

MAIN_PATH = ${SRC_PATH}main/
SRCS_MAIN = ${addprefix ${MAIN_PATH}, define.c \
										exec.c \
										pipex.c}

BONUS_PATH = ${SRC_PATH}bonus/
SRCS_BONUS = ${addprefix ${BONUS_PATH}, pipex_bonus.c \
										define_bonus.c \
										exec_bonus.c \
										stdin_bonus.c}

OBJS_MAIN = ${SRCS_MAIN:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

ifdef COMPILE_BONUS
	OBJS = ${OBJS_BONUS}
else
	OBJS = ${OBJS_MAIN}
endif

# --------------------------------- COMPILER --------------------------------- #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
ifdef DEBUG
	CFLAGS += -fsanitize=address -g
endif

HEADER_PATH = ./inc/main/
SRCS_COUNT = 0
SRCS_TOT = ${shell find ./src/main/ -type f -name '*.c' | wc -l}
SRCS_PRCT = ${shell expr 100 \* ${SRCS_COUNT} / ${SRCS_TOT}}
BAR =  ${shell expr 23 \* ${SRCS_COUNT} / ${SRCS_TOT}}

${MAIN_PATH}%.o: ${MAIN_PATH}%.c ${HEADER_PATH}
	@${eval SRCS_COUNT = ${shell expr ${SRCS_COUNT} + 1}}
	@${CC} ${CFLAGS} -I ${HEADER_PATH} -c $< -o ${<:.c=.o}
	@echo ""
	@echo " ${BOLD}${CUR}${BEIGE}-> Compiling ${DEF}${BOLD}${LYELLOW}[PIPEX]${DEF}"
	@printf " ${BEIGE}   [${LGREEN}%-23.${BAR}s${BEIGE}] [%d/%d (%d%%)]${DEF}" "***********************" ${SRCS_COUNT} ${SRCS_TOT} ${SRCS_PRCT}
	@echo "${UP}${UP}${UP}"

HEADER_PATH_BONUS = ./inc/bonus/
SRCS_TOT_BONUS = ${shell find ./src/bonus/ -type f -name '*.c' | wc -l}
SRCS_PRCT_BONUS = ${shell expr 100 \* ${SRCS_COUNT} / ${SRCS_TOT_BONUS}}
BAR_BONUS = ${shell expr 23 \* ${SRCS_COUNT} / ${SRCS_TOT_BONUS}}

${BONUS_PATH}%.o: ${BONUS_PATH}%.c ${HEADER_PATH_BONUS}
	@${eval SRCS_COUNT = ${shell expr ${SRCS_COUNT} + 1}}
	@${CC} ${CFLAGS} -I ${HEADER_PATH_BONUS} -c $< -o ${<:.c=.o}
	@echo ""
	@echo " ${BOLD}${CUR}${BEIGE}-> Compiling ${DEF}${BOLD}${LYELLOW}[PIPEX (BONUS)]${DEF}"
	@printf " ${BEIGE}   [${LGREEN}%-23.${BAR_BONUS}s${BEIGE}] [%d/%d (%d%%)]${DEF}" "***********************" ${SRCS_COUNT} ${SRCS_TOT_BONUS} ${SRCS_PRCT_BONUS}
	@echo "${UP}${UP}${UP}"

# ---------------------------------- RULES ----------------------------------- #
LIBFT_PATH = ./libft/
NAME = pipex

all: ${NAME}

${NAME}: ${OBJS}
	@echo "\n\n\n"
	@${MAKE} -C ${LIBFT_PATH}
	@${CC} ${CFLAGS} ${LIBFT_PATH}libft.a ${OBJS} -o ${NAME}
	@echo "\n\n\n   ${BOLD}${CUR}${LYELLOW}PIPEX COMPILED ✨${DEF}\n"

bonus:
	@${MAKE} COMPILE_BONUS=1 all

debug:
	@${MAKE} DEBUG=1

clean:
	@rm -f ${OBJS_MAIN} ${OBJS_BONUS}
	@${MAKE} -C ${LIBFT_PATH} clean
	@echo "\n${ORANGE}${BOLD}\tCLEANING${DEF}"
	@echo "${LBLUE}${BOLD}${CUR} - Deleted object files${DEF}"

fclean: clean
	@${eval SRCS_COUNT = 0}
	@rm -f ${LIBFT_PATH}libft.a ${NAME}
	@echo "${LBLUE}${BOLD}${CUR} - Deleted libft.a${DEF}"
	@echo "${LBLUE}${BOLD}${CUR} - Deleted ${NAME}${DEF}"

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re debug bonus rebonus