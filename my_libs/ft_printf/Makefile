# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/09 00:06:01 by lade-lim          #+#    #+#              #
#    Updated: 2022/08/17 17:25:50 by lade-lim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	ft_printf.c \
			srcs/print_char.c \
			srcs/print_str.c \
			srcs/print_int.c \
			srcs/print_unsigned_int.c \
			srcs/print_percentage.c \
			srcs/print_hex.c \
			srcs/print_void_hex.c \
			utils/ft_strlen.c \
			utils/ft_putstr_len.c \
			utils/ft_atoi.c \
			utils/ft_itoa.c \
			utils/ft_putchar_len.c \
			utils/ft_uitoa.c \
			utils/ft_strdup.c \
			utils/ft_uitoahex.c \
			utils/ft_strtolower.c \
			utils/ft_strtolupper.c \
			utils/ft_strchr.c \
			utils/ft_strjoin.c \
			utils/ft_uipoint_hex.c \
			utils/put_flags.c \
			utils/init_structs.c \
			utils/is_true_flags.c

OBJS	=	${SRC:.c=.o} 

NAME	=	libftprintf.a

FLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

CC		=	cc

AR		=	ar -rcs


all: 		${NAME}

.c.o:
			@$(CC) ${FLAGS} -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS) 
			@ar -rcs $(NAME) $(OBJS)

bonus:		${NAME}

clean:
			@${RM} ${OBJS}

fclean:		clean
			@${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
