/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:07:15 by anomourn          #+#    #+#             */
/*   Updated: 2024/03/18 18:13:05 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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

/*En fonction de l'option choisie, free soit les lignes dans game->map,
soit free la variable complète game->map, puis ferme le fichier de
carte et ecrit le message d'erreur envoyé en argument
au terminal, et quitte le programme avec errno.*/
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
