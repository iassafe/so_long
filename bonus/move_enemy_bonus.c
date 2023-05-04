/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:19:30 by iassafe           #+#    #+#             */
/*   Updated: 2023/05/04 11:52:00 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_right(t_data *dt, int y, int x)
{
	if (dt->map[y][x + 1] == '0')
	{
		dt->map[y][x + 1] = 'T';
		dt->map[y][x] = '0';
		mlx_put_image_to_window(dt->mlx, dt->new, dt->floor, x * 64, y * 64);
		mlx_put_image_to_window(dt->mlx,
			dt->new, dt->tom, (x + 1) * 64, y * 64);
		x++;
	}
	if (dt->map[y][x + 1] == 'P')
	{
		write(1, "<<<<<<👎👎👎👎👎👎👎👎👎!!!>>>>>>\n", 52);
		destroy_exit(dt);
	}
}

void	ft_move_1(t_data *dt)
{
	int	y;
	int	x;

	y = 0;
	while (dt->map[y])
	{
		x = 0;
		while (dt->map[y][x])
		{
			if (dt->map[y][x] == 'T')
			{
				ft_right(dt, y, x);
				break ;
			}
			x++;
		}
		y++;
	}
}

void	ft_left(t_data *dt, int y, int x)
{
	if (dt->map[y][x - 1] == '0')
	{
		dt->map[y][x - 1] = 'T';
		dt->map[y][x] = '0';
		mlx_put_image_to_window(dt->mlx, dt->new, dt->floor, x * 64, y * 64);
		mlx_put_image_to_window(dt->mlx, dt->new,
			dt->tom, (x - 1) * 64, y * 64);
	}
	if (dt->map[y][x - 1] == 'P')
	{
		write(1, "<<<<<<👎👎👎👎👎👎👎👎👎!!!>>>>>>\n", 52);
		destroy_exit(dt);
	}
}

void	ft_move_2(t_data *dt)
{
	int	y;
	int	x;

	y = 0;
	while (dt->map[y])
	{
		x = 0;
		while (dt->map[y][x])
		{
			if (dt->map[y][x] == 'T')
			{
				ft_left(dt, y, x);
			}
			x++;
		}
		y++;
	}
}

int	animation(t_data *dt)
{
	dt->count++;
	if (dt->count == 5000 && dt->hold == 0)
	{
		ft_move_2(dt);
		dt->hold = 1;
		dt->count = 0;
	}
	if (dt->count == 5000 && dt->hold == 1)
	{
		ft_move_1(dt);
		dt->hold = 0;
		dt->count = 0;
	}
	return (0);
}
