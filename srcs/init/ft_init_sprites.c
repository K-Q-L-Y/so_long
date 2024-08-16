/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:17:17 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/08/16 11:21:16 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Initialise sprites
// Choose XPM files here
void	ft_init_sprites(t_game *game)
{
	void	*mlx;

	mlx = game->mlx;
	game->animation.player_idle = ft_create_sprite(mlx, IMG_PLAYER_IDLE, game);
	game->animation.player_up = ft_create_sprite(mlx, IMG_PLAYER_UP, game);
	game->animation.player_down = ft_create_sprite(mlx, IMG_PLAYER_DOWN, game);
	game->animation.player_left = ft_create_sprite(mlx, IMG_PLAYER_LEFT, game);
	game->animation.player_right = ft_create_sprite(mlx, IMG_PLAYER_RIGHT,
			game);
	game->animation.floor = ft_create_sprite(mlx, IMG_FLOOR_WOOD, game);
	game->animation.wall = ft_create_sprite(mlx, IMG_WALL_STONE, game);
	game->animation.collectible = ft_create_sprite(mlx, IMG_COIN_WOOD, game);
	game->animation.finish = ft_create_sprite(mlx, IMG_FINISH, game);
}
