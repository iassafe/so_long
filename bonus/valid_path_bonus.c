/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:01:24 by iassafe           #+#    #+#             */
/*   Updated: 2023/04/17 12:56:05 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_valid(t_data *dt, int i, int j)
{
	int	result;

	result = 0;
	if (dt->map_copy[i + 1][j] == '0' || dt->map_copy[i + 1][j] == 'C')
	{
		dt->map_copy[i + 1][j] = 'P';
		result = 1;
	}
	if (dt->map_copy[i - 1][j] == '0' || dt->map_copy[i - 1][j] == 'C')
	{
		dt->map_copy[i - 1][j] = 'P';
		result = 1;
	}
	if (dt->map_copy[i][j + 1] == '0' || dt->map_copy[i][j + 1] == 'C')
	{
		dt->map_copy[i][j + 1] = 'P';
		result = 1;
	}
	if (dt->map_copy[i][j - 1] == '0' || dt->map_copy[i][j - 1] == 'C')
	{
		dt->map_copy[i][j - 1] = 'P';
		result = 1;
	}
	return (result);
}

void	ft_map_copy(t_data *dt)
{
	dt->i = 0;
	dt->map_copy = malloc((dt->len_i + 2) * sizeof(char *));
	while (dt->map[dt->i])
	{
		dt->map_copy[dt->i] = malloc((dt->len_j + 1) * sizeof(char));
		dt->j = 0;
		while (dt->map[dt->i][dt->j])
		{
			dt->map_copy[dt->i][dt->j] = dt->map[dt->i][dt->j];
			dt->j++;
		}
		dt->map_copy[dt->i][dt->j] = '\0';
		dt->i++;
	}
	dt->map_copy[dt->i] = NULL;
}

void	ft_valid_path(t_data *dt)
{
	dt->i = 0;
	while (dt->map_copy[dt->i])
	{
		dt->j = 0;
		while (dt->map_copy[dt->i][dt->j])
		{
			if (dt->map_copy[dt->i][dt->j] == 'P'
			&& ft_valid(dt, dt->i, dt->j) == 1)
			{
				dt->i = 0;
				dt->j = 0;
			}
			dt->j++;
		}
		dt->i++;
	}
}

int	ft_valid_path_exit(t_data *dt)
{
	dt->i = 0;
	while (dt->map_copy[dt->i])
	{
		dt->j = 0;
		while (dt->map_copy[dt->i][dt->j])
		{
			if (dt->map_copy[dt->i][dt->j] == 'E'
			&& (dt->map_copy[dt->i + 1][dt->j] == 'P'
			|| dt->map_copy[dt->i - 1][dt->j] == 'P'
			|| dt->map_copy[dt->i][dt->j + 1] == 'P'
			|| dt->map_copy[dt->i][dt->j - 1] == 'P'))
				return (1);
			dt->j++;
		}
		dt->i++;
	}
	return (0);
}

int	ft_len_coll(t_data *dt)
{
	int	lenc;

	lenc = 0;
	dt->i = 0;
	while (dt->map_copy[dt->i])
	{
		dt->j = 0;
		while (dt->map_copy[dt->i][dt->j])
		{
			if (dt->map_copy[dt->i][dt->j] == 'C')
				lenc++;
			dt->j++;
		}
		dt->i++;
	}
	return (lenc);
}
