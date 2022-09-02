NAME	=	fractol.a

# MY LIBRARIES - libft.a and libftprintf.a
PRINTF_PATH =	./my_libs/ft_printf/
LIBFT_PATH =	./my_libs/ft_libft/

PRINTF =		$(PRINTF_PATH)libftprintf.a
LIBFT =			$(LIBFT_PATH)libft.a

# INPUTS
SRC		=	main.c \
			init_structs.c \
			events.c \
			mandelbrot.c \
			color.c \
			julia.c 
		

HSRC	=	fractol.h 
OBJS	=	$(addprefix srcs/, ${SRC:.c=.o})

# compilation
CC		=	gcc
CFLAGS	=	-O3 -g3 
IFT		=	-Ilibft -Llibft
IMLX	=	-Imlx -Lmlx -lmlx -lXext -lX11 -lm

# clean
RM		=	rm -f

all: 		${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I.

$(PRINTF):
			make -C $(PRINTF_PATH)

$(LIBFT):
			make -C $(LIBFT_PATH)
			make bonus -C $(LIBFT_PATH)
			
$(NAME):	$(OBJS) $(HSRC) $(LIBFT) $(PRINTF)
			ar -rcs $(NAME) $(OBJS)
			$(CC) $(CFLAGS) $(addprefix srcs/, $(SRC)) $(NAME) $(PRINTF) $(LIBFT) $(IFT) $(IMLX) -o fractol

clean:
			${RM} ${OBJS}
			cd $(PRINTF_PATH) && make clean 
			cd $(LIBFT_PATH) && make clean 

fclean:		clean
			${RM} ${NAME}
			${RM} fractol
			${RM} ${PRINTF}
			${RM} ${LIBFT}

re:			fclean all

bonus:		${NAME}

.PHONY:		all clean fclean re