/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:22:09 by alhote            #+#    #+#             */
/*   Updated: 2016/03/06 19:46:03 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		move_cam(int keycode, t_camera *cam)
{
	if (keycode == 2 || keycode == 100)
		cam_move_lateral(cam, cam->s);
	if (keycode == 0 || keycode == 113)
		cam_move_lateral(cam, -cam->s);
	if (keycode == 13 || keycode == 122)
		cam_move_forward(cam, cam->s);
	if (keycode == 1 || keycode == 115)
		cam_move_forward(cam, -cam->s);
	if (keycode == 14)
		cam->y3d = (cam->y3d + cam->s);
	if (keycode == 12)
		cam->y3d = (cam->y3d - cam->s);
}

int				key(int keycode, void *param)
{
	t_world			*w;

	w = param;
	move_cam(keycode, w->cam);
	if (keycode == 16 || keycode == 121)
		w->h += 0.1;
	if (keycode == 4 || keycode == 104)
		w->h -= 0.1;
	if (keycode == 35)
		w->draw_seg = (w->draw_seg ? 0 : 1);
	if (keycode == 53)
		exit(0);
	update_world_projection(w);
	mlx_clear_window(w->mlx, w->win);
	draw_world(w);
	return (0);
}

int				mouse_motion(int x, int y, void *param)
{
	t_world		*w;
	static int	*bx;
	static int	*by;

	if (!bx || !by)
	{
		bx = (int*)malloc(sizeof(int));
		by = (int*)malloc(sizeof(int));
		*bx = x;
		*by = y;
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
