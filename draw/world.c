/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 10:21:00 by alhote            #+#    #+#             */
/*   Updated: 2016/03/04 15:29:59 by alhote           ###   ########.fr       */
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
