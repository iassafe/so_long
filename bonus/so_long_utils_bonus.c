/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:56:29 by iassafe           #+#    #+#             */
/*   Updated: 2023/04/16 22:08:10 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	*ft_error(char *str)
{
	ft_putstr(str);
	exit(1);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] && (i < dstsize - 1))
	{
		dst[i] = src[i];
			i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return ;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
