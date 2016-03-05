/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_segment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:21:15 by alhote            #+#    #+#             */
/*   Updated: 2016/03/04 15:59:27 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static int		c2(t_segment *s, t_world *w)
{
	int	i;
	int	cumul;
	int	pos[2];
	int	inc[2];

	i = 0;
	cumul = fabs(s->p[1]->y2d - s->p[0]->y2d) / 2;
	pos[0] = s->p[0]->x2d;
	pos[1] = s->p[0]->y2d;
	inc[0] = (s->p[1]->x2d - s->p[0]->x2d > 0) ? 1 : -1;
	inc[1] = (s->p[1]->y2d - s->p[0]->y2d > 0) ? 1 : -1;
	while (i <= fabs(s->p[1]->y2d - s->p[0]->y2d))
	{
		pos[1] += inc[1];
		cumul += fabs(s->p[1]->x2d - s->p[0]->x2d);
		if (cumul >= fabs(s->p[1]->y2d - s->p[0]->y2d))
		{
			cumul -= fabs(s->p[1]->y2d - s->p[0]->y2d);
			pos[0] += inc[0];
		}
		if (!safe_pixel_put(w, pos[0], pos[1], s->p[0]->color + s->p[1]->color))
			return (0);
		++i;
	}
	return (0);
}

static int		c1(t_segment *s, t_world *w)
{
	int	i;
	int	cumul;
	int	pos[2];
	int	inc[2];

	i = 0;
	cumul = fabs(s->p[1]->x2d - s->p[0]->x2d) / 2;
	pos[0] = s->p[0]->x2d;
	pos[1] = s->p[0]->y2d;
	inc[0] = (s->p[1]->x2d - s->p[0]->x2d > 0) ? 1 : -1;
	inc[1] = (s->p[1]->y2d - s->p[0]->y2d > 0) ? 1 : -1;
	while (i <= fabs(s->p[1]->x2d - s->p[0]->x2d))
	{
		pos[0] += inc[0];
		cumul += fabs(s->p[1]->y2d - s->p[0]->y2d);
		if (cumul >= fabs(s->p[1]->x2d - s->p[0]->x2d))
		{
			cumul -= fabs(s->p[1]->x2d - s->p[0]->x2d);
			pos[1] += inc[1];
		}
		if (!safe_pixel_put(w, pos[0], pos[1], s->p[0]->color + s->p[1]->color))
			return (0);
		++i;
	}
	return (0);
}

int				draw_segment(t_segment *s, t_world *w)
{
	if (s->p[0]->enable | s->p[1]->enable)
	{
		safe_pixel_put(w, s->p[0]->x2d, s->p[0]->y2d, s->p[0]->color);
		if (fabs(s->p[1]->x2d - s->p[0]->x2d) >
		fabs(s->p[1]->y2d - s->p[0]->y2d))
		{
			c1(s, w);
		}
		else
		{
			c2(s, w);
		}
	}
	return (0);
}

t_segment		*init_segment(t_point *p1, t_point *p2, t_segment *prev)
{
	t_segment	*s;

	s = (t_segment*)malloc(sizeof(t_segment));
	s->p = (t_point**)malloc(sizeof(t_point*) * 2);
	s->p[0] = p1;
	s->p[1] = p2;
	s->color = 0xFFFFFF;
	s->prev = prev;
	s->next = 0;
	if (prev)
		prev->next = s;
	return (s);
}
