/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_sprite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:22:05 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/08/15 22:09:33 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Create image from XPM file
t_img	ft_create_sprite(void *mlx, char *path, t_game *game)
{
	t_img	sprite;

	sprite.xpm_ptr = mlx_xpm_file_to_image(mlx, path, &sprite.x, &sprite.y);
	if (sprite.xpm_ptr == NULL)
	{
		ft_putstr_fd("Error:\n\t", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": XPM file not found\n", 2);
		ft_exit_error("", game);
	}
	return (sprite);
}
