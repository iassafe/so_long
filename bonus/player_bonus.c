/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:54:12 by iassafe           #+#    #+#             */
/*   Updated: 2023/04/16 14:29:35 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_i_player(t_data dt)
{
	int	y;

	y = 0;
	dt.i = 0;
	while (dt.map[dt.i])
	{
		dt.j = 0;
		while (dt.map[dt.i][dt.j])
		{
			if (dt.map[dt.i][dt.j] == 'P')
			{
				y = dt.i;
			}
			dt.j++;
		}
		dt.i++;
	}
	return (y);
}

int	check_j_player(t_data dt)
{
	int	x;

	x = 0;
	dt.i = 0;
	while (dt.map[dt.i])
	{
		dt.j = 0;
		while (dt.map[dt.i][dt.j])
		{
			if (dt.map[dt.i][dt.j] == 'P')
			{
				x = dt.j;
			}
			dt.j++;
		}
		dt.i++;
	}
	return (x);
}

int	ft_exit(void)
{
	exit(0);
}

void	move_player(t_data *dt, int i, int j)
{
	if (dt->map[i][j] == 'C')
		dt->len_c--;
	dt->map[i][j] = 'P';
	dt->map[dt->i][dt->j] = '0';
	dt->i = i;
	dt->j = j;
	ft_mlx_image(dt);
	if (dt->len_c == 0)
		ft_mlx_image_exit(dt);
}

int	keypress(int keycode, t_data *dt)
{
	if (keycode == 53)
	{
		write(1, "<<<<you closed games!>>>>\n", 27);
		mlx_destroy_window(dt->mlx, dt->new);
		exit(0);
	}
	if (keycode == 124 || keycode == 2)
		move_d(dt);
	if (keycode == 123 || keycode == 0)
		move_g(dt);
	if (keycode == 125 || keycode == 1)
		move_b(dt);
	if (keycode == 126 || keycode == 13)
		move_h(dt);
	return (0);
}
