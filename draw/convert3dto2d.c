/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert3dto2d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 14:46:19 by alhote            #+#    #+#             */
/*   Updated: 2016/02/19 13:35:06 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

int				project3dto2d_point(t_point *p, t_camera *cam, t_world *w)
{
	double	d[3];

	if (!p || !cam)
		return (0);
	d[2] = cospc(cam->panx) * (cospc(cam->pany) * (p->z3d - cam->z3d)
	+ sinpc(cam->pany) * (sinpc(cam->panz) * (p->y3d - cam->y3d) +
	cospc(cam->panz) * (p->x3d - cam->x3d))) - sinpc(cam->panx) *
	(cospc(cam->panz) * (p->y3d - cam->y3d) - sinpc(cam->panz) *
	(p->x3d - cam->x3d));
	if (d[2] > 0.0)
	{
		d[0] = cospc(cam->pany) * (sinpc(cam->panz) * (p->y3d - cam->y3d) +
		cospc(cam->panz) * (p->x3d - cam->x3d)) - sinpc(cam->pany) *
		(p->z3d - cam->z3d);
		d[1] = sinpc(cam->panx) * (cospc(cam->pany) * (p->z3d - cam->z3d) +
		sinpc(cam->pany) * (sinpc(cam->panz) * (p->y3d - cam->y3d) +
		cospc(cam->panz) * (p->x3d - cam->x3d))) + cospc(cam->panx) *
		(cospc(cam->panz) * (p->y3d - cam->y3d) - sinpc(cam->panz) *
		(p->x3d - cam->x3d));
		p->x2d = ((cam->vz / (d[2])) * d[0] + cam->vx) * cam->zoom + w->sx / 2;
		p->y2d = ((cam->vz / (d[2])) * d[1] + cam->vy) * cam->zoom + w->sy / 2;
	}
	p->enable = (d[2] > 0 ? 1 : 0);
	return (1);
}
