/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:26:31 by anomourn          #+#    #+#             */
/*   Updated: 2024/03/20 13:46:58 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	init_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->lines > x)
	{
		y = 0;
		while (y < game->columns)
		{
			image_direct(game, game->sprite.base, 0, (t_coords){x, y});
			if (game->map[x][y] == PLAYER)
				image_direct(game, game->sprite.cat_down, 0, (t_coords){x, y});
			else if (game->map[x][y] == NOUK)
				image_direct(game, game->sprite.nouk_right, 0,
					(t_coords){x, y});
			else if (game->map[x][y] == WALL)
				image_direct(game, game->sprite.wall, 0, (t_coords){x, y});
			else if (game->map[x][y] == COLLECTIBLE)
				image_direct(game, game->sprite.collect, 0, (t_coords){x, y});
			else if (game->map[x][y] == EXIT)
				image_direct(game, game->sprite.exit, 0, (t_coords){x, y});
			y++;
		}
		x++;
	}
}

/*Calcule le nombre de lignes et alloue dynamiquement cette quantité de
chaînes de caractères dans le tableau game->map.*/
void	malloc_all(char *argv, t_game *game)
{
	game->fd = open(argv, O_RDONLY);
	if (game->fd < 0)
		close_free_exit(OPEN_ERROR, game, 3);
	game->tmp = get_next_line(game->fd);
	while (game->tmp)
	{
		game->columns = ft_strlen(game->tmp);
		game->lines++;
		free(game->tmp);
		game->tmp = get_next_line(game->fd);
	}
	if (game->lines == 0)
		close_free_exit(EMPTY_ERROR, game, 3);
	if (game->lines >= 16)
		close_free_exit(HEIGHT_ERROR, game, 3);
	game->map = ft_calloc(game->lines + 1, sizeof(char *));
	close(game->fd);
}

/*Alloue dynamiquement les lignes et les colonnes de la variable game->map,
puis utilise get_next_line pour lire le fichier de la carte
et copie son contenu dans game->map*/
void	read_map(char *argv, t_game *game)
{
	int	i;

	i = 0;
	malloc_all(argv, game);
	game->fd = open(argv, O_RDONLY);
	if (game->fd < 0)
		close_free_exit(OPEN_ERROR, game, 1);
	while (game->lines > i)
	{
		game->map[i] = get_next_line(game->fd);
		if (game->columns >= 32)
			close_free_exit(LENGHT_ERROR, game, 0);
		i++;
	}
	close(game->fd);
}