# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: komatsud <komatsud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/30 21:30:46 by komatsud          #+#    #+#              #
#    Updated: 2023/07/02 17:20:03 by komatsud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= connect4

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

DEBUG			= debug
CFLAGS_DEBUG	= -Wall -Wextra -Werror -g -fsanitize=address

# find *.c | sed 's/$/ \\/'
SRCS	= \
			ft_add_pawn.c \
			ft_connect4.c \
			ft_draw_field.c \
			ft_error.c \
			ft_exit.c \
			ft_free.c \
			ft_get_move.c \
			ft_cal_move.c \
			ft_init.c \
			ft_is_game_ended.c \
			ft_randomly_choose_first_move.c \
			ft_show_result.c \
			get_next_line.c \
			get_next_line_utils.c \
			bonus/ft_draw_tiles.c \
			bonus/ft_error_libx.c \
			bonus/ft_free_libx.c \
			bonus/ft_hooks.c \
			bonus/ft_init_libx.c \
			bonus/ft_libx_connect4.c \

OBJS	= $(SRCS:.c=.o)

MINILIBX	=	libmlx.dylib

LIBFT_DIR	=	./libft
LIBFT		=	$(LIBFT_DIR)/libft.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(MINILIBX) $(LIBFT) -o $@

$(DEBUG):
	make all
	$(CC) $(OBJS) $(CFLAGS_DEBUG) $(LIBFT) $(MINILIBX) -o $(NAME)

$(LIBFT): FORCE
	@make -C $(LIBFT_DIR) all

clean:
	@make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

FORCE:

.PHONY: all clean fclean re FORCE
