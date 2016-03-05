/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 14:59:38 by alhote            #+#    #+#             */
/*   Updated: 2016/03/04 19:02:22 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void			cam_move_forward(t_camera *c, double s)
{
	c->pany = efmod(c->pany + 50.0, 360.0);
	c->x3d -= s * (cospc(c->pany) - sinpc(c->pany));
	c->z3d += s * (sinpc(c->pany) + cospc(c->pany));
	c->pany = efmod(c->pany - 50.0, 360.0);
}

void			cam_move_lateral(t_camera *c, double s)
{
	c->pany = efmod(c->pany + 50.0 - 90.0, 360.0);
	c->x3d -= s * (cospc(c->pany) - sinpc(c->pany));
	c->z3d += s * (sinpc(c->pany) + cospc(c->pany));
	c->pany = efmod(c->pany - 50.0 + 90.0, 360.0);
}

void			set_cam_rot(t_camera *c, double x, double y, double z)
{
	c->panx = efmod(x, 360.0);
	c->pany = efmod(y, 360.0);
	c->panz = efmod(z, 360.0);
}

void			set_cam_pos(t_camera *c, double x, double y, double z)
{
	c->x3d = x;
	c->y3d = y;
	c->z3d = z;
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
	cam->s = 0.5;
	return (cam);
}
