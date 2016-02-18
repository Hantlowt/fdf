/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 12:09:59 by alhote            #+#    #+#             */
/*   Updated: 2016/02/18 16:15:05 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "mlx.h"
#include "libft.h"
#include "draw.h"
#include "fdf.h"

int				key(int keycode, void *param)
{
	t_world	*w;

	w = param;
	mlx_clear_window(w->mlx, w->win);
	if (keycode == 123)
		w->cam->x3d = (w->cam->x3d - 0.5);
	if (keycode == 124)
		w->cam->x3d = (w->cam->x3d + 0.5);
	if (keycode == 126)
		w->cam->y3d = (w->cam->y3d + 0.5);
	if (keycode == 125)
		w->cam->y3d = (w->cam->y3d - 0.5);
	if (keycode == 53)
		exit(0);
	if (keycode == 65361 || keycode == 2)
		rotate(w, 0.0, 1.0, 0.0);
		//w->cam->x3d = (w->cam->x3d - 0.5);
	if (keycode == 65363)
		w->cam->x3d = (w->cam->x3d + 0.5);
	if (keycode == 65362)
		w->cam->y3d = (w->cam->y3d + 0.5);
	if (keycode == 65364)
		w->cam->y3d = (w->cam->y3d - 0.5);
	if (keycode == 65307)
		exit(0);
	ft_putnbr(keycode);
	ft_putendl("");
	update_world_projection(w);
	draw_world(w);
	return (0);
}

int				loop_hook(void *param)
{
	t_world	*w;

	w = param;
	rotate(w, 0.0, 0.01, 0.0);
	update_world_projection(w);
	mlx_clear_window(w->mlx, w->win);
	draw_world(w);
	return (0);
}

int				main(void)
{
	t_world	*w;
	t_map	*map;
	int x = 0;
	int y = 0;

	map = init_map("42.fdf");
	while (y < map->sizey)
	{
		while (x < map->sizex)
		{
			ft_putnbr(map->dots[y][x]);
			ft_putchar(' ');
			x++;
		}
		ft_putendl("");
		x = 0;
		y++;
	}
	w = init_world(1920, 1080, mlx_init(), 0);
	w->win = mlx_new_window(w->mlx, w->sx, w->sy, "FdF");
	mlx_key_hook(w->win, key, w);
	mlx_loop_hook(w->mlx, loop_hook, w);
	add_point(w, 3.0, 3.0, 3.0);
	add_point(w, 4.0, 3.0, 3.0);
	add_segment_with_last_pts(w);
	w->seg->color = 0xFF0000;
	add_point(w, 3.0, 4.0, 4.0);
	add_point(w, 4.0, 4.0, 4.0);
	add_segment_with_last_pts(w);
	w->seg->color = 0xFF0000;
	add_point(w, 3.0, 3.0, 4.0);
	add_point(w, 4.0, 3.0, 4.0);
	add_segment_with_last_pts(w);
	w->seg->color = 0xFF0000;
	add_point(w, 3.0, 3.0, 4.0);
	add_point(w, 4.0, 3.0, 4.0);
	add_segment_with_last_pts(w);
	w->seg->color = 0xFF0000;
	add_point(w, 3.0, 4.0, 3.0);
	add_point(w, 4.0, 4.0, 3.0);
	add_segment_with_last_pts(w);
	w->seg->color = 0xFF0000;
	add_point(w, 3.0, 3.0, 3.0);
	add_point(w, 3.0, 4.0, 3.0);
	add_segment_with_last_pts(w);
	w->seg->color = 0x00FF00;
	add_point(w, 4.0, 3.0, 3.0);
	add_point(w, 4.0, 4.0, 3.0);
	add_segment_with_last_pts(w);
	w->seg->color = 0x00FF00;
	add_point(w, 3.0, 3.0, 4.0);
	add_point(w, 3.0, 4.0, 4.0);
	add_segment_with_last_pts(w);
	w->seg->color = 0x00FF00;
	add_point(w, 4.0, 3.0, 4.0);
	add_point(w, 4.0, 4.0, 4.0);
	add_segment_with_last_pts(w);
	w->seg->color = 0x00FF00;
	add_point(w, 3.0, 3.0, 3.0);
	add_point(w, 3.0, 3.0, 4.0);
	add_segment_with_last_pts(w);
	w->seg->color = 0x0000FF;
	add_point(w, 4.0, 3.0, 3.0);
	add_point(w, 4.0, 3.0, 4.0);
	add_segment_with_last_pts(w);
	w->seg->color = 0x0000FF;
	add_point(w, 3.0, 4.0, 3.0);
	add_point(w, 3.0, 4.0, 4.0);
	add_segment_with_last_pts(w);
	w->seg->color = 0x0000FF;
	add_point(w, 4.0, 4.0, 3.0);
	add_point(w, 4.0, 4.0, 4.0);
	add_segment_with_last_pts(w);
	w->seg->color = 0x0000FF;
	w->cam->x3d = 0.0;
	w->cam->y3d = 0.0;
	w->cam->z3d = -9.0;
	update_world_projection(w);
	mlx_loop(w->mlx);
	return (0);
}
