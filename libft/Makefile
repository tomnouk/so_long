# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 12:27:09 by anomourn          #+#    #+#              #
#    Updated: 2024/03/14 14:51:25 by anomourn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CC_FLAGS = -Wall -Wextra -Werror

SRCS = ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strncmp.c \
		ft_calloc.c \
		ft_itoa.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putnbr_fd.c \
		ft_absolute.c \
		ft_gnl.c \

NAME = libft.a

		
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	@echo "libft ok"


%.o: %.c libft.h
	$(CC) $(CC_FLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all 

add:
	git add $(SRCS)
	git add *.h
	git add Makefile