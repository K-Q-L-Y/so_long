/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:09:26 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/08/13 12:23:43 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// initialise mlx
// free if fails
void	ft_mlx_init(t_game *game)
{
	if (!game)
	{
		ft_putendl_fd("Malloc error\n", 1);
		exit(1);
	}
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_exit_error("MLX init error\n", game);
}
