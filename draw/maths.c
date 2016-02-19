/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 13:34:49 by alhote            #+#    #+#             */
/*   Updated: 2016/02/19 14:26:32 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

double	cosfd(double v)
{
	return (cosf(v * 2 * 3.14159265359 / 256));
}

double	sinfd(double v)
{
	return (sinf(v * 2 * 3.14159265359 / 256));
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
			table[i] = cosf(i * 2 * 3.14159265359 / 256);
	}
	return (table[(int)v % 256]);
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
			table[i] = sinf(i * 2 * 3.14159265359 / 256);
	}
	return (table[(int)v % 256]);
}
