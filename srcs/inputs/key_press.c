/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 21:23:58 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/08/16 09:44:23 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Esc to exit, WASD to move
int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC || keycode == KEY_ESC_MAC)
		ft_close_game_lost(game);
	else if (keycode == KEY_W || keycode == KEY_W_MAC || keycode == KEY_UP
		|| keycode == KEY_UP_MAC)
		ft_player_move(game, game->player.x, game->player.y - 1, UP);
	else if (keycode == KEY_S || keycode == KEY_S_MAC || keycode == KEY_DOWN
		|| keycode == KEY_DOWN_MAC)
		ft_player_move(game, game->player.x, game->player.y + 1, DOWN);
	else if (keycode == KEY_A || keycode == KEY_A_MAC || keycode == KEY_LEFT
		|| keycode == KEY_LEFT_MAC)
		ft_player_move(game, game->player.x - 1, game->player.y, LEFT);
	else if (keycode == KEY_D || keycode == KEY_D_MAC || keycode == KEY_RIGHT
		|| keycode == KEY_RIGHT_MAC)
		ft_player_move(game, game->player.x + 1, game->player.y, RIGHT);
	return (0);
}
