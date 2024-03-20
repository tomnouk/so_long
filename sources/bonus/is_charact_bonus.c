/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_charact_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:26:44 by anomourn          #+#    #+#             */
/*   Updated: 2024/03/18 19:45:35 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	is_nouk(t_game *game, int x, int y)
{
	game->nouk_num++;
	game->anouk.x = x;
	game->anouk.y = y;
}

void	is_player(t_game *game, int x, int y)
{
	game->player_num++;
	game->x = x;
	game->y = y;
}
