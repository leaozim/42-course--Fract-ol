NAME	=	fractol

BONUS 	=	fractol_bonus

# MY LIBRARIES - libft.a and libftprintf.a
PRINTF_PATH =	./my_libs/ft_printf/
LIBFT_PATH =	./my_libs/ft_libft/

PRINTF =		$(PRINTF_PATH)libftprintf.a
LIBFT =			$(LIBFT_PATH)libft.a

# INPUTS
SRC_FILES =		fractol.c \
				init_structs.c \
				start_windows.c \
				check_errors.c \
				draw_fractol.c \
				fractol_math.c \
				key_events.c \
				define_color.c \
				mouse_event.c \
				close_window.c 

SRCB_FILES 	=	fractol_bonus.c \
				init_structs_bonus.c \
				start_windows_bonus.c \
				check_errors_bonus.c \
				draw_fractol_bonus.c \
				fractol_math_bonus.c \
				key_events_bonus.c \
				define_color_bonus.c \
				mouse_event_bonus.c \
				close_window_bonus.c 


SRC_PATH =			./srcs
OBJ_PATH =			./obj
SRC_BONUS_PATH =	./srcs_bonus
OBJ_BONUS_PATH =	./obj/bonus

HSRC			=	./includes/fractol.h 
HSRC_BONUS		=	./includes/fractol_bonus.h 
SRC 			=	$(addprefix $(SRC_PATH)/, $(SRC_FILES))
OBJ 			=	$(SRC:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)
SRC_BONUS 		=	$(addprefix $(SRC_BONUS_PATH)/, $(SRCB_FILES))
OBJ_BONUS 		=	$(SRC_BONUS:$(SRC_BONUS_PATH)/%.c=$(OBJ_BONUS_PATH)/%.o)

# compilation
CC		=	gcc
CFLAGS	=	-g3 -O3 -Imlx -Lmlx -lmlx -lXext -lX11 -lm -Wall -Wextra -Werror

# clean
RM		=	rm -rf

all:	$(NAME)

bonus:
	@make OBJ="$(OBJ_BONUS)" all --no-print-directory

$(NAME):	$(LIBFT) $(PRINTF) $(OBJ)
	$(CC) $(OBJ) $(PRINTF) $(LIBFT) $(CFLAGS) -o $@ 

$(OBJ_PATH)/%.o:	$(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) -c $< -o $@

$(OBJ_BONUS_PATH)/%.o:	$(SRC_BONUS_PATH)/%.c
	@mkdir -p $(OBJ_BONUS_PATH)
	$(CC) -c $< -o $@

$(PRINTF):
			make -C $(PRINTF_PATH)

$(LIBFT):
			make -C $(LIBFT_PATH)
			make bonus -C $(LIBFT_PATH)


clean:
			${RM} ${OBJ_PATH}
			cd $(PRINTF_PATH) && make clean 
			cd $(LIBFT_PATH) && make clean 

fclean:		clean
			${RM} ${NAME}
			${RM} ${BONUS}
			${RM} fractol
			${RM} ${PRINTF}
			${RM} ${LIBFT}

re:			fclean all

.PHONY:		all clean fclean re bonus