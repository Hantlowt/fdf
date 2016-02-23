/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 13:34:49 by alhote            #+#    #+#             */
/*   Updated: 2016/02/23 19:41:14 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

double		cosfd(double v)
{
	return (cosf(v * 2 * 3.14159265359 / 360));
}

double		sinfd(double v)
{
	return (sinf(v * 2 * 3.14159265359 / 360));
}

double		cospc(double v)
{
	static double	*table;
	int				i;

	if (!table)
	{
		i = -1;
		table = (double*)malloc(sizeof(double) * (360));
		while (++i < 360)
			table[i] = cosf(i * 2 * 3.14159265359 / 360);
	}
	return (table[(int)v % 360]);
}

double		sinpc(double v)
{
	static double	*table;
	int				i;

	if (!table)
	{
		i = -1;
		table = (double*)malloc(sizeof(double) * (360));
		while (++i < 360)
			table[i] = sinf(i * 2 * 3.14159265359 / 360);
	}
	return (table[(int)v % 360]);
}

double		efmod(double a, double base)
{
	return (a < 0.0 ? fmod(((fmod(a, base)) + base), base) : fmod(a, base));
}
