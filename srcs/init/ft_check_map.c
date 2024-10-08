/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 22:07:03 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/08/16 11:30:50 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_wall(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->map.y)
	{
		if (game->map.blocks[y][0] != WALL)
			ft_exit_error("Wall should surround map.\n", game);
		else if (game->map.blocks[y][game->map.x - 1] != WALL)
			ft_exit_error("Wall should surround map.\n", game);
	}
	x = -1;
	while (++x < game->map.x)
	{
		if (game->map.blocks[0][x] != WALL)
			ft_exit_error("Wall should surround map.\n", game);
		else if (game->map.blocks[game->map.y - 1][x] != WALL)
			ft_exit_error("Wall should surround map.\n", game);
	}
}

// checks if map is valid
// Initialise player position
// below is for special case where last line has \n
// if (y == game->map.y - 1 && ft_ends_with(game->map.blocks[y], "\n"))
// 	ft_exit_error("Newline at end of file.\n", game);
void	ft_check_map(t_game *game)
{
	int	y;
	int	x;

	if (!game->map.y || !game->map.x)
		ft_exit_error("Invalid map\n", game);
	y = -1;
	while (++y < game->map.y)
	{
		x = -1;
		if (ft_strlen_nl(game->map.blocks[y]) != game->map.x)
			ft_exit_error("Map is not rectangular.\n", game);
		while (++x < game->map.x)
		{
			if (ft_strchr("PCE01", game->map.blocks[y][x]) == 0)
				ft_exit_error("Invalid elements. Only 'PCE01' accepted\n",
					game);
			if (game->map.blocks[y][x] == 'P')
				game->player.x = x;
			if (game->map.blocks[y][x] == 'P')
				game->player.y = y;
		}
	}
	if (game->map.x > 100 || game->map.y > 100)
		ft_exit_error("Map too big, max 100x100.\n", game);
	check_wall(game);
}
