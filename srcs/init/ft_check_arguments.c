/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:49:54 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/08/14 19:02:56 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_arguments(int argc, char **argv, t_game *game)
{
	int	valid;

	valid = 1;
	game->map.map_alloc = 0;
	if (argc < 2)
	{
		ft_putendl_fd("No map specified. Example: ./so_long maps/map.ber", 2);
		valid = 0;
	}
	else if (argc > 2)
	{
		ft_putendl_fd("Too many arguments. Example: ./so_long maps/map.ber", 2);
		valid = 0;
	}
	else if (ft_ends_with(argv[1], ".ber") == 0)
	{
		ft_putendl_fd("Wrong map extension. Example : map.ber", 2);
		valid = 0;
	}
	if (!valid)
	{
		free(game);
		exit(1);
	}
}
