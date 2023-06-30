# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: komatsud <komatsud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/30 21:30:46 by komatsud          #+#    #+#              #
#    Updated: 2023/06/30 21:33:16 by komatsud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= connect4

CC		= cc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror #-fsanitize=address

SRCS	= *.c

ARCS	= include/libft.a

all: $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean

re: fclean all

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

.PHONY: all clean fclean re