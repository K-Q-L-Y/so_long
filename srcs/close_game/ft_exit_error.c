/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:50:46 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/08/16 09:48:37 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit_error(char *s, t_game *game)
{
	if (*s)
	{
		ft_putstr_fd("Error:\n\t", 2);
		ft_putstr_fd(s, 2);
	}
	if (game->map.map_alloc == 1)
		ft_free_split(game->map.y, game->map.blocks);
	ft_destroy_images(game);
	free(game->mlx);
	free(game);
	exit(1);
}
