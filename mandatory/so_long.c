/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:25:56 by iassafe           #+#    #+#             */
/*   Updated: 2023/04/25 19:38:08 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h" 

void	*ft_read_map(char *file)
{
	int			fd;
	static char	*s;
	char		*line;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
	{
		ft_error("Error❌\n");
	}
	while (line != NULL)
	{
		if (line[0] == '\n')
			ft_error("Error\n❌new line");
		s = ft_strjoin(s, line);
		free(line);
		line = get_next_line(fd);
	}
	return (s);
}

int	main(int ac, char **av)
{
	t_data	dt;
	char	*str;
	int		i;

	if (ac != 2)
		ft_error("Error\n❌2 arguments");
	i = ft_strlen(av[1]);
	if (i == 4 || av[1][i - 1] != 'r' || av[1][i - 2] != 'e'
	|| av[1][i - 3] != 'b' || av[1][i - 4] != '.')
		ft_error("Error\n❌.ber");
	str = ft_read_map(av[1]);
	if (str[ft_strlen(str) - 1] == '\n')
		ft_error("Error\n❌new line");
	dt.map = ft_split(str, '\n');
	ft_parcing(&dt);
	dt.move = 0;
	ft_mlx(dt);
}
