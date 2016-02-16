/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert3dto2d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 14:46:19 by alhote            #+#    #+#             */
/*   Updated: 2016/02/16 15:31:24 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

int				project3dto2d_point(t_point *p, t_camera *cam, t_world *w)
{
	double	d[3];
	double	pi;

	if (!p || !cam)
		return (0);
	pi = 3.14159265359;
	d[0] = cosf(cam->pany * pi / 180) * (sinf(cam->panz * pi / 180) *
	(p->y3d - cam->y3d) + cosf(cam->panz * pi / 180) * (p->x3d - cam->x3d)) -
	sinf(cam->pany * pi / 180) * (p->z3d - cam->z3d);
	d[1] = sinf(cam->panx * pi / 180) * (cosf(cam->pany * pi / 180) *
	(p->z3d - cam->z3d) + sinf(cam->pany * pi / 180) *
	(sinf(cam->panz * pi / 180) * (p->y3d - cam->y3d) +
	cosf(cam->panz * pi / 180) * (p->x3d - cam->x3d))) +
	cosf(cam->panx * pi / 180) * (cosf(cam->panz * pi / 180) *
	(p->y3d - cam->y3d) - sinf(cam->panz * pi / 180) * (p->x3d - cam->x3d));
	d[2] = cosf(cam->panx * pi / 180) * (cosf(cam->pany * pi / 180) *
	(p->z3d - cam->z3d) + sinf(cam->pany * pi / 180) *
	(sinf(cam->panz * pi / 180) * (p->y3d - cam->y3d) +
	cosf(cam->panz * pi / 180) * (p->x3d - cam->x3d))) -
	sinf(cam->panx * pi / 180) * (cosf(cam->panz * pi / 180) *
	(p->y3d - cam->y3d) - sinf(cam->panz * pi / 180) * (p->x3d - cam->x3d));
	p->x2d = ((cam->vz / (d[2])) * d[0] + cam->vx) * cam->zoom + w->sx / 2;
	p->y2d = ((cam->vz / (d[2])) * d[1] + cam->vy) * cam->zoom + w->sy / 2;
	return (1);
}
