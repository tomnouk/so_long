/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:23:22 by anomourn          #+#    #+#             */
/*   Updated: 2024/03/20 19:05:29 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	exist_charact(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->lines > x)
	{
		y = 0;
		while (game->columns > y)
		{
			if (game->map[x][y] == PLAYER)
				is_player(game, x, y);
			else if (game->map[x][y] == NOUK)
				is_nouk(game, x, y);
			else if (game->map[x][y] == COLLECTIBLE)
				game->collect_num++;
			else if (game->map[x][y] == EXIT)
				game->exit_num++;
			else if (game->map[x][y] != WALL && game->map[x][y] != '0')
				free_exit(CHAR_ERROR, game);
			y++;
		}
		x++;
	}
}

void	walls_everywhere(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->columns)
	{
		if (game->map[0][i] != WALL || game->map[game->lines - 1][i] != WALL)
			free_exit(WALL_ERROR, game);
		if (i < game->lines && (game->map[i][game->columns - 1] != WALL
			|| game->map[i][0] != WALL))
			free_exit(WALL_ERROR, game);
		i++;
	}
}

void	check_rect(t_game *game)
{
	int	i;

	i = 0;
	while (game->lines > i)
	{
		if (ft_strlen(game->map[i]) != (size_t)game->columns)
			free_exit(RECTANGLE_ERROR, game);
		i++;
	}
}

void	validate_extension(char *argv)
{
	int		i;
	int		fd;
	void	*buf;

	i = (ft_strlen(argv) - 4);
	if (ft_strncmp(".ber", &argv[i], 4) != 0)
	{
		write(1, EXTENSION_ERROR, ft_strlen(EXTENSION_ERROR));
		exit(errno);
	}
	fd = open(argv, O_RDONLY);
	if (read(fd, &buf, 1) == -1)
	{
		close(fd);
		write(1, FOLDER_ERROR, ft_strlen(FOLDER_ERROR));
		exit(errno);
	}
	close (fd);
}

void	validate_all_map(char *argv, t_game *game)
{
	validate_extension(argv);
	read_map(argv, game);
	check_rect(game);
	walls_everywhere(game);
	exist_charact(game);
	if (game->player_num != 1)
		free_exit(PLAY_ERROR, game);
	if (game->collect_num < 1)
		free_exit(COLL_ERROR, game);
	if (game->exit_num != 1)
		free_exit(EXIT_ERROR, game);
	if (game->nouk_num != 1)
		free_exit(NOUK_ERROR, game);
	flood_fill(game);
}
