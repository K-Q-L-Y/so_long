/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 18:25:45 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/08/14 22:50:16 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Initialise map and sprites
void	ft_init_game(t_game *game, char *map)
{
	ft_init_player(game);
	ft_init_sprites(game);
	ft_init_map(game, map);
	ft_check_valid_map(game);
}
