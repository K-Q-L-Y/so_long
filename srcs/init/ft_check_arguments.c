/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:49:54 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/08/13 15:13:19 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_arguments(int argc, char **argv, t_game *game)
{
	game->map.map_alloc = 0;
	if (argc < 2)
		ft_exit_error("No map specified. Example: ./so_long maps/map.ber\n",
			game);
	if (argc > 2)
		ft_exit_error("Too many arguments.", game);
	if (ft_ends_with(argv[1], ".ber") == 0)
		ft_exit_error("Wrong map extension. Example : map.ber\n", game);
}
