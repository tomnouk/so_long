# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 12:27:35 by anomourn          #+#    #+#              #
#    Updated: 2024/03/20 13:28:59 by anomourn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CC_FLAGS = -Wall -Wextra -Werror -g

SRCS = ./sources/mandatory/options_game.c \
		./sources/mandatory/exit.c \
		./sources/mandatory/flood_fill.c \
		./sources/mandatory/key_moves.c \
		./sources/mandatory/pars_map.c \
		./sources/mandatory/all_move.c \
		./sources/mandatory/put_images.c \
		./sources/mandatory/read_map.c \
		./sources/mandatory/so_long.c \

SRCS_BONUS = 	./sources/bonus/options_game_bonus.c \
				./sources/bonus/flood_fill_bonus.c \
				./sources/bonus/nouk_bonus.c \
				./sources/bonus/exit_bonus.c \
				./sources/bonus/all_move_bonus.c \
				./sources/bonus/pars_map_bonus.c \
				./sources/bonus/key_moves_bonus.c \
				./sources/bonus/put_images_bonus.c \
				./sources/bonus/read_map_bonus.c \
				./sources/bonus/so_long_bonus.c \
				./sources/bonus/is_charact_bonus.c \

NAME = so_long

NAME_BONUS = so_long_bonus

MAKE_LIBFT = make -C libft

MAKE_MLX =  make -C minilibx-linux

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

RM = @rm -f

all: $(NAME)
		
$(NAME): $(OBJS)
		@$(MAKE_LIBFT)
		@$(MAKE_MLX)
		@$(CC) $(CC_FLAGS) $(OBJS) -Lmlx_linux ./libft/libft.a ./minilibx-linux/libmlx.a -lXext -lX11 -lm -lz -o $(NAME)
		@echo "mandatory ok"

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
		@$(MAKE_LIBFT) 
		@$(MAKE_MLX)
		@$(CC) $(CC_FLAGS) $(OBJS_BONUS) -Lmlx_linux ./libft/libft.a ./minilibx-linux/libmlx.a -lXext -lX11 -lm -lz -o $(NAME_BONUS)
		@echo "bonus ok"

clean:
		@$(MAKE) clean -C ./libft
		$(RM) $(OBJS_BONUS) $(OBJS)

fclean: 
		@$(MAKE) fclean -C ./libft
		$(RM) $(OBJS) $(OBJS_BONUS) $(NAME) $(NAME_BONUS)
		@$(MAKE) clean -C ./minilibx-linux
		
re: fclean all

add:
	git add $(SRCS)
	git add $(SRCS_BONUS)
	git add *.h
	git add Makefile

.PHONY: all bonus clean fclean re