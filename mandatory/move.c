/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 22:11:18 by iassafe           #+#    #+#             */
/*   Updated: 2023/04/15 21:48:54 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_d(t_data *dt)
{
	dt->i = check_i_player(*dt);
	dt->j = check_j_player(*dt);
	if (dt->map[dt->i][dt->j + 1] == 'E')
	{
		if (dt->len_c == 0)
		{
			write(1, "<<<<<<👏👏👏👏👏👏👏👏👏!!!>>>>>>\n", 52);
			destroy_exit(dt);
		}
	}
	if (dt->map[dt->i][dt->j + 1] == '0'
	|| dt->map[dt->i][dt->j + 1] == 'C')
	{
		dt->move++;
		ft_putnbr(dt->move);
		ft_putstr("\n");
		move_player(dt, dt->i, dt->j + 1);
	}
	dt->j++;
}

void	move_g(t_data *dt)
{
	dt->i = check_i_player(*dt);
	dt->j = check_j_player(*dt);
	if (dt->map[dt->i][dt->j - 1] == 'E')
	{
		if (dt->len_c == 0)
		{
			write(1, "<<<<<<👏👏👏👏👏👏👏👏👏!!!>>>>>>\n", 52);
			destroy_exit(dt);
		}
	}
	if (dt->map[dt->i][dt->j - 1] == '0' ||
	dt->map[dt->i][dt->j - 1] == 'C')
	{
		dt->move++;
		ft_putnbr(dt->move);
		ft_putstr("\n");
		move_player(dt, dt->i, dt->j - 1);
	}
	dt->j++;
}

void	move_b(t_data *dt)
{
	dt->i = check_i_player(*dt);
	dt->j = check_j_player(*dt);
	if (dt->map[dt->i + 1][dt->j] == 'E')
	{
		if (dt->len_c == 0)
		{
			write(1, "<<<<<<👏👏👏👏👏👏👏👏👏!!!>>>>>>\n", 52);
			destroy_exit(dt);
		}
	}
	if (dt->map[dt->i + 1][dt->j] == '0' ||
	dt->map[dt->i + 1][dt->j] == 'C')
	{
		dt->move++;
		ft_putnbr(dt->move);
		ft_putstr("\n");
		move_player(dt, dt->i + 1, dt->j);
	}
	dt->i++;
}

void	move_h(t_data *dt)
{
	dt->i = check_i_player(*dt);
	dt->j = check_j_player(*dt);
	if (dt->map[dt->i - 1][dt->j] == 'E')
	{
		if (dt->len_c == 0)
		{
			write(1, "<<<<<<👏👏👏👏👏👏👏👏👏!!!>>>>>>\n", 52);
			destroy_exit(dt);
		}
	}
	if (dt->map[dt->i - 1][dt->j] == '0' ||
	dt->map[dt->i - 1][dt->j] == 'C')
	{
		dt->move++;
		ft_putnbr(dt->move);
		ft_putstr("\n");
		move_player(dt, dt->i - 1, dt->j);
	}
	dt->i++;
}
