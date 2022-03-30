/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrossi <fgrossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:46:57 by fgrossi           #+#    #+#             */
/*   Updated: 2022/03/30 13:16:08 by fgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H 

# include "mlx/mlx.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_data {
	void	*mlx;
	void	*win;
	void	**img;
	void	**path;
	void	*map;
	int		j;
	int		i;
	int		height;
	int		width;
	char	**matrix;
	int		coin;
	int		check_e;
	int		check_p;
	int		count_step;
	int		mstr_x;
	int		mstr_y;
	int		loop;
	int		monsters;
	int		**mstr_arr;
	int		bricks;
	int		end;
	int		trigger_start;
	int		index;
	int		index1;
	int		x;
	int		y;
	char	*count_moves;
}				t_data;

void	quit(t_data *v);
void	move_right(t_data *v);
bool	check_walls(t_data v);
void	player_animation(t_data *v);
void	move_up(t_data *v);
void	move_down(t_data *v);
void	move_left(t_data *v);
char	*get_next_line(int fd);
int		check(int keycode, t_data *v);
void	check_map(t_data v);
int		check_size(t_data *v);
void	check_exit(t_data *v);
bool	check_different(t_data var);
char	**ft_split(char const *s, char c, t_data *v);
bool	check_exit_and_player(t_data *v);
int		loop_monster(t_data *v);
void	images(t_data *v);
int		check_rectangle(t_data v);
int		fill_matrix(t_data *v);
void	put_map(t_data *v);
int		loop_monster(t_data *v);
void	find_route(t_data *v, int k);
void	move_mstr_right(t_data *v, int k);
void	move_mstr_left(t_data *v, int k);
void	move_mstr_up(t_data *v, int k);
void	move_mstr_down(t_data *v, int k);
void	check_monster(t_data *v);
void	print_matrix(t_data *v);
void	mstr_move(t_data *v);
void	game_over(t_data *v, int i, int k);
char	*count_moves(t_data *v);
void	coin_animation(t_data *v);
void	player_animation(t_data *v);
int		ft_delay(int *delay, int time);
#endif