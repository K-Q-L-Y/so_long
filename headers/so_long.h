/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 21:24:05 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/08/14 11:44:47 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TITLE "SO_LONG"
# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define BUFFER_SIZE 10000
# define IMG_SIZE 32

// keys
enum			e_key_inputs
{
	KEY_ESC = 65307,
	KEY_W = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100,
	KEY_UP = 65362,
	KEY_DOWN = 65364,
	KEY_LEFT = 65361,
	KEY_RIGHT = 65363,
};

// directions
enum			e_directions
{
	UP = 1,
	DOWN = 2,
	LEFT = 3,
	RIGHT = 4,
};

enum			e_blocks
{
	FLOOR = '0',
	WALL = '1',
	COLLECTIBLE = 'C',
	PLAYER = 'P',
	EXIT = 'E',
};

# include "../includes/libft/libft.h"
# include "assets_path.h"
# include "mlx.h"
# include "trgb_colours.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_img
{
	void		*xpm_ptr;
	int			x;
	int			y;
}				t_img;

typedef struct s_animation
{
	t_img		player_idle;
	t_img		wall;
	t_img		floor;
	t_img		finish;
	t_img		collectible;
}				t_animation;

typedef struct s_player
{
	int			steps;
	int			collectible;
	int			direction;
	int			x;
	int			y;
}				t_player;

typedef struct s_map
{
	char		**blocks;
	int			map_alloc;
	int			collectible;
	int			x;
	int			y;
}				t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_player	player;
	t_map		map;
	t_animation	animation;
}				t_game;

// Initialization
void			ft_check_arguments(int argc, char **argv, t_game *game);
void			ft_flood_fill(t_game *game);
t_img			ft_create_sprite(void *mlx, char *path, t_game *game);
void			ft_init_game(t_game *game, char *map);
void			ft_init_map(t_game *game, char *map);
void			ft_init_player(t_game *game);
void			ft_init_sprites(t_game *game);
char			*get_next_line(int fd);

// Player
int				key_press(int keycode, t_game *data);
void			ft_player_move(t_game *game, int new_x, int new_y,
					int direction);

// MLX
void			ft_mlx_init(t_game *game);
void			ft_mlx_new_window(t_game *game, char *title, int width,
					int height);

// Rendering
void			ft_render_sprite(t_game *game, t_img sprite, int y, int x);
void			ft_render_finish(t_game *game, int y, int x);
void			ft_render_floor(t_game *game, int y, int x);
void			ft_render_walls(t_game *game, int y, int x);
void			ft_render_collectibles(t_game *game, int y, int x);
void			ft_render_player(t_game *game);
void			ft_render_map(t_game *game);

// Close
void			ft_print_steps(t_game *game, int win);
void			ft_destroy_images(t_game *game);
int				ft_close_game_lost(t_game *game);
int				ft_close_game_victory(t_game *game);
void			ft_exit_error(char *s, t_game *game);

#endif
