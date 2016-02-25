/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 10:21:00 by alhote            #+#    #+#             */
/*   Updated: 2016/02/25 21:23:51 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

t_world			*init_world(int screen_x, int screen_y, void *mlx, void *win)
{
	t_world	*result;

	result = (t_world*)malloc(sizeof(t_world));
	result->sx = screen_x;
	result->sy = screen_y;
	result->centerx = 0.0;
	result->centery = 0.0;
	result->centerz = 0.0;
	result->dt = 0.0;
	result->mlx = mlx;
	result->win = win;
	result->h = 0.1;
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
	if (!w || !w->p || !w->p->prev)
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
	t_point		*p;

	if (!w || !w->seg)
		return (0);
	s = w->seg;
	p = w->p;
	while (s)
	{
		draw_segment(s, w);
		s = s->prev;
	}
	while (p)
	{
		draw_point(p, w);
		p = p->prev;
	}
	return (1);
}

int				rotate(t_world *w, double rx, double ry, double rz)
{
	t_point	*cur;
	double	t[3];

	cur = w->p;
	while (cur)
	{
		cur->x3d -= w->centerx;
		cur->y3d -= w->centery;
		cur->z3d -= w->centerz;
		t[0] = cur->x3d * cospc(rz) - cur->y3d * sinpc(rz);
		t[1] = cur->x3d * sinpc(rz) + cur->y3d * cospc(rz);
		cur->x3d = t[0] + w->centerx;
		cur->y3d = t[1] + w->centery;
		t[2] = cur->z3d * cospc(ry) - cur->x3d * sinpc(ry);
		t[0] = cur->x3d * cospc(ry) + cur->z3d * sinpc(ry);
		cur->z3d = t[2] + w->centerz;
		cur->x3d = t[0] + w->centerx;
		t[1] = cur->y3d * cospc(rx) - cur->z3d * sinpc(rx);
		t[2] = cur->y3d * sinpc(rx) + cur->z3d * cospc(rx);
		cur->y3d = t[1] + w->centery;
		cur->z3d = t[2] + w->centerz;
		cur = cur->prev;
	}
	return (1);
}
