/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_images.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:38:26 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/08/13 15:38:34 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_destroy_images(t_game *game)
{
	mlx_destroy_image(game->mlx, game->animation.player_idle.xpm_ptr);
	mlx_destroy_image(game->mlx, game->animation.floor.xpm_ptr);
	mlx_destroy_image(game->mlx, game->animation.wall.xpm_ptr);
	mlx_destroy_image(game->mlx, game->animation.finish.xpm_ptr);
	mlx_destroy_image(game->mlx, game->animation.collectible.xpm_ptr);
}
