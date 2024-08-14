/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:50:46 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/08/13 15:16:05 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit_error(char *s, t_game *game)
{
	ft_putstr_fd(s, 2);
	if (game->map.map_alloc)
		ft_free_split(game->map.y, game->map.blocks);
	ft_destroy_images(game);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
	exit(1);
}
