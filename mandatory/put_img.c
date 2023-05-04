/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:42:35 by iassafe           #+#    #+#             */
/*   Updated: 2023/04/25 20:39:13 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

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

void	ft_file_to_img(t_data *dt)
{
	int		h;
	int		w;

	dt->jerry = mlx_xpm_file_to_image(dt->mlx, "far.xpm", &w, &h);
	if (dt->jerry == NULL)
		exit(1);
	dt->floor = mlx_xpm_file_to_image(dt->mlx, "plank-floor.xpm", &w, &h);
	if (dt->floor == NULL)
		exit(1);
	dt->cheese = mlx_xpm_file_to_image(dt->mlx, "jobn.xpm", &w, &h);
	if (dt->cheese == NULL)
		exit(1);
	dt->walls = mlx_xpm_file_to_image(dt->mlx, "wall2.xpm", &w, &h);
	if (dt->walls == NULL)
		exit(1);
	dt->hole = mlx_xpm_file_to_image(dt->mlx, "zaz.xpm", &w, &h);
	if (dt->hole == NULL)
		exit(1);
}

void	ft_mlx_image(t_data *dt)
{
	dt->i = 0;
	while (dt->map[dt->i])
	{
		dt->j = 0;
		while (dt->map[dt->i][dt->j])
		{
			if (dt->map[dt->i][dt->j] == 'P')
				mlx_put_image_to_window(dt->mlx, dt->new,
					dt->jerry, dt->j * 64, dt->i * 64);
			if (dt->map[dt->i][dt->j] == '0')
				mlx_put_image_to_window(dt->mlx, dt->new,
					dt->floor, dt->j * 64, dt->i * 64);
			if (dt->map[dt->i][dt->j] == 'C')
				mlx_put_image_to_window(dt->mlx, dt->new,
					dt->cheese, dt->j * 64, dt->i * 64);
			if (dt->map[dt->i][dt->j] == '1')
				mlx_put_image_to_window(dt->mlx, dt->new,
					dt->walls, dt->j * 64, dt->i * 64);
			if (dt->map[dt->i][dt->j] == 'E')
				mlx_put_image_to_window(dt->mlx, dt->new,
					dt->hole, dt->j * 64, dt->i * 64);
			dt->j++;
		}
		dt->i++;
	}
}

void	ft_mlx(t_data dt)
{
	dt.mlx = mlx_init();
	if (!dt.mlx)
		exit(1);
	dt.new = mlx_new_window(dt.mlx, dt.len_j * 64,
			(dt.len_i + 1) * 64, "so_long");
	if (!dt.new)
		exit(1);
	ft_file_to_img(&dt);
	ft_mlx_image(&dt);
	mlx_hook(dt.new, 2, 0, &keypress, &dt);
	mlx_hook(dt.new, 17, 0, ft_exit, &dt);
	mlx_loop(dt.mlx);
}
