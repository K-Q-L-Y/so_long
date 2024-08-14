/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_new_window.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:09:58 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/08/11 14:34:20 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mlx_new_window(t_game *game, char *title, int width, int height)
{
	game->win = mlx_new_window(game->mlx, width, height, title);
	if (!game->win)
	{
		free(game->mlx);
		free(game);
		exit(1);
	}
}
