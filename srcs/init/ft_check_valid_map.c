/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:40:53 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/08/14 23:13:35 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**copy_array(char **arr)
{
	int		i;
	int		count;
	char	**new_arr;

	if (!arr)
		return (0);
	count = 0;
	while (arr[count] != 0)
		count++;
	new_arr = ft_calloc((count + 1), sizeof(char *));
	if (!new_arr)
		return (0);
	i = -1;
	while (++i < count)
		new_arr[i] = ft_strdup(arr[i]);
	new_arr[count] = 0;
	return (new_arr);
}

static void	flood_fill(t_floodfill *area, int row, int col)
{
	if (row < 0 || col < 0 || row >= area->y || col >= area->x)
		return ;
	if (area->map[row][col] == 'F')
		return ;
	if (ft_strchr("CPE0", area->map[row][col]) == 0)
		return ;
	if (area->map[row][col] == 'C')
		area->collectibles_found++;
	if (area->map[row][col] == 'E')
		area->exit_found = 1;
	area->map[row][col] = 'F';
	flood_fill(area, row - 1, col);
	flood_fill(area, row + 1, col);
	flood_fill(area, row, col - 1);
	flood_fill(area, row, col + 1);
}

static void	init_area(t_floodfill *area, t_game *game)
{
	area->map = copy_array(game->map.blocks);
	if (!area->map)
	{
		free(area);
		ft_exit_error("Malloc error\n", game);
	}
	area->y = game->map.y;
	area->x = game->map.x;
	area->collectibles_found = 0;
	area->exit_found = 0;
	area->start_x = game->player.x;
	area->start_y = game->player.y;
}

void	ft_check_valid_map(t_game *game)
{
	t_floodfill	*area;

	area = (t_floodfill *)ft_calloc(sizeof(t_floodfill), 1);
	if (!area)
		ft_exit_error("Malloc error\n", game);
	init_area(area, game);
	flood_fill(area, area->start_y, area->start_x);
	if (area->exit_found == 0)
	{
		ft_free_split(game->map.y, area->map);
		free(area);
		ft_putendl_fd("Player can't reach exit.", 2);
	}
	if (area->collectibles_found != game->map.collectible)
	{
		ft_free_split(game->map.y, area->map);
		free(area);
		ft_putendl_fd("Player can't collect all collectibles.", 2);
	}
	ft_free_split(game->map.y, area->map);
	free(area);
}
