/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrossi <fgrossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:23:26 by fgrossi           #+#    #+#             */
/*   Updated: 2022/03/30 11:27:55 by fgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_over(t_data *v, int i, int k)
{
	v->end = 1;
	v->matrix[i][k] = 'M';
	put_map(v);
}

int	ft_delay(int *delay, int time)
{
	if (*delay <= time)
	{
		*delay += 1;
		return (1);
	}
	*delay = 0;
	return (0);
}

void	coin_animation(t_data *v)
{
	int			i;
	int			j;
	static int	x;

	i = -1;
	if (x > 3)
		x = 0;
	if (ft_delay(&v->index, 1500) == 1)
		return ;
	while (++i < v->height)
	{
		j = -1;
		while (++j < v->width)
		{
			if (v->matrix[i][j] == 'C')
			{
				mlx_put_image_to_window(v->mlx, v->win,
					v->img[8 + x], j * 32, i * 32);
			}
		}
	}
	x += 1;
}

void	player_animation(t_data *v)
{
	int			i;
	int			j;
	static int	x;

	i = -1;
	if (x > 2)
		x = 0;
	if (ft_delay(&v->index1, 1000) == 1)
		return ;
	while (++i < v->height)
	{
		j = -1;
		while (++j < v->width)
		{
			if (v->matrix[i][j] == 'P')
			{
				mlx_put_image_to_window(v->mlx, v->win,
					v->img[12 + x], j * 32, i * 32);
			}
		}
	}
	x += 1;
}

int	check(int keycode, t_data *v)
{
	if (keycode == 36)
		v->trigger_start = 1;
	if (keycode == 53 || keycode == 12)
		quit(v);
	else if (v->trigger_start != 0)
	{
		if (v->end == 1)
			return (0);
		if (keycode == 13 || keycode == 126)
			move_up(v);
		if (keycode == 0 || keycode == 123)
			move_left(v);
		if (keycode == 1 || keycode == 125)
			move_down(v);
		if (keycode == 2 || keycode == 124)
			move_right(v);
		put_map(v);
		return (1);
	}
	return (0);
}
