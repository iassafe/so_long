/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:50:33 by iassafe           #+#    #+#             */
/*   Updated: 2023/04/16 22:08:48 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include "mlx.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	3
# endif

typedef struct s_data
{
	int		move;
	int		i;
	int		j;
	char	**map;
	char	**map_copy;
	int		len_c;
	int		len_e;
	int		len_p;
	int		len_j;
	int		len_i;
	int		len_t;
	void	*new;
	void	*mlx;
	void	*jerry;
	void	*floor;
	void	*cheese;
	void	*walls;
	void	*hole;
	void	*hole2;
	void	*tom;
	int		count;
	int		x;
	int		y;
	int		hold;
}			t_data;

void	ft_file_to_img(t_data *dt);
int		animation(t_data *dt);
void	ft_right(t_data *dt, int y, int x);
void	ft_left(t_data *dt, int y, int x);
void	ft_move_1(t_data *dt);
void	ft_move_2(t_data *dt);
void	ft_move_str(t_data *dt);
char	*ft_itoa(int n);
void	ft_mlx_tom(t_data *dt);
void	destroy_exit(t_data *dt);
void	ft_mlx(t_data dt);
int		ft_exit(void);
int		check_i_player(t_data dt);
int		check_j_player(t_data dt);
void	move_player(t_data *dt, int i, int j);
int		keypress(int keycode, t_data *dt);
void	move_b(t_data *dt);
void	move_h(t_data *dt);
void	move_g(t_data *dt);
void	move_d(t_data *dt);
void	ft_parcing(t_data *dt);
void	ft_map_copy(t_data *data);
void	ft_check_1(t_data *data);
void	ft_check_format(t_data *data);
void	*ft_error(char *str);
void	ft_check_map(t_data *data);
void	ft_check_cont(t_data *data);
char	**ft_split(char const *s, char c);
void	ft_putstr(char *str);
void	ft_valid_path(t_data *dt);
int		ft_valid_path_exit(t_data *dt);
int		ft_len_coll(t_data *dt);
void	check_valid_path(t_data *dt);
void	ft_mlx_image(t_data *dt);
void	ft_mlx_image_exit(t_data *dt);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strchr(char *str, char c);
char	*ft_strjoin(char *left_str, char *buff);
char	*ft_substr(const char *s, unsigned int start, size_t len);

#endif
