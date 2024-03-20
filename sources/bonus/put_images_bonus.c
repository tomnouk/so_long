/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:26:22 by anomourn          #+#    #+#             */
/*   Updated: 2024/03/20 18:55:53 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	image_direct(t_game *game, void **image, int direct, t_coords coord)
{
	if (direct == 0)
		mlx_put_image_to_window(game->mlx, game->window,
			image, coord.y * 64, coord.x * 64);
	if (direct == LEFT)
		mlx_put_image_to_window(game->mlx, game->window,
			image, (coord.y + 1) * 64, coord.x * 64);
	else if (direct == RIGHT)
		mlx_put_image_to_window(game->mlx, game->window,
			image, (coord.y - 1) * 64, coord.x * 64);
	else if (direct == DOWN)
		mlx_put_image_to_window(game->mlx, game->window,
			image, coord.y * 64, (coord.x - 1) * 64);
	else if (direct == UP)
		mlx_put_image_to_window(game->mlx, game->window,
			image, coord.y * 64, (coord.x + 1) * 64);
	else if (direct == 0)
		mlx_put_image_to_window(game->mlx, game->window,
			image, coord.y * 64, coord.x * 64);
}

void	**convert_xpm(t_game *game, char *path)
{
	int		size;
	int		fd;

	size = 64;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		destroy_img(game);
		mlx_destroy_window(game->mlx, game->window);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		free_map(game->map, game);
		write(1, IMAGE_ERROR, ft_strlen(IMAGE_ERROR));
		exit(errno);
	}
	close(fd);
	game->image = mlx_xpm_file_to_image(game->mlx, path, &size, &size);
	return (game->image);
}

void	init_sprites(t_game *game)
{
	game->sprite.base = convert_xpm(game, "./xpm/sol.xpm");
	game->sprite.wall = convert_xpm(game, "./xpm/wall.xpm");
	game->sprite.exit = convert_xpm(game, "./xpm/exit.xpm");
	game->sprite.cat_right = convert_xpm(game, "./xpm/cat_right.xpm");
	game->sprite.cat_down = convert_xpm(game, "./xpm/cat_down.xpm");
	game->sprite.cat_up = convert_xpm(game, "./xpm/cat_up.xpm");
	game->sprite.cat_left = convert_xpm(game, "./xpm/cat_left.xpm");
	game->sprite.black = convert_xpm(game, "./xpm/black.xpm");
	game->sprite.nouk_right = convert_xpm(game, "./xpm/nouk_right.xpm");
	game->sprite.nouk_left = convert_xpm(game, "./xpm/nouk_left.xpm");
	game->sprite.nouk_up = convert_xpm(game, "./xpm/nouk_up.xpm");
	game->sprite.nouk_down = convert_xpm(game, "./xpm/nouk_down.xpm");
	game->sprite.collect = convert_xpm(game, "./xpm/mouse_1.xpm");
	game->sprite.collect1 = convert_xpm(game, "./xpm/mouse_2.xpm");
	game->end = 0;
}

void	destroy(t_game *game, void **image)
{
	if (image)
	{
		mlx_destroy_image(game->mlx, image);
		image = NULL;
	}
}

void	destroy_img(t_game *game)
{
	destroy(game, game->sprite.base);
	destroy(game, game->sprite.wall);
	destroy(game, game->sprite.collect);
	destroy(game, game->sprite.collect1);
	destroy(game, game->sprite.exit);
	destroy(game, game->sprite.cat_right);
	destroy(game, game->sprite.cat_down);
	destroy(game, game->sprite.cat_up);
	destroy(game, game->sprite.cat_left);
	destroy(game, game->sprite.nouk_right);
	destroy(game, game->sprite.nouk_left);
	destroy(game, game->sprite.nouk_up);
	destroy(game, game->sprite.nouk_down);
	destroy(game, game->sprite.black);
}
