/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:58:43 by iassafe           #+#    #+#             */
/*   Updated: 2023/04/16 22:06:30 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_parcing(t_data *dt)
{
	ft_check_map(dt);
	ft_check_cont(dt);
	ft_check_format(dt);
	ft_check_1(dt);
	ft_map_copy(dt);
	ft_valid_path(dt);
	ft_valid_path_exit(dt);
	check_valid_path(dt);
}

void	ft_mlx(t_data dt)
{
	dt.mlx = mlx_init();
	if (!dt.mlx)
		exit(1);
	dt.new = mlx_new_window(dt.mlx, dt.len_j * 64,
			(dt.len_i + 1) * 64, "so_long_bonus");
	if (!dt.new)
		exit(1);
	ft_file_to_img(&dt);
	ft_mlx_image(&dt);
	ft_mlx_tom(&dt);
	mlx_hook(dt.new, 2, 0, &keypress, &dt);
	mlx_hook(dt.new, 17, 0, ft_exit, &dt);
	dt.count = 0;
	dt.hold = 0;
	mlx_loop_hook(dt.mlx, animation, &dt);
	mlx_loop(dt.mlx);
}

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
