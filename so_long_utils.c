/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrossi <fgrossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:46:45 by fgrossi           #+#    #+#             */
/*   Updated: 2022/03/30 11:28:07 by fgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	images2(t_data *v)
{	
	int		x;
	int		y;

	v->path[8] = "./image/coin_anm0.xpm";
	v->path[9] = "./image/coin_anm1.xpm";
	v->path[10] = "./image/coin_anm2.xpm";
	v->path[11] = "./image/coin_anm3.xpm";
	v->path[12] = "./image/player.xpm";
	v->path[13] = "./image/player1.xpm";
	v->path[14] = "./image/player2.xpm";
	v->path[15] = "./image/player3.xpm";
	v->img[8] = mlx_xpm_file_to_image(v->mlx, v->path[8], &x, &y);
	v->img[9] = mlx_xpm_file_to_image(v->mlx, v->path[9], &x, &y);
	v->img[10] = mlx_xpm_file_to_image(v->mlx, v->path[10], &x, &y);
	v->img[11] = mlx_xpm_file_to_image(v->mlx, v->path[11], &x, &y);
	v->img[12] = mlx_xpm_file_to_image(v->mlx, v->path[12], &x, &y);
	v->img[13] = mlx_xpm_file_to_image(v->mlx, v->path[13], &x, &y);
	v->img[14] = mlx_xpm_file_to_image(v->mlx, v->path[14], &x, &y);
	v->img[15] = mlx_xpm_file_to_image(v->mlx, v->path[15], &x, &y);
}

void	images(t_data *v)
{	
	int		x;
	int		y;

	v->path = (void **)malloc(sizeof(void **) * 15);
	v->img = (void **)malloc(sizeof(void **) * 15);
	v->path[0] = "./image/background.xpm";
	v->path[1] = "./image/wall.xpm";
	v->path[2] = "./image/coin.xpm";
	v->path[3] = "./image/cops.xpm";
	v->path[4] = "./image/exit.xpm";
	v->path[5] = "./image/open_exit.xpm";
	v->path[6] = "./image/end.xpm";
	v->path[7] = "./image/start.xpm";
	v->img[0] = mlx_xpm_file_to_image(v->mlx, v->path[0], &x, &y);
	v->img[1] = mlx_xpm_file_to_image(v->mlx, v->path[1], &x, &y);
	v->img[2] = mlx_xpm_file_to_image(v->mlx, v->path[2], &x, &y);
	v->img[3] = mlx_xpm_file_to_image(v->mlx, v->path[3], &x, &y);
	v->img[4] = mlx_xpm_file_to_image(v->mlx, v->path[4], &x, &y);
	v->img[5] = mlx_xpm_file_to_image(v->mlx, v->path[5], &x, &y);
	v->img[6] = mlx_xpm_file_to_image(v->mlx, v->path[6], &x, &y);
	v->img[7] = mlx_xpm_file_to_image(v->mlx, v->path[7], &x, &y);
	images2(v);
}

void	check_monster(t_data *v)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = 0;
	k = 0;
	l = 0;
	v->mstr_arr = malloc(sizeof(int *) * v->monsters);
	while (i < v->height)
	{
		j = 0;
		while (v->matrix[i][j] != '\0')
		{
			if (v->matrix[i][j] == 'M')
			{
				v->mstr_arr[k] = malloc(sizeof(int) * 2);
				v->mstr_arr[k][l] = i;
				v->mstr_arr[k][l + 1] = j;
				k++;
			}
			j++;
		}
		i++;
	}
}

void	mstr_move(t_data *v)
{
	int	k;
	int	l;

	k = 0;
	l = 0;
	while (v->monsters > k)
	{
		v->mstr_y = v->mstr_arr[k][l];
		v->mstr_x = v->mstr_arr[k][l + 1];
		if (v->end == 0)
			find_route(v, k);
		k++;
	}
}

int	loop_monster(t_data *v)
{
	if (v->end == 0 && v->trigger_start != 0)
	{
		coin_animation(v);
		player_animation(v);
		if (v->loop++ < 5000)
			return (0);
		v->loop = 0;
		mstr_move(v);
	}
	return (0);
}
