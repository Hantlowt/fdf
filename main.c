/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 12:09:59 by alhote            #+#    #+#             */
/*   Updated: 2016/03/06 19:43:11 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <mlx.h>
#include "libft.h"
#include "draw.h"
#include "fdf.h"

int				main(int argc, char **argv)
{
	t_world	*w;
	t_map	*map;

	map = 0;
	w = init_world(1920, 1080, mlx_init(), 0);
	w->win = mlx_new_window(w->mlx, w->sx, w->sy, "FdF");
	if (argc == 2)
		map = init_map(argv[1], w);
	if (map && argc == 2)
	{
		mlx_hook(w->win, 6, (1L << 6), mouse_motion, w);
		mlx_hook(w->win, 2, (1L << 0), key, w);
		w->cam->x3d = 0.0;
		w->cam->y3d = 0.0;
		w->cam->z3d = -9.0;
		w->pa = map;
		update_world_projection(w);
		draw_world(w);
		mlx_loop(w->mlx);
	}
	ft_putstr("error\n");
	return (0);
}
