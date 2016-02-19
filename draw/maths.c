/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 13:34:49 by alhote            #+#    #+#             */
/*   Updated: 2016/02/19 13:46:18 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

double	cosfd(double v)
{
	return (cosf(v * 3.14159265359 / 180));
}

double	sinfd(double v)
{
	return (sinf(v * 3.14159265359 / 180));
}

double	cospc(double v)
{
	static double	*table;
	int				i;

	if (!table)
	{
		i = -1;
		table = (double*)malloc(sizeof(double) * (256));
		while (++i < 256)
			table[i] = cosfd(i / 256);
	}
	return (table[(int)v / 256]);
}

double	sinpc(double v)
{
	static double	*table;
	int				i;

	if (!table)
	{
		i = -1;
		table = (double*)malloc(sizeof(double) * (256));
		while (++i < 256)
			table[i] = sinfd(i / 256);
	}
	return (table[(int)v / 256]);
}
