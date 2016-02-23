/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 15:52:19 by alhote            #+#    #+#             */
/*   Updated: 2016/02/23 21:11:53 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

int				safe_pixel_put(t_world *w, int x, int y, int color)
{
	if (x > w->sx || y > w->sy || x < 0 || y < 0)
		return (0);
	mlx_pixel_put(w->mlx, w->win, x, y, color);
	return (1);
}

int				draw_point(t_point *point, t_world *w)
{
	if (point->enable)
		safe_pixel_put(w, (int)point->x2d, (int)point->y2d, point->color);
	return (0);
}

int				next_color(int color, int final, int dist)
{
	int	r;
	int	g;
	int	b;

	r = (color & 0xFF0000) >> 16;
	r += ((((color & 0xFF0000) >> 16) - ((final & 0xFF0000) >> 16))) * dist;
	g = (color & 0x00FF00) >> 8;
	g += ((((color & 0x00FF00) >> 8) - ((final & 0x00FF00) >> 8))) * dist;
	b = (color & 0x0000FF);
	b += (((color & 0x0000FF) - (final & 0x0000FF))) * dist;
	return ((r << 16) + (g << 8) + b);
}

t_point			*init_point(double x, double y, double z, t_point *prev)
{
	t_point	*point;

	point = (t_point*)malloc(sizeof(t_point));
	point->x2d = x;
	point->y2d = y;
	point->x3d = x;
	point->y3d = y;
	point->z3d = z;
	point->enable = 0;
	point->color = 0xFFFFFF;
	point->next = 0;
	point->prev = prev;
	if (prev)
		prev->next = point;
	return (point);
}
