/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 22:15:51 by iassafe           #+#    #+#             */
/*   Updated: 2023/04/27 17:43:41 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_valid_path(t_data *dt)
{
	if (!ft_valid_path_exit(dt) || ft_len_coll(dt) > 0)
		ft_error("lmap not valid");
}

void	destroy_exit(t_data *dt)
{
	mlx_destroy_window(dt->mlx, dt->new);
	exit (0);
}

int	ft_exit(void)
{
	exit(0);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int number)
{
	long	n;

	n = number;
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	if (n >= 0 && n <= 9)
	{
		ft_putchar(n + '0');
	}
}
