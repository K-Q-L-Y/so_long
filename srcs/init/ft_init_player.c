/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:48:12 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/08/16 11:14:29 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Reset x and y coordinates
// Reset steps and collectibles
void	ft_init_player(t_game *game)
{
	game->player.x = -1;
	game->player.y = -1;
	game->player.steps = 0;
	game->player.collectible = 0;
	game->player.direction = IDLE;
}
