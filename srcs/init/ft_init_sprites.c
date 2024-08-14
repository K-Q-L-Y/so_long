/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:17:17 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/08/13 15:16:51 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Initialise sprites
void	ft_init_sprites(t_game *game)
{
	void	*mlx;

	mlx = game->mlx;
	game->animation.player_idle = ft_create_sprite(mlx, IMG_PLAYER_IDLE, game);
	game->animation.floor = ft_create_sprite(mlx, IMG_FLOOR, game);
	game->animation.wall = ft_create_sprite(mlx, IMG_WALL, game);
	game->animation.collectible = ft_create_sprite(mlx, IMG_COIN, game);
	game->animation.finish = ft_create_sprite(mlx, IMG_FINISH, game);
}
