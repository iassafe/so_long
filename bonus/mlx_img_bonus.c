/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:12:52 by iassafe           #+#    #+#             */
/*   Updated: 2023/04/16 14:28:53 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	dt->hole2 = mlx_xpm_file_to_image(dt->mlx, "baab.xpm", &w, &h);
	if (dt->hole2 == NULL)
		exit(1);
	dt->tom = mlx_xpm_file_to_image(dt->mlx, "Tom.xpm", &w, &h);
	if (dt->tom == NULL)
		exit(1);
}

void	ft_mlx_image_exit(t_data *dt)
{
	dt->i = 0;
	while (dt->map[dt->i])
	{
		dt->j = 0;
		while (dt->map[dt->i][dt->j])
		{
			if (dt->map[dt->i][dt->j] == 'E')
				mlx_put_image_to_window(dt->mlx, dt->new,
					dt->hole2, dt->j * 64, dt->i * 64);
			dt->j++;
		}
		dt->i++;
	}
}

void	ft_mlx_tom(t_data *dt)
{
	dt->i = 0;
	while (dt->map[dt->i])
	{
		dt->j = 0;
		while (dt->map[dt->i][dt->j])
		{
			if (dt->map[dt->i][dt->j] == 'T')
				mlx_put_image_to_window(dt->mlx, dt->new,
					dt->tom, dt->j * 64, dt->i * 64);
			dt->j++;
		}
		dt->i++;
	}
}

void	ft_move_str(t_data *dt)
{
	char	*str;

	str = ft_itoa(dt->move);
	mlx_string_put(dt->mlx, dt->new, 25, 22, 00000000, str);
	free(str);
}

void	ft_mlx_image(t_data *dt)
{
	dt->i = -1;
	while (dt->map[++dt->i])
	{
		dt->j = -1;
		while (dt->map[dt->i][++dt->j])
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
			ft_move_str(dt);
		}
	}
}
