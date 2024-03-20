/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:07:36 by anomourn          #+#    #+#             */
/*   Updated: 2024/03/18 20:00:19 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include <errno.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include <limits.h>

# define TRUE 0
# define FALSE 1
# define WIN 2
# define OVER 1

# define PLAYER 'P'
# define NOUK 'N'
# define WALL '1'
# define EXIT 'E'
# define COLLECTIBLE 'C'

# define UP XK_w
# define DOWN XK_s
# define LEFT XK_a
# define RIGHT XK_d
# define ESC XK_Escape
# define ENTER XK_Return

# define EXIT_ERROR "map should contain exactly one exit 'E'\n"
# define ARG_ERROR "nb args invalid\n"
# define EMPTY_ERROR "map is empty...\n"
# define PLAY_ERROR "map should contain exactly one player\n"
# define EXTENSION_ERROR "extension should be .ber\n"
# define WALL_ERROR "map should be surrounded by walls\n"
# define RECTANGLE_ERROR "map should be a rectangle\n"
# define OPEN_ERROR "file could not be opened\n"
# define LENGHT_ERROR "the lenght is >= 32\n"
# define CHAR_ERROR "invalid character\n"
# define PATH_EXIT_ERROR "impossible to get to exit\n"
# define HEIGHT_ERROR "the height is >= 16\n"
# define COLL_ERROR "map should contain at least one collectible\n"
# define FOLDER_ERROR "arg sent is not a file\n"
# define NOUK_ERROR "map should contain one nouk 'n'\n"
# define PATH_COLL_ERROR "impossible to get to all 'c'\n"
# define BLOCKED_ERROR "exit is blocking 'c'\n"
# define IMAGE_ERROR "sprites could not be opened\n"

typedef struct s_coords
{
	int	x;
	int	y;
}				t_coords;

typedef struct sprites
{
	int			collect_current_frame;
	void		**base;
	void		**wall;
	void		**collect;
	void		**collect1;
	void		**exit;
	void		**cat_right;
	void		**cat_down;
	void		**cat_up;
	void		**cat_left;
	void		**black;
	void		**nouk_right;
	void		**nouk_left;
	void		**nouk_up;
	void		**nouk_down;
}				t_sprites;

typedef struct game
{
	int			pos_arrow;
	int			player_num;
	int			collect_num;
	int			exit_num;
	int			nouk_num;
	int			temp;
	int			fd;
	int			loop;
	int			status;
	int			end;
	int			moves;
	int			x;
	int			y;
	int			lines;
	int			columns;
	t_sprites	sprite;
	t_coords	anouk;
	void		*mlx;
	void		*window;
	char		*tmp;
	void		**image;
	char		**map_copy2;
	char		**map;
	char		**argv;
}				t_game;

void	start_game(t_game *game, int first);
void	arrows(t_game *game, int direct);
void	selection(t_game *game);
void	game_over(t_game *game);
void	change_collect(t_game *game);
void	free_map(char **tab, t_game *game);
void	free_exit(char *error, t_game *game);
void	close_free_exit(char *error, t_game *game, int option);
void	flood_fill(t_game *game);
void	init_sprites(t_game *game);
void	init_struct(t_game *game, char **argv);
void	init_map(t_game *game);
void	init_d(t_game *game);
void	check_col(t_game *game);
void	moves_player(t_game *game, int direct, int option);
void	moves_term(t_game *game);
void	move_player_on_map(t_game *game, int direct);
void	move(t_game *game, void **player, int direct);
void	image_direct(t_game *game, void **image, int direct, t_coords coord);
void	destroy_img(t_game *game);
void	read_map(char *argv, t_game *game);
void	is_nouk(t_game *game, int x, int y);
void	is_player(t_game *game, int x, int y);
void	validate_all_map(char *argv, t_game *game);

bool	is_exit(t_game *game, int direct);
bool	is_wall(t_game *game, int direct);

int		end_game(t_game *game, int should_exit);
int		restart(int key, void *game);
int		key(int key, t_game *game);
int		nouk_hook(t_game *game);

char	**copy_map(t_game *game);

#endif
