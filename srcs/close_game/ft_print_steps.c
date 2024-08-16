/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_steps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:31:02 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/08/16 11:32:28 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_steps(t_game *game, int win)
{
	char	*steps;
	char	*s;

	if (win)
	{
		steps = ft_itoa(game->player.steps + 1);
		s = ft_strjoin("Steps taken: ", steps);
		ft_putendl_fd("YOU WON!!", 1);
		ft_putendl_fd(s, 1);
		free(steps);
		free(s);
	}
	else
		ft_putendl_fd("Exited program.", 1);
}
