/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 18:04:12 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/08/16 11:18:50 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_player(t_game *game)
{
	int	x;
	int	y;

	x = game->player.x;
	y = game->player.y;
	if (game->player.direction == IDLE)
		ft_render_sprite(game, game->animation.player_idle, y, x);
	else if (game->player.direction == UP)
		ft_render_sprite(game, game->animation.player_up, y, x);
	else if (game->player.direction == DOWN)
		ft_render_sprite(game, game->animation.player_down, y, x);
	else if (game->player.direction == LEFT)
		ft_render_sprite(game, game->animation.player_left, y, x);
	else if (game->player.direction == RIGHT)
		ft_render_sprite(game, game->animation.player_right, y, x);
}
