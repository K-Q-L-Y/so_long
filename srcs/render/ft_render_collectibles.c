/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_collectibles.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:58:36 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/08/11 15:15:10 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Render collectibles
void	ft_render_collectibles(t_game *game, int y, int x)
{
	ft_render_sprite(game, game->animation.collectible, y, x);
}
