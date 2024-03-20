/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:06:49 by anomourn          #+#    #+#             */
/*   Updated: 2024/03/18 19:38:37 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	moves_term(t_game *game)
{
	game->moves++;
	ft_putnbr_fd(game->moves, 1);
	write(1, "\n", 1);
}

int	end_game(t_game *game, int should_exit)
{
	destroy_img(game);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game->map, game);
	if (should_exit)
	{
		write(1, "GAME ENDED\n", 11);
		exit(errno);
	}
	return (0);
}

int	restart(int key, void *game)
{
	if (key == DOWN)
		arrows(game, DOWN);
	if (key == UP)
		arrows(game, UP);
	if (key == ENTER)
		selection(game);
	return (0);
}

void	selection(t_game *game)
{
	if (game->pos_arrow == UP)
		start_game(game, 0);
	else if (game->pos_arrow == DOWN)
		end_game(game, 1);
}

/*bouge la fleche a la position specifiee par
l'argument direct.*/
void	arrows(t_game *game, int direct)
{
	game->y = ((64 * game->lines) / 2);
	game->x = ((64 * game->columns) / 2) - (64 / 2);
	mlx_clear_window(game->mlx, game->window);
	mlx_string_put(game->mlx, game->window,
		game->x, game->y, 16777215, "RESTART");
	mlx_string_put(game->mlx, game->window,
		game->x, game->y + 64, 16777215, "EXIT");
	if (direct == UP)
	{
		mlx_string_put(game->mlx, game->window,
			game->x - 64, game->y, 16777215, ">");
		game->pos_arrow = UP;
	}
	else if (direct == DOWN)
	{
		mlx_string_put(game->mlx, game->window, game->x - 64,
			game->y + 64, 16777215, ">");
		game->pos_arrow = DOWN;
	}
}
