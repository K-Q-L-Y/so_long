/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_sprite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 14:32:51 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/08/10 18:28:55 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_sprite(t_game *game, t_img sprite, int y, int x)
{
	mlx_put_image_to_window(game->mlx, game->win, sprite.xpm_ptr, x * sprite.x,
		y * sprite.y);
}
