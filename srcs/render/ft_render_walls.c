/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 18:24:40 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/08/11 15:13:14 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Render walls
void	ft_render_walls(t_game *game, int y, int x)
{
	ft_render_sprite(game, game->animation.wall, y, x);
}
