/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 18:11:21 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/08/16 09:48:33 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_destroy_game(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	ft_destroy_images(game);
	ft_free_split(game->map.y, game->map.blocks);
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	free(game);
	exit(0);
}

int	ft_close_game_lost(t_game *game)
{
	ft_print_steps(game, 0);
	ft_destroy_game(game);
	return (0);
}

int	ft_close_game_victory(t_game *game)
{
	ft_print_steps(game, 1);
	ft_destroy_game(game);
	return (0);
}
