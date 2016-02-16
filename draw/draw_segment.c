/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_segment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:21:15 by alhote            #+#    #+#             */
/*   Updated: 2016/02/16 15:41:39 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void		c2(t_segment *seg, t_world *w)
{
	int	i;
	int	cumul;
	int	pos[2];
	int	inc[2];

	i = 0;
	cumul = fabs(seg->p[1]->y2d - seg->p[0]->y2d) / 2;
	pos[0] = seg->p[0]->x2d;
	pos[1] = seg->p[0]->y2d;
	inc[0] = (seg->p[1]->x2d - seg->p[0]->x2d > 0) ? 1 : -1;
	inc[1] = (seg->p[1]->y2d - seg->p[0]->y2d > 0) ? 1 : -1;
	while (i <= fabs(seg->p[1]->y2d - seg->p[0]->y2d))
	{
		pos[1] += inc[1];
		cumul += fabs(seg->p[1]->x2d - seg->p[0]->x2d);
		if (cumul >= fabs(seg->p[1]->y2d - seg->p[0]->y2d))
		{
			cumul -= fabs(seg->p[1]->y2d - seg->p[0]->y2d);
			pos[0] += inc[0];
		}
		safe_pixel_put(w, pos[0], pos[1], seg->color);
		++i;
	}
}

static void		c1(t_segment *seg, t_world *w)
{
	int	i;
	int	cumul;
	int	pos[2];
	int	inc[2];

	i = 0;
	cumul = fabs(seg->p[1]->x2d - seg->p[0]->x2d) / 2;
	pos[0] = seg->p[0]->x2d;
	pos[1] = seg->p[0]->y2d;
	inc[0] = (seg->p[1]->x2d - seg->p[0]->x2d > 0) ? 1 : -1;
	inc[1] = (seg->p[1]->y2d - seg->p[0]->y2d > 0) ? 1 : -1;
	while (i <= fabs(seg->p[1]->x2d - seg->p[0]->x2d))
	{
		pos[0] += inc[0];
		cumul += fabs(seg->p[1]->y2d - seg->p[0]->y2d);
		if (cumul >= fabs(seg->p[1]->x2d - seg->p[0]->x2d))
		{
			cumul -= fabs(seg->p[1]->x2d - seg->p[0]->x2d);
			pos[1] += inc[1];
		}
		safe_pixel_put(w, pos[0], pos[1], seg->color);
		++i;
	}
}

int				draw_segment(t_segment *seg, t_world *w)
{
	if (seg->p[0]->enable && seg->p[1]->enable)
	{
		safe_pixel_put(w, seg->p[0]->x2d, seg->p[0]->y2d, seg->color);
		if (fabs(seg->p[1]->x2d - seg->p[0]->x2d) >
		fabs(seg->p[1]->y2d - seg->p[0]->y2d))
		{
			c1(seg, w);
		}
		else
		{
			c2(seg, w);
		}
	}
	return (0);
}

t_segment		*init_segment(t_point *p1, t_point *p2, t_segment *prev)
{
	t_segment	*seg;

	seg = (t_segment*)malloc(sizeof(t_segment));
	seg->p = (t_point**)malloc(sizeof(t_point*) * 2);
	seg->p[0] = p1;
	seg->p[1] = p2;
	seg->color = 0xFFFFFF;
	seg->prev = prev;
	seg->next = 0;
	if (prev)
		prev->next = seg;
	return (seg);
}
