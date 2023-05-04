/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:53:07 by iassafe           #+#    #+#             */
/*   Updated: 2023/04/17 12:55:17 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_check_map(t_data *dt)
{
	dt->i = -1;
	dt->len_c = 0;
	dt->len_e = 0;
	dt->len_p = 0;
	dt->len_t = 0;
	while (dt->map[++dt->i])
	{
		dt->j = 0;
		while (dt->map[dt->i][dt->j])
		{
			if (dt->map[dt->i][dt->j] == 'C')
				dt->len_c++;
			else if (dt->map[dt->i][dt->j] == 'E')
				dt->len_e++;
			else if (dt->map[dt->i][dt->j] == 'P')
				dt->len_p++;
			else if (dt->map[dt->i][dt->j] == 'T')
				dt->len_t++;
			dt->j++;
		}
	}
	if (dt->len_t == 0 || dt->len_c == 0 || dt->len_e == 0 || dt->len_p == 0)
		ft_error("Error\n❌❌C E P T");
	else if (dt->len_e > 1 || dt->len_p > 1)
		ft_error("Error\n❌1 E 1 P");
}

void	ft_check_cont(t_data *dt)
{
	dt->i = 0;
	while (dt->map[dt->i])
	{
		dt->j = 0;
		while (dt->map[dt->i][dt->j])
		{
			if (dt->map[dt->i][dt->j] != '1'
			&& dt->map[dt->i][dt->j] != '0'
			&& dt->map[dt->i][dt->j] != 'P'
			&& dt->map[dt->i][dt->j] != 'E'
			&& dt->map[dt->i][dt->j] != 'C'
			&& dt->map[dt->i][dt->j] != 'T')
			{
				ft_error("Error\n❌ char");
			}
			dt->j++;
		}
		dt->i++;
	}
}

void	ft_check_format(t_data *dt)
{
	dt->len_j = 0;
	while (dt->map[0][dt->len_j] && dt->map[0][dt->len_j] != '\n')
		dt->len_j++;
	if (dt->len_j > 256)
		ft_error("❌❌long");
	dt->i = 1;
	while (dt->map[dt->i])
	{
		dt->j = 0;
		while (dt->map[dt->i][dt->j])
			dt->j++;
		if (dt->j != dt->len_j)
			ft_error("Error\n❌rectangle");
		dt->j = 0;
		dt->i++;
	}
}

int	len_one(t_data *dt)
{
	dt->len_j = 0;
	dt->j = 0;
	while (dt->map[0][dt->j])
	{
		if (dt->map[0][dt->j] != '1')
			ft_error("Error\n❌ one line 1");
		dt->len_j++;
		dt->j++;
	}
	return (dt->len_j);
}

void	ft_check_1(t_data *dt)
{
	dt->len_j = len_one(dt);
	dt->len_i = 0;
	dt->i = 1;
	while (dt->map[dt->i])
	{
		dt->len_i++;
		if (dt->map[dt->i][0] != '1' || dt->map[dt->i][dt->len_j - 1] != '1')
			ft_error("Error\n1❌1");
		dt->i++;
	}
	if ((dt->len_i + 1) > 256)
		ft_error("❌❌long");
	dt->j = 0;
	while (dt->j < dt->len_j)
	{
		if (dt->map[dt->len_i][dt->j] != '1')
			ft_error("Error\n❌111");
		dt->j++;
	}
}
