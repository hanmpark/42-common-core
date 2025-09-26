# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanmpark <hanmpark@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 16:40:47 by hanmpark          #+#    #+#              #
#    Updated: 2023/06/01 09:58:46 by hanmpark         ###   ########.fr        #
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
LYELLOW = \033[38;5;228m
LPURPLE = \033[38;5;189m
LGREEN = \033[38;5;155m

# ---------------------------- SOURCES / OBJECTS ----------------------------- #
SRCS_PATH = ./srcs/

SRCS_MAN_PATH = ${SRCS_PATH}mandatory/
SRCS = ${addprefix ${SRCS_MAN_PATH}, ft_bzero.c \
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
									ft_strlcat.c \
									ft_toupper.c \
									ft_tolower.c \
									ft_strchr.c \
									ft_strrchr.c \
									ft_strncmp.c \
									ft_memchr.c \
									ft_memcmp.c \
									ft_strnstr.c \
									ft_atoi.c \
									ft_calloc.c \
									ft_strdup.c \
									ft_substr.c \
									ft_strjoin.c \
									ft_strtrim.c \
									ft_split.c \
									ft_itoa.c \
									ft_strmapi.c \
									ft_striteri.c \
									ft_putchar_fd.c \
									ft_putstr_fd.c \
									ft_putendl_fd.c \
									ft_putnbr_fd.c}

OBJS_MAN = ${SRCS:.c=.o}

SRCS_BONUS_PATH = ${SRCS_PATH}bonus/
BONUS_SRCS = ${addprefix ${SRCS_BONUS_PATH}, ft_lstnew.c \
												ft_lstadd_front.c \
												ft_lstsize.c \
												ft_lstlast.c \
												ft_lstadd_back.c \
												ft_lstdelone.c \
												ft_lstclear.c \
												ft_lstiter.c \
												ft_lstmap.c}

BONUS_OBJS = ${BONUS_SRCS:.c=.o}

ifdef BONUS
OBJS = ${OBJS_MAN} ${BONUS_OBJS}
else
OBJS = ${OBJS_MAN}
endif

# --------------------------------- COMPILER --------------------------------- #
CC = gcc
CFLAGS = -Wall -Wextra -Werror

ifdef DEBUG
	CFLAGS += -fsanitize=address -g3
endif

HEADER = ./inc/
SRCS_COUNT = 0
SRCS_TOT = ${shell find . -type f -name '*.c' | wc -l}
SRCS_PRCT = ${shell expr 100 \* ${SRCS_COUNT} / ${SRCS_TOT}}
BAR = ${shell expr 23 \* ${SRCS_COUNT} / ${SRCS_TOT}}

%.o:%.c ${HEADER}
	@${eval SRCS_COUNT = ${shell expr ${SRCS_COUNT} + 1}}
	@${CC} ${CFLAGS} -I ${HEADER} -c $< -o ${<:.c=.o}
	@echo "\n ${BOLD}${CUR}${LPURPLE}-> Compiling ${DEF}${BOLD}${LYELLOW}[LIBFT]${DEF}"
	@printf " ${LPURPLE}   [${LGREEN}%-23.${BAR}s${LPURPLE}] [%d/%d (%d%%)]${DEF}" "***********************" ${SRCS_COUNT} ${SRCS_TOT} ${SRCS_PRCT}
	@echo "${UP}${UP}${UP}"

# ---------------------------------- RULES ----------------------------------- #
NAME = libft.a

all: ${NAME}

${NAME}: ${OBJS}
	@ar rcs ${NAME} ${OBJS}
	@echo "\n\n\n\n   ${BOLD}${CUR}${LYELLOW}PHILO COMPILED ✨${DEF}\n"

debug:
	@${MAKE} DEBUG=1

bonus:
	@${MAKE} BONUS=1

clean:
	@rm -f ${OBJS_MAN} ${BONUS_OBJS}
	@echo "${ORANGE}${BOLD}\tCLEANING${DEF}"
	@echo "${LBLUE}${BOLD}${CUR} - Deleted object files${DEF}"

fclean: clean
	@rm -f ${NAME}
	@echo "${LBLUE}${BOLD}${CUR} - Deleted ${NAME}${DEF}"

re: fclean
	@${MAKE} all

.PHONY: all debug clean fclean re bonus