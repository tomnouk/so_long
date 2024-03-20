/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:06:42 by anomourn          #+#    #+#             */
/*   Updated: 2024/03/20 19:02:44 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	is_win(t_game *game)
{
	moves_term(game);
	write(1, "\nBRAVOOO\n", 10);
	arrows(game, UP);
	mlx_key_hook(game->window, restart, game);
}

bool	is_exit(t_game *game, int direct)
{
	if (game->map[game->x][game->y] == EXIT)
	{
		if (game->collect_num == 0)
			is_win(game);
		moves_player(game, direct, FALSE);
		return (false);
	}
	return (true);
}

bool	is_wall(t_game *game, int direct)
{
	if ((direct == LEFT && (game->map[game->x][game->y - 1] != WALL))
		|| (direct == RIGHT && (game->map[game->x][game->y + 1] != WALL))
		|| (direct == DOWN && (game->map[game->x + 1][game->y] != WALL))
		|| (direct == UP && (game->map[game->x - 1][game->y] != WALL)))
		return (false);
	return (true);
}

void	move(t_game *game, void **player, int direct)
{
	if (!is_wall(game, direct))
	{
		moves_player(game, direct, TRUE);
		check_col(game);
		if (is_exit(game, direct))
		{
			image_direct(game, game->sprite.base, direct,
				(t_coords){game->x, game->y});
			image_direct(game, player, 0, (t_coords){game->x, game->y});
			moves_term(game);
		}
	}
}

void	check_col(t_game *game)
{
	if (game->map[game->x][game->y] == COLLECTIBLE)
	{
		game->map[game->x][game->y] = 0;
		game->collect_num--;
		image_direct(game, game->sprite.base, 0, (t_coords){game->x, game->y});
	}
}
