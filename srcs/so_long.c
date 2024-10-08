/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 21:24:00 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/08/16 09:07:47 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_window(t_game *game)
{
	ft_render_map(game);
	ft_render_player(game);
	return (0);
}

int	expose_hook(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	draw_window(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = (t_game *)ft_calloc(sizeof(t_game), 1);
	ft_check_arguments(argc, argv, game);
	ft_mlx_init(game);
	ft_init_game(game, argv[1]);
	ft_mlx_new_window(game, TITLE, IMG_SIZE * game->map.x, IMG_SIZE
		* game->map.y);
	mlx_do_key_autorepeaton(game->mlx);
	mlx_hook(game->win, ON_KEYDOWN, KEY_PRESS_MASK, key_press, game);
	mlx_hook(game->win, ON_DESTROY, STRUCTURE_NOTIFY_MASK, ft_close_game_lost,
		game);
	mlx_expose_hook(game->win, expose_hook, game);
	mlx_loop(game->mlx);
	return (0);
}
