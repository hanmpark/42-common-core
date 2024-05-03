# ---------------------------------- COLORS ---------------------------------- #
DEF		:= \033[0m
BOLD	:= \033[1m
CUR		:= \033[3m
UL		:= \033[4m
UP		:= \033[A

ORANGE	:= \033[38;5;216m
LBLUE	:= \033[38;5;153m
LYELLOW	:= \033[38;5;222m
BEIGE	:= \033[38;5;223m
LGREEN	:= \033[38;5;155m

# --------------------------------- SOURCES ---------------------------------- #
LIBFT_PATH		:= ./lib/libft/
LIBFT_INC_PATH	:= ${LIBFT_PATH}inc/

ifeq ($(shell uname), Linux)
	LIBMLX_PATH	:= ./lib/libmlx/linux
else
	LIBMLX_PATH	:= ./lib/libmlx/macos
endif

HEADER_PATH			:= ./inc/
HEADER_PATH_MAIN	:= ${HEADER_PATH}main/
DEPS_MAIN			:= ${addprefix ${HEADER_PATH_MAIN},	game.h \
														parsing.h}

MAIN_PATH	:= ./src/main/
SRCS_MAN	:= ${addprefix ${MAIN_PATH},	main.c \
											map_init.c \
											map_check.c \
											game_init.c \
											hooks.c \
											render.c \
											move_check.c}

HEADER_PATH_BONUS	:= ${HEADER_PATH}bonus/
DEPS_BONUS			:= ${addprefix ${HEADER_PATH_BONUS},	game_bonus.h \
															hooks_bonus.h \
															move_bonus.h \
															parsing_bonus.h}

BONUS_PATH	:= ./src/bonus/
SRCS_BONUS	:= ${addprefix ${BONUS_PATH},	map_init_bonus.c \
											map_check_bonus.c \
											assign_textures_bonus.c \
											game_init_bonus.c \
											move_player_bonus.c \
											game_check_bonus.c \
											hooks_bonus.c \
											image_utils_bonus.c \
											render_bonus.c \
											update_frame_bonus.c \
											move_enemy_bonus.c \
											print_tools_bonus.c \
											main_bonus.c \
											clear_textures_bonus.c}

# --------------------------------- OBJECTS ---------------------------------- #
OBJS_MAIN	:= ${SRCS_MAN:.c=.o}
OBJS_BONUS	:= ${SRCS_BONUS:.c=.o}

ifdef COMPILE_BONUS
	OBJS	:= ${OBJS_BONUS}
else
	OBJS	:= ${OBJS_MAIN}
endif

# --------------------------------- COMPILER --------------------------------- #
CC		:= cc
CFLAGS	= -Wall -Wextra -Werror

UTILS_FLAGS	:= -lm -Llib -lft

ifeq (${shell uname}, Linux)
	MLX_FLAGS	:= -lmlx -lXext -lX11
else
	MLX_FLAGS	:= -lmlx -framework OpenGL -framework Appkit
endif

ifdef DEBUG
	CFLAGS	+= -fsanitize=address -g
endif

SRCS_COUNT	= 0
SRCS_TOT	:= ${shell find ./src/main/ -type f -name '*.c' | wc -l}
SRCS_PRCT	= ${shell expr 100 \* ${SRCS_COUNT} / ${SRCS_TOT}}
BAR			= ${shell expr 23 \* ${SRCS_COUNT} / ${SRCS_TOT}}

${MAIN_PATH}%.o: ${MAIN_PATH}%.c ${DEPS_MAIN}
	@${eval SRCS_COUNT = ${shell expr ${SRCS_COUNT} + 1}}
	@${CC} ${CFLAGS} -I${HEADER_PATH_MAIN} -I${LIBMLX_PATH} -I${LIBFT_INC_PATH} -c $< -o $@
	@printf " ${BOLD}${CUR}${BEIGE}-> Compiling ${DEF}${BOLD}${LYELLOW}[${NAME}]${DEF}\n"
	@printf " ${BEIGE}   [${LGREEN}%-23.${BAR}s${BEIGE}] [%d/%d (%d%%)]${DEF}" "***********************" ${SRCS_COUNT} ${SRCS_TOT} ${SRCS_PRCT}
	@printf "${UP}${UP}\n"

SRCS_TOT_BONUS = ${shell find ./src/bonus/ -type f -name '*.c' | wc -l}
SRCS_PRCT_BONUS = ${shell expr 100 \* ${SRCS_COUNT} / ${SRCS_TOT_BONUS}}
BAR_BONUS = ${shell expr 23 \* ${SRCS_COUNT} / ${SRCS_TOT_BONUS}}

${BONUS_PATH}%.o: ${BONUS_PATH}%.c ${DEPS_BONUS}
	@${eval SRCS_COUNT = ${shell expr ${SRCS_COUNT} + 1}}
	@${CC} ${CFLAGS} -I${HEADER_PATH_BONUS} -I${LIBMLX_PATH} -I${LIBFT_INC_PATH} -c $< -o $@
	@printf " ${BOLD}${CUR}${BEIGE}-> Compiling ${DEF}${BOLD}${LYELLOW}[${NAME} (BONUS)]${DEF}\n"
	@printf " ${BEIGE}   [${LGREEN}%-23.${BAR_BONUS}s${BEIGE}] [%d/%d (%d%%)]${DEF}" "***********************" ${SRCS_COUNT} ${SRCS_TOT_BONUS} ${SRCS_PRCT_BONUS}
	@printf "${UP}${UP}\n"

# ---------------------------------- RULES ----------------------------------- #
RM		:= rm -f
NAME	:= so_long

all: libft mlx ${NAME}

${NAME}: ${OBJS}
	@${CC} ${FLAGS} ${OBJS} ${UTILS_FLAGS} -L${LIBMLX_PATH} ${MLX_FLAGS} -o $@
	@printf "\n\n\n   ${BOLD}${CUR}${LYELLOW}SO_LONG COMPILED ✨${DEF}\n\n"

libft:
	@${MAKE} -C ${LIBFT_PATH}

mlx:
	@${MAKE} -C ${LIBMLX_PATH}

bonus:
	@${MAKE} COMPILE_BONUS=1

debug:
	@printf "\n   ${BOLD}${UL}${MAGENTA}DEBUGGING MODE${DEF}\n"
	@${MAKE} DEBUG=1

clean:
	@printf "${ORANGE}${BOLD}\tCLEANING${DEF}\n"
	@${MAKE} -C ${LIBFT_PATH} clean
	@${MAKE} -C ${LIBMLX_PATH} clean
	@${RM} -r ${OBJS_MAIN} ${OBJS_BONUS}
	@printf "${LBLUE}${BOLD}${CUR} - Deleted object files${DEF}\n"

fclean:
	@${MAKE} -C ${LIBFT_PATH} fclean
	@${MAKE} -C ${LIBMLX_PATH} fclean
	@${RM} -r ${OBJS_MAIN} ${OBJS_BONUS}
	@${RM} ${NAME}
	@printf "${LBLUE}${BOLD}${CUR} - Deleted libft.a${DEF}\n"
	@printf "${LBLUE}${BOLD}${CUR} - Deleted ${NAME}${DEF}\n"

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus debug
