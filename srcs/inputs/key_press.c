/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 21:23:58 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/08/13 15:36:52 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Esc to exit, WASD to move
int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		ft_close_game_lost(game);
	else if (keycode == KEY_W)
		ft_player_move(game, game->player.x, game->player.y - 1, UP);
	else if (keycode == KEY_S)
		ft_player_move(game, game->player.x, game->player.y + 1, DOWN);
	else if (keycode == KEY_A)
		ft_player_move(game, game->player.x - 1, game->player.y, LEFT);
	else if (keycode == KEY_D)
		ft_player_move(game, game->player.x + 1, game->player.y, RIGHT);
	return (0);
}

// else if (keycode == KEY_W)
// 	game->player.y -= 1;
// else if (keycode == KEY_A)
// 	game->player.x -= 1;
// else if (keycode == KEY_S)
// 	game->player.y += 1;
// else if (keycode == KEY_D)
// 	game->player.x += 1;