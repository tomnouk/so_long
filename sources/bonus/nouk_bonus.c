/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nouk_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:25:51 by anomourn          #+#    #+#             */
/*   Updated: 2024/03/18 19:47:23 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	change_collect(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->lines > x)
	{
		y = 0;
		while (y < game->columns)
		{
			if (game->map[x][y] == COLLECTIBLE)
			{
				if (game->sprite.collect_current_frame == 0)
					image_direct(game, game->sprite.collect, 0,
						(t_coords){x, y});
				else
					image_direct(game, game->sprite.collect1, 0,
						(t_coords){x, y});
			}
			y++;
		}
		x++;
	}
}

void	move_nouk_horizontally(t_game *game, int random)
{
	if (game->map[game->anouk.x][game->anouk.y + random] == '0')
	{
		image_direct(game, game->sprite.base, 0,
			(t_coords){game->anouk.x, game->anouk.y});
		game->map[game->anouk.x][game->anouk.y] = '0';
		game->anouk.y = game->anouk.y + random;
		game->map[game->anouk.x][game->anouk.y] = 'N';
		if (random < 0)
			image_direct(game, game->sprite.nouk_left, 0,
				(t_coords){game->anouk.x, game->anouk.y});
		else
			image_direct(game, game->sprite.nouk_right, 0,
				(t_coords){game->anouk.x, game->anouk.y});
	}
	else if (game->map [game->anouk.x][game->anouk.y + random] == 'P')
		game_over(game);
}

void	move_nouk_vertically(t_game *game, int random)
{
	if (game->map[game->anouk.x + random][game->anouk.y] == '0')
	{
		image_direct(game, game->sprite.base, 0,
			(t_coords){game->anouk.x, game->anouk.y});
		game->map[game->anouk.x][game->anouk.y] = '0';
		game->anouk.x = game->anouk.x + random;
		game->map[game->anouk.x][game->anouk.y] = 'N';
		if (random < 0)
			image_direct(game, game->sprite.nouk_up, 0,
				(t_coords){game->anouk.x, game->anouk.y});
		else
			image_direct(game, game->sprite.nouk_down, 0,
				(t_coords){game->anouk.x, game->anouk.y});
	}
	else if (game->map [game->anouk.x + random][game->anouk.y] == 'P')
		game_over(game);
}

int	nouk_hook(t_game *game)
{
	int	random_direct;
	int	random_value;
	int	interval;

	game->loop++;
	random_value = (rand() % 2);
	random_direct = (rand() % 2);
	if (random_direct == 0)
		random_direct = -1;
	interval = 55555;
	if (game->status != OVER && game->status != WIN)
	{
		if (game->loop % 555 == 0)
		{
			game->sprite.collect_current_frame
				= (game->sprite.collect_current_frame + 1) % 2;
			change_collect(game);
		}
		if (random_value == 0 && game->loop % interval == 0)
			move_nouk_horizontally(game, random_direct);
		else if (random_value == 1 && game->loop % interval == 0)
			move_nouk_vertically(game, random_direct);
	}
	return (0);
}
