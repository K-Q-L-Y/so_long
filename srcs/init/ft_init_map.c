/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:48:34 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/08/14 22:19:22 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	open_fd(char *filename, int permission, t_game *game)
{
	int	fd;

	fd = open(filename, permission);
	if (fd < 0)
	{
		ft_putstr_fd(filename, 2);
		ft_exit_error(": Map not found\n", game);
	}
	return (fd);
}

// get map x and map y
// get coin and player count
static void	init_map_dimensions(t_game *game, char *filename)
{
	static int	player_count = 0;
	static int	exit_count = 0;
	int			fd;
	char		*line;

	fd = open_fd(filename, O_RDONLY, game);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		game->map.collectible += ft_count_occurence(line, 'C');
		player_count += ft_count_occurence(line, 'P');
		exit_count += ft_count_occurence(line, 'E');
		game->map.y++;
		game->map.x = ft_strlen(line) - (ft_ends_with(line, "\n") * 2);
		free(line);
	}
	close(fd);
	if (player_count != 1)
		ft_exit_error("Invalid number of players found.\n", game);
	if (exit_count != 1)
		ft_exit_error("Invalid number of exits found.\n", game);
	if (game->map.collectible == 0)
		ft_exit_error("No collectibles found.\n", game);
}

// Initialise map
void	ft_init_map(t_game *game, char *filename)
{
	int		fd;
	int		i;
	char	*line;

	init_map_dimensions(game, filename);
	fd = open_fd(filename, O_RDONLY, game);
	game->map.blocks = ft_calloc(game->map.y + 1, sizeof(char *));
	game->map.map_alloc = 1;
	i = -1;
	while (++i < game->map.y)
	{
		line = get_next_line(fd);
		game->map.blocks[i] = ft_strdup(line);
		free(line);
	}
	ft_check_map(game);
}
