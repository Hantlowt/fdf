/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 10:21:00 by alhote            #+#    #+#             */
/*   Updated: 2016/02/16 14:17:27 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_world			*init_world(int screen_x, int screen_y, void *mlx, void *win)
{
	t_world	*result;

	result = (t_world*)malloc(sizeof(t_world));
	result->sx = screen_x;
	result->sy = screen_y;
	result->mlx = mlx;
	result->win = win;
	result->cam = init_camera(0.0, 0.0, 0.0);
	result->p = 0;
	result->seg = 0;
	return (result);
}

int				add_point(t_world *w, double x, double y, double z)
{
	if (!w)
		return (0);
	w->p = init_point(x, y, z, (w->p ? w->p : 0));
	return (1);
}

int				add_segment_with_last_pts(t_world *w)
{
	if (!w || !w->p)
		return (0);
	w->seg = init_segment(w->p, w->p->prev, (w->seg ? w->seg : 0));
	return (1);
}

int				update_world_projection(t_world *w)
{
	t_point	*p;

	if (!w->p)
		return (0);
	p = w->p;
	while (p)
	{
		project3dto2d_point(p, w->cam, w);
		p = p->prev;
	}
	return (1);
}

int				draw_world(t_world *w)
{
	t_segment	*s;

	if (!w || !w->seg)
		return (0);
	s = w->seg;
	while (s)
	{
		draw_segment(s, w);
		s = s->prev;
	}
	return (1);
}

int				rotate(t_world *w, double rx, double ry, double rz)
{
	t_point	*cur;
	double	tx;
	double	ty;
	double	tz;

	cur = w->p;
	while (cur)
	{
		tx = cur->x3d * cosf(rz) - cur->y3d * sin(rz);
		ty = cur->x3d * sin(rz) + cur->y3d * cos(rz);
		cur->x3d = tx;
		cur->y3d = ty;
		tz = cur->z3d * cosf(ry) - cur->x3d * sin(ry);
		tx = cur->z3d * sin(ry) + cur->x3d * cos(ry);
		cur->z3d = tz;
		cur->x3d = tx;
		ty = cur->y3d * cosf(rx) - cur->z3d * sin(rx);
		tz = cur->y3d * sin(rx) + cur->z3d * cos(rx);
		cur->y3d = ty;
		cur->z3d = tz;
		cur = cur->prev;
	}
	return (1);
}
