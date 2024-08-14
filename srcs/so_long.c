/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 21:24:00 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/08/13 15:36:43 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = (t_game *)ft_calloc(sizeof(t_game), 1);
	ft_check_arguments(argc, argv, game);
	ft_mlx_init(game);
	ft_init_game(game, argv[1]);
	ft_mlx_new_window(game, TITLE, IMG_SIZE * game->map.x, IMG_SIZE
		* game->map.y);
	ft_render_map(game);
	ft_render_player(game);
	mlx_hook(game->win, KeyPress, KeyPressMask, key_press, game);
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask, ft_close_game_lost,
		game);
	mlx_loop(game->mlx);
	return (0);
}

// mlx_loop_hook(game->mlx, main_loop, &game);