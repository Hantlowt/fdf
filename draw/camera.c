/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 14:59:38 by alhote            #+#    #+#             */
/*   Updated: 2016/02/25 21:02:12 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void			cam_move_forward(t_camera *c, double s)
{
	double	pi;

	pi = 3.14159265359;
	c->pany = efmod(c->pany + 50.0, 360.0);
	c->x3d -= s * (cospc(c->pany) - sinpc(c->pany));
	c->z3d += s * (sinpc(c->pany) + cospc(c->pany));
	c->pany = efmod(c->pany - 50.0, 360.0);
}

t_camera		*init_camera(double x, double y, double z)
{
	t_camera	*cam;

	cam = (t_camera*)malloc(sizeof(t_camera));
	cam->x3d = x;
	cam->y3d = y;
	cam->z3d = z;
	cam->vx = 0.0;
	cam->vy = 0.0;
	cam->vz = -10.0;
	cam->panx = 0.0;
	cam->pany = 0.0;
	cam->panz = 0.0;
	cam->zoom = 90.0;
	return (cam);
}
