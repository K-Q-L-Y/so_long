/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_steps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:31:02 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/08/13 20:28:43 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_steps(t_game *game, int win)
{
	char	*steps;
	char	*s;

	steps = ft_itoa(game->player.steps);
	s = ft_strjoin("Steps taken: ", steps);
	if (win)
		ft_putendl_fd("YOU WON!!", 1);
	else
		ft_putendl_fd("You lost... Try harder next time...", 1);
	ft_putendl_fd(s, 1);
	free(steps);
	free(s);
}
