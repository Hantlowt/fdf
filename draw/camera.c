/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 14:59:38 by alhote            #+#    #+#             */
/*   Updated: 2016/02/16 15:29:28 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

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
