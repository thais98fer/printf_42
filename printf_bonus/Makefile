# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thais.fer <thais.fer@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/08 12:35:00 by thfernan          #+#    #+#              #
#    Updated: 2025/08/25 14:02:43 by thais.fer        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
CC = cc

SRCS = 	ft_printf.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putnbr.c \
		ft_init_specifier.c \
		ft_parse_specifier.c \
		ft_parse_format.c \

BONUS_SRCS = ft_parse_bonus.c \
			ft_aux_ptr_bonus.c \
			ft_counts_put_bonus.c \
			ft_pad_zeros_bonus.c \
			ft_pad_zeros_x_u_bonus.c \

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

AR = ar
ARFLAGS = rcs

all: $(NAME)

$(NAME): $(OBJS)
		$(AR) $(ARFLAGS) $(NAME) $(OBJS)

bonus: 
		$(MAKE) OBJS="$(OBJS) $(BONUS_OBJS)" all

%.o: %.c
		$(CC) $(FLAGS) -c $< -o $@

clean:
		rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
		rm -f $(NAME)
		
re: fclean all

.PHONY: all bonus clean fclean re
