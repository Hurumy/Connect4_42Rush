# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taekklee <taekklee@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 15:10:41 by taekklee          #+#    #+#              #
#    Updated: 2023/07/01 13:09:13 by taekklee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
AR			=	ar
ARFLAGS		=	rcs

NAME		=	libft.a
SRCS		=	ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_strlen.c \
				ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
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
				ft_putnbr_fd.c \
				ft_printf.c \
				convert/convert_chr.c \
				convert/convert_int.c \
				convert/convert_pct.c \
				convert/convert_ptr.c \
				convert/convert_str.c \
				opts/opts.c \
				opts/opts_utils.c \
				utils/utils_1.c \
				utils/utils_2.c \

OBJS		=	$(SRCS:.c=.o)

RM			=	rm -f 

%.o		:	%.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME) :	$(OBJS)
	$(AR) $(ARFLAGS) $@ $(OBJS)

.DEFAULT_GOAL	=	all
.PHONY	:	all
all		:	$(NAME)

.PHONY	:	clean
clean	:
	$(RM) $(OBJS)

.PHONY	:	fclean 
fclean	:	clean
	$(RM) $(NAME)

.PHONY	:	re
re		:	fclean all
