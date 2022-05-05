/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrossi <fgrossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:46:23 by fgrossi           #+#    #+#             */
/*   Updated: 2022/03/30 13:13:02 by fgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Incl/so_long.h"

bool	check_walls(t_data v)
{
	int	i;

	i = 0;
	while (i < v.width)
	{
		if (v.matrix[0][i] != '1')
			return (false);
		i++;
	}
	i = -1;
	while (++i < v.width)
	{
		if (v.matrix[v.height - 1][i] != '1')
			return (false);
	}
	i = 1;
	while (i < v.height - 1)
	{
		if (v.matrix[i][0] != '1')
			return (false);
		if (v.matrix[i][v.width - 1] != '1')
			return (false);
		i++;
	}
	return (true);
}

bool	check_exit_and_player(t_data *v)
{
	v->x = -1;
	while (++v->x < v->height)
	{
		v->y = -1;
		while (++v->y < v->width)
		{
			if (v->matrix[v->x][v->y] == 'P')
			{
				v->i = v->x;
				v->j = v->y;
				v->check_p++;
			}
			if (v->matrix[v->x][v->y] == 'M')
				v->monsters++;
			if (v->matrix[v->x][v->y] == 'E')
				v->check_e++;
			if (v->matrix[v->x][v->y] == 'C')
				v->coin++;
		}
	}
	if (v->check_p != 1 || v->check_e < 1 || v->coin == 0)
		return (false);
	return (true);
}

bool	check_different(t_data v)
{
	int	i;
	int	j;

	i = -1;
	while (++i < v.height)
	{
		j = -1;
		while (++j < v.width)
		{
			if (v.matrix[i][j] != '1' && v.matrix[i][j] != 'C'
			&& v.matrix[i][j] != 'M' && v.matrix[i][j] != 'P'
			&& v.matrix[i][j] != 'E' && v.matrix[i][j] != '0')
				return (false);
		}
	}
	return (true);
}

void	put_map2(t_data *v, int i, int j)
{
	if (v->matrix[i][j] == '0')
		mlx_put_image_to_window(v->mlx, v->win, v->img[0], j * 32, i * 32);
	if (v->matrix[i][j] == '1')
	{
		if (i == 0 && j < 2 && v->bricks != 0)
		{
			j++;
			return ;
			v->bricks = 0;
		}
		else
			mlx_put_image_to_window(v->mlx, v->win, v->img[1], j * 32, i * 32);
	}
	if (v->matrix[i][j] == 'M')
		mlx_put_image_to_window(v->mlx, v->win, v->img[3], j * 32, i * 32);
	if (v->matrix[i][j] == 'C')
		mlx_put_image_to_window(v->mlx, v->win, v->img[8], j * 32, i * 32);
	if (v->matrix[i][j] == 'P')
		mlx_put_image_to_window(v->mlx, v->win, v->img[12], j * 32, i * 32);
	if (v->coin == 0 && v->matrix[i][j] == 'E')
		mlx_put_image_to_window(v->mlx, v->win, v->img[5], j * 32, i * 32);
	else if (v->matrix[i][j] == 'E')
		mlx_put_image_to_window(v->mlx, v->win, v->img[4], j * 32, i * 32);
}

void	put_map(t_data *v)
{
	int	i;
	int	j;

	i = -1;
	while (++i < v->height)
	{
		j = -1;
		while (++j < v->width)
		{
			put_map2(v, i, j);
		}
	}
	if (v->trigger_start == 0)
		mlx_put_image_to_window(v->mlx, v->win, v->img[7],
			((v->width * 32) / 2) - 200, ((v->height * 32) / 2) - 47);
	mlx_string_put(v->mlx, v->win, 10, 30, 0xFFFFFF, "moves: ");
	mlx_string_put(v->mlx, v->win, 70, 30, 0xFFFFFF, count_moves(v));
	ft_printf("moves: %d\n", v->count_step);
	if (v->end == 1)
		mlx_put_image_to_window(v->mlx, v->win, v->img[6],
			((v->width * 32) / 2) - 200, ((v->height * 32) / 2) - 103);
}
