/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:49:42 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/08/13 15:36:34 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	collect_collectible(t_game *game, int collectible)
{
	game->map.blocks[game->player.y][game->player.x] = FLOOR;
	if (collectible == COLLECTIBLE)
		game->player.collectible++;
}

void	ft_player_move(t_game *game, int new_x, int new_y, int direction)
{
	if (game->map.blocks[new_y][new_x] != WALL)
	{
		if (game->map.blocks[game->player.y][game->player.x] == EXIT)
			ft_render_finish(game, game->player.y, game->player.x);
		else
			ft_render_floor(game, game->player.y, game->player.x);
		if (direction == RIGHT)
			game->player.x++;
		if (direction == LEFT)
			game->player.x--;
		if (direction == UP)
			game->player.y--;
		if (direction == DOWN)
			game->player.y++;
		if (game->map.blocks[game->player.y][game->player.x] == COLLECTIBLE)
			collect_collectible(game, COLLECTIBLE);
		ft_render_player(game);
		if (game->map.blocks[game->player.y][game->player.x] == EXIT)
			if (game->player.collectible == game->map.collectible)
				ft_close_game_victory(game);
		game->player.steps++;
	}
}
