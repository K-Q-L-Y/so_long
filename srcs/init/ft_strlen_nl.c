/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_nl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 22:05:13 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/08/15 22:59:47 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_nl(char *s)
{
	int	len;

	len = ft_strlen(s);
	if (!len)
		return (0);
	while ((len > 0) && (s[len - 1] == '\n' || s[len - 1] == '\r'))
		len -= 1;
	return (len);
}
