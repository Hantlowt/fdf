/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 15:29:34 by alhote            #+#    #+#             */
/*   Updated: 2016/03/04 15:31:34 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

int				rotate(t_world *w, double rx, double ry, double rz)
{
	t_point	*cur;
	double	t[3];

	cur = w->p;
	while (cur)
	{
		cur->x3d -= w->centerx;
		cur->y3d -= w->centery;
		cur->z3d -= w->centerz;
		t[0] = cur->x3d * cospc(rz) - cur->y3d * sinpc(rz);
		t[1] = cur->x3d * sinpc(rz) + cur->y3d * cospc(rz);
		cur->x3d = t[0] + w->centerx;
		cur->y3d = t[1] + w->centery;
		t[2] = cur->z3d * cospc(ry) - cur->x3d * sinpc(ry);
		t[0] = cur->x3d * cospc(ry) + cur->z3d * sinpc(ry);
		cur->z3d = t[2] + w->centerz;
		cur->x3d = t[0] + w->centerx;
		t[1] = cur->y3d * cospc(rx) - cur->z3d * sinpc(rx);
		t[2] = cur->y3d * sinpc(rx) + cur->z3d * cospc(rx);
		cur->y3d = t[1] + w->centery;
		cur->z3d = t[2] + w->centerz;
		cur = cur->prev;
	}
	return (1);
}
