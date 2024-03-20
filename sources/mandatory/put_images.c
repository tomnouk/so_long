/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:06:26 by anomourn          #+#    #+#             */
/*   Updated: 2024/03/20 19:06:42 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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
	game->img = mlx_xpm_file_to_image(game->mlx, path, &size, &size);
	return (game->img);
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
	destroy(game, game->sprite.exit);
	destroy(game, game->sprite.cat_right);
	destroy(game, game->sprite.cat_down);
	destroy(game, game->sprite.cat_up);
	destroy(game, game->sprite.cat_left);
}

void	init_sprites(t_game *game)
{
	game->sprite.base = convert_xpm(game, "./xpm/sol.xpm");
	game->sprite.wall = convert_xpm(game, "./xpm/wall.xpm");
	game->sprite.collect = convert_xpm(game, "./xpm/mouse_1.xpm");
	game->sprite.exit = convert_xpm(game, "./xpm/exit.xpm");
	game->sprite.cat_right = convert_xpm(game, "./xpm/cat_right.xpm");
	game->sprite.cat_down = convert_xpm(game, "./xpm/cat_down.xpm");
	game->sprite.cat_up = convert_xpm(game, "./xpm/cat_up.xpm");
	game->sprite.cat_left = convert_xpm(game, "./xpm/cat_left.xpm");
}
