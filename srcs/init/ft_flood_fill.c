/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:40:53 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/08/14 16:46:51 by cseng-kh         ###   ########.fr       */
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

void	ft_flood_fill(t_game *game)
{
	char	**arr;

	arr = copy_array(game->map.blocks);
	ft_free_split(game->map.y, arr);
}
