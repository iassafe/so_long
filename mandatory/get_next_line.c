/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:59:10 by iassafe           #+#    #+#             */
/*   Updated: 2023/04/16 15:20:14 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_line_len(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*get_after_newline(char *stock)
{
	char	*tmp;
	int		a;
	int		i;

	i = 0;
	while (stock[i] != '\n')
	{
		if (stock[i] == '\0')
			return (free(stock), NULL);
		i++;
	}
	a = i + 1;
	while (stock[i] != '\0')
		i++;
	tmp = ft_substr(stock, a, i - a);
	free(stock);
	return (tmp);
}

char	*ft_read(int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(left_str, '\n') && rd_bytes > 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			if (left_str)
				free (left_str);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	free(buff);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*k;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	k = ft_read(fd, k);
	if (!k)
		return (NULL);
	line = ft_substr(k, 0, ft_line_len(k) + 1);
	k = get_after_newline(k);
	return (line);
}
