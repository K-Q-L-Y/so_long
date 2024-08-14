/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_floor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:13:23 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/08/11 15:13:50 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Render floor
void	ft_render_floor(t_game *game, int y, int x)
{
	ft_render_sprite(game, game->animation.floor, y, x);
}
