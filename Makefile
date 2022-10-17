NAME			=	fractol

BONUS 			=	fractol_bonus

PRINTF_PATH		=	./my_libs/ft_printf/
LIBFT_PATH 		=	./my_libs/ft_libft/
MINILIBX_PATH	=	./minilibx-linux/

PRINTF 			=	$(PRINTF_PATH)libftprintf.a
LIBFT 			=	$(LIBFT_PATH)libft.a
MINILIBX		= 	$(MINILIBX_PATH)libmlx_Linux.a

SRC_FILES 		=	fractol.c \
				init_structs.c \
				start_window.c \
				check_errors.c \
				draw_fractol.c \
				fractol_math.c \
				key_events.c \
				define_color.c \
				mouse_event.c \
				close_window.c 


SRC_PATH		=	./srcs
OBJ_PATH		=	./obj

HSRC			=	./includes/fractol.h 
SRC 			=	$(addprefix $(SRC_PATH)/, $(SRC_FILES))
OBJ 			=	$(SRC:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)

CC				=	gcc
CFLAGS			=	-g3 -O3 -Wall -Wextra -Werror
MLXFLAGS		= 	-Imlx -Lmlx -lmlx -lXext -lX11 -lm

RM				=	rm -rf

all:	$(NAME)

$(NAME):	$(LIBFT) $(PRINTF) $(MINILIBX)  $(OBJ)
	$(CC) $(OBJ) $(PRINTF) $(LIBFT) $(MINILIBX) $(CFLAGS) $(MLXFLAGS) -o $@ 

$(OBJ_PATH)/%.o:	$(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC)  -c  $(CFLAGS)  $< -o $@


$(PRINTF):
	@make -C $(PRINTF_PATH)

$(LIBFT):
	@make -C $(LIBFT_PATH)
	@make bonus -C $(LIBFT_PATH)

$(MINILIBX):
	@make -C $(MINILIBX_PATH)

clean:
	@${RM} ${OBJ_PATH}
	@cd $(PRINTF_PATH) && make clean 
	@cd $(LIBFT_PATH) && make clean 
	@cd $(MINILIBX_PATH) && make clean

fclean:		clean
	@${RM} ${NAME}
	@${RM} ${PRINTF}
	@${RM} ${LIBFT}

re:			fclean all

.PHONY:		all clean fclean re