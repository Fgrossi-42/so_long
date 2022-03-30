/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrossi <fgrossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:46:31 by fgrossi           #+#    #+#             */
/*   Updated: 2022/03/30 12:25:34 by fgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	fill_matrix(t_data *v)
{
	int		fd;
	char	*line;

	v->width = 0;
	v->end = 0;
	fd = open(v->map, O_RDONLY);
	line = get_next_line(fd);
	v->matrix = ft_split(line, '\n', v);
	while (v->matrix[0][v->width] != '\0')
		v->width++;
	if (!check_rectangle(*v) || !check_exit_and_player(v)
		|| !check_walls(*v) || !check_different(*v))
		return (0);
	close(fd);
	free(line);
	return (1);
}

int	check_rectangle(t_data v)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < v.height)
	{
		j = 0;
		while (v.matrix[i][j] != '\0')
			j++;
		if (j != v.width)
			return (0);
		i++;
	}
	return (1);
}

void	print_matrix(t_data *v)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < v->height)
	{
		j = 0;
		while (v->matrix[i][j] != '\0')
		{
			write(1, &v->matrix[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

char	*count_moves(t_data *v)
{
	char	*num;

	num = ft_itoa(v->count_step);
	v->count_moves = num;
	return (v->count_moves);
}
