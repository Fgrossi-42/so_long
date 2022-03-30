/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrossi <fgrossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:46:51 by fgrossi           #+#    #+#             */
/*   Updated: 2022/03/30 12:08:52 by fgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize(t_data *var)
{
	var->check_e = 0;
	var->check_p = 0;
	var->coin = 0;
	var->monsters = 0;
	var->x = 0;
	var->y = 0;
	var->count_step = 0;
}

int	main(int argc, char **argv)
{
	t_data	v;

	if (argc == 1)
		return (0);
	initialize(&v);
	v.map = argv[1];
	if (fill_matrix(&v) == 0)
		return (0);
	v.mlx = mlx_init();
	images(&v);
	v.win = mlx_new_window(v.mlx, v.width * 32, v.height * 32, "So_Long");
	put_map(&v);
	check_monster(&v);
	v.loop = 0;
	mlx_hook(v.win, 3, 1L << 1, check, &v);
	mlx_loop_hook(v.mlx, loop_monster, &v);
	mlx_loop(v.mlx);
}
