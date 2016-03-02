/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 12:09:59 by alhote            #+#    #+#             */
/*   Updated: 2016/02/27 18:23:20 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "mlx.h"
#include "libft.h"
#include "draw.h"
#include "fdf.h"

int				key(int keycode, void *param)
{
	t_world	*w;

	w = param;
	mlx_clear_window(w->mlx, w->win);
	if (keycode == 123 || keycode == 100)
		cam_move_lateral(w->cam, 0.5);
	if (keycode == 124 || keycode == 113)
		cam_move_lateral(w->cam, -0.5);
	if (keycode == 126)
		w->cam->y3d = (w->cam->y3d + 0.5);
	if (keycode == 125)
		w->cam->y3d = (w->cam->y3d - 0.5);
	if (keycode == 16 || keycode == 121)
		w->h += 0.1;
	if (keycode == 4 || keycode == 104)
		w->h -= 0.1;
	if (keycode == 13 || keycode == 122)
		cam_move_forward(w->cam, 0.5);
	if (keycode == 1 || keycode == 115)
		cam_move_forward(w->cam, -0.5);
	if (keycode == 53)
		exit(0);
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
	static clock_t c;

	w = param;
	w->dt = (double)(clock() - c) / CLOCKS_PER_SEC;
	c = clock();
	//rotate(w, 0.0, 5.0, 0.0);
	//update_world_projection(w);
	//mlx_clear_window(w->mlx, w->win);
	//draw_world(w);
	return (0);
}

int				mouse_motion(int x, int y, void *param)
{
	t_world	*w;
	static int	*bx;
	static int	*by;

	if (!bx || !by)
	{
		bx = (int*)malloc(sizeof(int));
		by = (int*)malloc(sizeof(int));
		return (0);
	}
	w = param;
	w->cam->pany = efmod((w->cam->pany - (x - *bx) * 1 / 2), 360.0);
	w->cam->panx = efmod((w->cam->panx - (*by - y) * 1 / 2), 360.0);
	*bx = x;
	*by = y;
	update_world_projection(w);
	mlx_clear_window(w->mlx, w->win);
	draw_world(w);
	return (0);
}

int				main(int argc, char **argv)
{
	t_world	*w;
	t_map	*map;

	if (argc > 1)
		map = init_map(argv[1]);
	else
		map = init_map("test_maps/42.fdf");
	w = init_world(1920/2, 1080/2, mlx_init(), 0);
	w->win = mlx_new_window(w->mlx, w->sx, w->sy, "FdF");
	mlx_key_hook(w->win, key, w);
	mlx_loop_hook(w->mlx, loop_hook, w);
	mlx_hook(w->win, 6, (1L<<6), mouse_motion, w);
	map_to_world(map, w);
	w->cam->x3d = 0.0;
	w->cam->y3d = 0.0;
	w->cam->z3d = -9.0;
	update_world_projection(w);
	draw_world(w);
	mlx_loop(w->mlx);
	return (0);
}
