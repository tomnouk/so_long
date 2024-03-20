/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:07:08 by anomourn          #+#    #+#             */
/*   Updated: 2024/03/18 18:37:13 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*Si exit_as_wall est true, alors la sortie ('EXIT') est traitée
comme un mur. Elle est utilisée pour marquer les zones accessibles
sans passer par une sortie, sinon elle est traitée normalement*/
void	flood(char **map, t_coords coords, t_game *game, bool exit_as_wall)
{
	while ((exit_as_wall && map[coords.x][coords.y] != WALL
		&& map[coords.x][coords.y] != 'X' && map[coords.x][coords.y] != EXIT)
		|| (!exit_as_wall && map[coords.x][coords.y] != WALL
		&& map[coords.x][coords.y] != 'X'))
	{
		if (map[coords.x][coords.y] == COLLECTIBLE)
			game->temp--;
		else if (!exit_as_wall && map[coords.x][coords.y] == EXIT)
			game->exit_num--;
		map[coords.x][coords.y] = 'X';
		flood(map, (t_coords){coords.x + 1, coords.y}, game, exit_as_wall);
		flood(map, (t_coords){coords.x - 1, coords.y}, game, exit_as_wall);
		flood(map, (t_coords){coords.x, coords.y + 1}, game, exit_as_wall);
		flood(map, (t_coords){coords.x, coords.y - 1}, game, exit_as_wall);
	}
}

bool	block_exit(t_game *game)
{
	game->temp = game->collect_num;
	game->map_copy2 = copy_game(game);
	flood(game->map_copy2, (t_coords){game->x, game->y}, game, true);
	free_map(game->map_copy2, game);
	if (game->temp != 0)
		return (true);
	return (false);
}

char	**copy_game(t_game *game)
{
	int		i;

	game->map_copy2 = malloc(sizeof(char *) * game->lines);
	i = 0;
	while (game->lines > i)
	{
		game->map_copy2[i] = ft_calloc(sizeof(char), ft_strlen(game->map[i]));
		ft_memmove(game->map_copy2[i], game->map[i], ft_strlen(game->map[i]));
		i++;
	}
	return (game->map_copy2);
}

void	flood_fill(t_game *game)
{
	game->temp = game->collect_num;
	game->map_copy2 = copy_game(game);
	flood(game->map_copy2, (t_coords){game->x, game->y}, game, false);
	free_map(game->map_copy2, game);
	if (game->temp != 0)
		free_exit(PATH_COLL_ERROR, game);
	if (game->exit_num != 0)
		free_exit(PATH_EXIT_ERROR, game);
	if (block_exit(game))
		free_exit(BLOCKED_ERROR, game);
}
