/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrossi <fgrossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:46:39 by fgrossi           #+#    #+#             */
/*   Updated: 2022/03/30 11:51:58 by fgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	quit(t_data *v)
{
	mlx_destroy_window(v->mlx, v->win);
	exit (0);
}

void	move_right(t_data *v)
{
	if (v->matrix[v->i][v->j + 1] == '1')
		return ;
	else if (v->matrix[v->i][v->j + 1] == 'M')
	{
		v->matrix[v->i][v->j] = '0';
		return (game_over(v, v->i, v->j + 1));
	}
	else if (v->matrix[v->i][v->j + 1] == 'C')
	{
		v->coin--;
		v->matrix[v->i][v->j] = '0';
		v->matrix[v->i][v->j + 1] = 'P';
	}
	else if (v->matrix[v->i][v->j + 1] == 'E' && v->coin == 0)
		return (quit(v));
	else if (v->matrix[v->i][v->j + 1] == 'E')
		return ;
	else
	{
		v->matrix[v->i][v->j] = '0';
		v->matrix[v->i][v->j + 1] = 'P';
	}
	v->count_step++;
	v->j++;
}

void	move_left(t_data *v)
{
	if (v->matrix[v->i][v->j - 1] == '1')
		return ;
	else if (v->matrix[v->i][v->j - 1] == 'M')
	{
		v->matrix[v->i][v->j] = '0';
		return (game_over(v, v->i, v->j - 1));
	}
	else if (v->matrix[v->i][v->j - 1] == 'C')
	{
		v->coin--;
		v->matrix[v->i][v->j] = '0';
		v->matrix[v->i][v->j - 1] = 'P';
	}
	else if (v->matrix[v->i][v->j - 1] == 'E' && v->coin == 0)
		return (quit(v));
	else if (v->matrix[v->i][v->j - 1] == 'E')
		return ;
	else
	{
		v->matrix[v->i][v->j] = '0';
		v->matrix[v->i][v->j - 1] = 'P';
	}
	v->count_step++;
	v->j--;
}

void	move_up(t_data *v)
{
	if (v->matrix[v->i - 1][v->j] == '1')
		return ;
	else if (v->matrix[v->i - 1][v->j] == 'M')
	{
		v->matrix[v->i][v->j] = '0';
		return (game_over(v, v->i - 1, v->j));
	}
	else if (v->matrix[v->i - 1][v->j] == 'C')
	{
		v->coin--;
		v->matrix[v->i][v->j] = '0';
		v->matrix[v->i - 1][v->j] = 'P';
	}
	else if (v->matrix[v->i - 1][v->j] == 'E' && v->coin == 0)
		return (quit(v));
	else if (v->matrix[v->i - 1][v->j] == 'E')
		return ;
	else
	{
		v->matrix[v->i][v->j] = '0';
		v->matrix[v->i - 1][v->j] = 'P';
	}
	v->count_step++;
	v->i--;
}

void	move_down(t_data *v)
{
	if (v->matrix[v->i + 1][v->j] == '1')
		return ;
	else if (v->matrix[v->i + 1][v->j] == 'M')
	{
		v->matrix[v->i][v->j] = '0';
		return (game_over(v, v->i + 1, v->j));
	}
	else if (v->matrix[v->i + 1][v->j] == 'C')
	{
		v->coin--;
		v->matrix[v->i][v->j] = '0';
		v->matrix[v->i + 1][v->j] = 'P';
	}
	else if (v->matrix[v->i + 1][v->j] == 'E' && v->coin == 0)
		return (quit(v));
	else if (v->matrix[v->i + 1][v->j] == 'E')
		return ;
	else
	{
		v->matrix[v->i][v->j] = '0';
		v->matrix[v->i + 1][v->j] = 'P';
	}
	v->count_step++;
	v->i++;
}
