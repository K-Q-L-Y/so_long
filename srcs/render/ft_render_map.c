/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 14:53:43 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/08/11 15:14:32 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Render floor, walls and exit
void	ft_render_map(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->map.y)
	{
		x = -1;
		while (++x < game->map.x)
		{
			if (game->map.blocks[y][x] == WALL)
				ft_render_sprite(game, game->animation.wall, y, x);
			else if (game->map.blocks[y][x] == EXIT)
				ft_render_sprite(game, game->animation.finish, y, x);
			else if (game->map.blocks[y][x] == COLLECTIBLE)
				ft_render_sprite(game, game->animation.collectible, y, x);
			else
				ft_render_sprite(game, game->animation.floor, y, x);
		}
	}
}
