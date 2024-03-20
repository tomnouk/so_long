/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:26:37 by anomourn          #+#    #+#             */
/*   Updated: 2024/03/20 19:03:16 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	init_struct(t_game *game, char **argv)
{
	ft_memset(game, 0, sizeof(t_game));
	game->argv = argv;
}

void	init_d(t_game *game)
{
	game->lines = 0;
	game->columns = 0;
	game->player_num = 0;
	game->collect_num = 0;
	game->exit_num = 0;
	game->nouk_num = 0;
	game->moves = 0;
	game->loop = 0;
	game->status = 0;
	game->sprite.collect_current_frame = 0;
}

/*Initialise toutes les données nécessaires de la structure
t_game et enregistre la carte après l'avoir validée.
Ensuite, initialise une nouvelle fenêtre mlx avec la carte
et les sprites, puis lance la boucle de jeu.*/
void	start_game(t_game *game, int first)
{
	if (!first)
		end_game(game, 0);
	init_d(game);
	validate_all_map(game->argv[1], game);
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, (64 * game->columns),
			(64 * game->lines) + (64 / 2), "nouk");
	init_sprites(game);
	init_map(game);
	mlx_string_put(game->mlx, game->window,
		8, (game->lines * 64) + (64 / 2) - 4, 16777215, "Moves:");
	mlx_hook(game->window, 1, 1L << 0, key, game);
	mlx_hook(game->window, 17, 0, end_game, game);
	mlx_loop_hook(game->mlx, nouk_hook, game);
	mlx_key_hook(game->window, key, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		write(1, ARG_ERROR, ft_strlen(ARG_ERROR));
		exit(errno);
	}
	init_struct(&game, argv);
	start_game(&game, 1);
	return (0);
}
