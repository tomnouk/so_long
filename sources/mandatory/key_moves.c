/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:36:11 by anomourn          #+#    #+#             */
/*   Updated: 2024/03/20 13:33:27 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	key(int key, t_game *game)
{
	if (key == LEFT)
		move(game, game->sprite.cat_left, LEFT);
	else if (key == RIGHT)
		move(game, game->sprite.cat_right, RIGHT);
	else if (key == DOWN)
		move(game, game->sprite.cat_down, DOWN);
	else if (key == UP)
		move(game, game->sprite.cat_up, UP);
	else if (key == ESC)
		end_game(game, 1);
	return (0);
}

void	moves_player(t_game *game, int direct, int option)
{
	if ((direct == LEFT && option == TRUE)
		|| (direct == RIGHT && option == FALSE))
		game->y--;
	else if ((direct == RIGHT && option == TRUE)
		|| (direct == LEFT && option == FALSE))
		game->y++;
	else if ((direct == DOWN && option == TRUE)
		|| (direct == UP && option == FALSE))
		game->x++;
	else if ((direct == UP && option == TRUE)
		|| (direct == DOWN && option == FALSE))
		game->x--;
}
