/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 14:59:38 by alhote            #+#    #+#             */
/*   Updated: 2016/02/19 00:04:45 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void			cam_move_forward(t_camera *cam, double speed)
{
	double	t[3];
	double	pi;

	pi = 3.14159265359;
	t[0] = speed * (cosf(cam->panz * pi / 180) * sinf(cam->panx * pi / 180));
	t[1] = speed * (sinf(cam->panz * pi / 180));
	t[2] = speed * (cosf(cam->panz * pi / 180) * cosf(cam->panx * pi / 180));
	cam->x3d += t[0];
	cam->y3d += t[1];
	cam->z3d += t[2];
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
	cam->vz = 10.0;
	cam->panx = 180.0;
	cam->pany = 0.0;
	cam->panz = 180.0;
	cam->zoom = 90.0;
	return (cam);
}
