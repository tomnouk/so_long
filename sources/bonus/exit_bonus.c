/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:04:54 by anomourn          #+#    #+#             */
/*   Updated: 2024/03/18 19:49:57 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	game_over(t_game *game)
{
	game->status = OVER;
	ft_putstr_fd("GAME OVER\n", 1);
	game->end = 1;
	arrows(game, UP);
	mlx_key_hook(game->window, restart, game);
}

void	free_map(char **tab, t_game *game)
{
	int	i;

	i = 0;
	while (game->lines > i)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}

void	free_exit(char *error, t_game *game)
{
	free_map(game->map, game);
	write(1, error, ft_strlen(error));
	exit(errno);
}

void	close_free_exit(char *error, t_game *game, int option)
{
	if (option == 0)
	{
		free(game->map);
		game->map = NULL;
	}
	else if (option == 1)
		free_map(game->map, game);
	close(game->fd);
	write(1, error, ft_strlen(error));
	exit(errno);
}
